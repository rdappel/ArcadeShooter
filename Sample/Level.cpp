
/*   .oooooo..o       .o.       ooo        ooooo ooooooooo.   ooooo        oooooooooooo
	d8P'    `Y8      .888.      `88.       .888' `888   `Y88. `888'        `888'     `8
	Y88bo.          .8"888.      888b     d'888   888   .d88'  888          888
	 `"Y8888o.     .8' `888.     8 Y88. .P  888   888ooo88P'   888          888oooo8
		 `"Y88b   .88ooo8888.    8  `888'   888   888          888          888    "
	oo     .d8P  .8'     `888.   8    Y     888   888          888       o  888       o
	8""88888P'  o88o     o8888o o8o        o888o o888o        o888ooooood8 o888ooooood8

				     	   Sample © 2017 - Shuriken Studios LLC                          */

#include "Sample.h"

using namespace ShooterLibrary;

namespace Sample
{

	/** @brief Callback function for when a player projectile hits
		an enemy.
		@param pObject1 The first game object in the collision. 
		@param pObject2 The second game object in the collision. */
	void PlayerShootsEnemy(GameObject *pObject1, GameObject *pObject2)
	{
		bool m = pObject1->HasMask(COLLISIONTYPE_ENEMY);
		EnemyShip *pEnemyShip = static_cast<EnemyShip *>((m) ? pObject1 : pObject2);
		Projectile *pPlayerProjectile = static_cast<Projectile *>((!m) ? pObject1 : pObject2);
		pEnemyShip->Hit(pPlayerProjectile->GetDamage());
		pPlayerProjectile->Deactivate();
	}

	/** @brief Callback function for when a player collects a power up.
		@param pObject1 The first game object in the collision.
		@param pObject2 The second game object in the collision. */
	void PlayerCollectsPowerUp(GameObject *pObject1, GameObject *pObject2)
	{
		bool m = pObject1->HasMask(COLLISIONTYPE_POWERUP);
		PowerUp *pPowerUp = static_cast<PowerUp *>((m) ? pObject1 : pObject2);
		PlayerShip *pPlayerShip = static_cast<PlayerShip *>((!m) ? pObject1 : pObject2);
		pPowerUp->Deactivate();
		pPlayerShip->PowerUp();
	}

	/** @brief Callback function for when a player collides with an enemy.
		@param pObject1 The first game object in the collision.
		@param pObject2 The second game object in the collision. */
	void PlayerCollidesWithEnemy(GameObject *pObject1, GameObject *pObject2)
	{
		bool m = pObject1->HasMask(COLLISIONTYPE_PLAYER);
		PlayerShip *pPlayerShip = static_cast<PlayerShip *>((m) ? pObject1 : pObject2);
		EnemyShip *pEnemyShip = static_cast<EnemyShip *>((!m) ? pObject1 : pObject2);
		pPlayerShip->Hit(std::numeric_limits<float>::max());
		pEnemyShip->Hit(std::numeric_limits<float>::max());
	}


	Level::Level(GameplayScreen *pGameplayScreen)
	{
		m_pGameplayScreen = pGameplayScreen;
		m_isOver = false;

		SetBackground(new Background());
	}

	void Level::LoadContent(ResourceManager *pResourceManager)
	{
		// TODO: Move this into some sort of factory function.
		PlayerShip *pPlayerShip = new PlayerShip();
		Texture *pTexture = pResourceManager->Load<Texture>("Textures\\PlayerShip.png");
		pPlayerShip->SetTexture(pTexture);
		Animation *pAnimation = pResourceManager->Load<Animation>("Animations\\Thruster.anim");
		if (pAnimation)
		{
			pAnimation->SetTexture(pResourceManager->Load<Texture>("Textures\\Thruster_01.png"));
			if (pAnimation->GetTexture())
			{
				pPlayerShip->SetThrusterAnimation(pAnimation);
				pAnimation->Play();
			}
		}
		
		ProjectilePool *pPool;
		pPool = new ProjectilePool(this);
		AddProjectilePool(pPool);
		Launcher *pLauncher;
		Blaster *pBlaster;
		Missile *pMissile;

		for (int i = 0; i < 100; i++) pPool->Add(new Projectile());

		pBlaster = new Blaster(true);
		pBlaster->SetProjectilePool(pPool);
		pPlayerShip->AttachWeapon(pBlaster, Vector2::UnitY * -32);

		SmokeTemplate<RotatingParticle> *pTemplate = new SmokeTemplate<RotatingParticle>();
		pTemplate->SetTexture(pResourceManager->Load<Texture>("Textures\\Particle.png"));


		pPool = new ProjectilePool(this);
		AddProjectilePool(pPool);
		for (int i = 0; i < 100; i++)
		{
			pMissile = new Missile();
			pMissile->SetEmitter(new Emitter(GetParticleManager(), pTemplate, 100));
			pMissile->SetAnimation(pResourceManager->Load<Animation>("Animations\\Missile_01.anim"));
			pPool->Add(pMissile);
		}

		pLauncher = new Launcher(false);
		pLauncher->SetProjectilePool(pPool);
		pPlayerShip->AttachWeapon(pLauncher, Vector2::UnitX * -22);

		pLauncher = new Launcher(false);
		pLauncher->SetProjectilePool(pPool);
		pPlayerShip->AttachWeapon(pLauncher, Vector2::UnitX * 22);

		AddPlayerShip(pPlayerShip);
		// end todo

		for (int i = 0; i < 20; i++)
		{
			Explosion *pExplosion = new Explosion();
			pExplosion->SetAnimation(pResourceManager->Load<Animation>("Animations\\Explosion.anim"));
			m_explosions.push_back(pExplosion);
		}

		ShooterLibrary::Level::LoadContent(pResourceManager);

		CollisionManager *pC = GetCollisionManager();

		uint32_t playerShip = (COLLISIONTYPE_PLAYER | COLLISIONTYPE_SHIP);
		uint32_t playerProjectile = (COLLISIONTYPE_PLAYER | COLLISIONTYPE_PROJECTILE);
		uint32_t enemyShip = (COLLISIONTYPE_ENEMY | COLLISIONTYPE_SHIP);
		uint32_t powerUp = (COLLISIONTYPE_POWERUP);

		pC->AddNonCollisionType(playerShip, playerProjectile);
		pC->AddCollisionType(playerProjectile, enemyShip, PlayerShootsEnemy);
		pC->AddCollisionType(playerShip, powerUp, PlayerCollectsPowerUp);
		pC->AddCollisionType(playerShip, enemyShip, PlayerCollidesWithEnemy);
	}

	
	void Level::HandleInput(const InputState *pInput)
	{
		m_playerShipIt = m_playerShips.begin();
		for (; m_playerShipIt != m_playerShips.end(); m_playerShipIt++)
		{
			(*m_playerShipIt)->HandleInput(pInput);
		}
	}

	void Level::Update(const GameTime *pGameTime)
	{
		if (!m_isOver)
		{
			bool isOver = true;

			m_playerShipIt = m_playerShips.begin();
			for (; m_playerShipIt != m_playerShips.end(); m_playerShipIt++)
			{
				if ((*m_playerShipIt)->IsActive())
				{
					isOver = false;
					break;
				}
			}

			if (isOver)
			{
				m_isOver = true;
				GetScreenManager()->AddScreen(new LevelOverScreen(m_pGameplayScreen, false));
			}
		}
		else
		{

		}

		m_explosionIt = m_explosions.begin();
		for (; m_explosionIt != m_explosions.end(); m_explosionIt++)
		{
			(*m_explosionIt)->Update(pGameTime);
		}

		ShooterLibrary::Level::Update(pGameTime);
	}

	void Level::Draw(SpriteBatch *pSpriteBatch)
	{

		pSpriteBatch->Begin(SpriteSortMode::BACK_TO_FRONT);
		ShooterLibrary::Level::Draw(pSpriteBatch);
		pSpriteBatch->End();
		
		pSpriteBatch->Begin(SpriteSortMode::BACK_TO_FRONT, BlendState::ADDITIVE);
		m_explosionIt = m_explosions.begin();
		for (; m_explosionIt != m_explosions.end(); m_explosionIt++)
		{
			(*m_explosionIt)->Draw(pSpriteBatch);
		}
		pSpriteBatch->End();
	}

	void Level::AddPlayerShip(PlayerShip *pPlayerShip)
	{
		AddGameObject(pPlayerShip);
		m_playerShips.push_back(pPlayerShip);
		pPlayerShip->SetLevel(this);
		pPlayerShip->SetAITarget(pPlayerShip->GetPosition() - Vector2::UnitY * 300);
	}

	
	void Level::SpawnPowerUp(const Vector2 position)
	{
		PowerUp *pPowerUp = new	PowerUp();
		pPowerUp->Activate(position, this);
		AddGameObject(pPowerUp);
	}

	
	void Level::SpawnExplosion(const Vector2 position, const float scale)
	{
		m_explosionIt = m_explosions.begin();
		for (; m_explosionIt != m_explosions.end(); m_explosionIt++)
		{
			Explosion *pExplosion = *m_explosionIt;
			if (!pExplosion->IsActive())
			{
				pExplosion->Activate(position, scale);
				break;
			}
		}
	}

	void Level::Complete()
	{
		if (!m_isOver)
		{
			m_isOver = true;
			GetScreenManager()->AddScreen(new LevelOverScreen(m_pGameplayScreen, true));
		}
	}
	
	ParticleManager *Level::GetParticleManager() const 
	{
		return m_pGameplayScreen->GetParticleManager(); 
	}


	ScreenManager *Level::GetScreenManager() const
	{
		return m_pGameplayScreen->GetScreenManager();
	}
}