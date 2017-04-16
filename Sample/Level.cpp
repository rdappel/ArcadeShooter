
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
		bool m = pObject1->HasMask((ShooterLibrary::CollisionType)CollisionType::ENEMY);
		EnemyShip *pEnemyShip = (EnemyShip *)((m) ? pObject1 : pObject2);
		Projectile *pPlayerProjectile = (Projectile *)((!m) ? pObject1 : pObject2);
		pEnemyShip->Hit(pPlayerProjectile->GetDamage());
		pPlayerProjectile->Deactivate();
	}

	/** @brief Callback function for when a player collects a power up.
		@param pObject1 The first game object in the collision.
		@param pObject2 The second game object in the collision. */
	void PlayerCollectsPowerUp(GameObject *pObject1, GameObject *pObject2)
	{
		bool m = pObject1->HasMask((ShooterLibrary::CollisionType)CollisionType::POWERUP);
		PowerUp *pPowerUp = (PowerUp *)((m) ? pObject1 : pObject2);
		PlayerShip *pPlayerShip = (PlayerShip *)((!m) ? pObject1 : pObject2);
		pPowerUp->Deactivate();
		pPlayerShip->PowerUp();
	}

	/** @brief Callback function for when a player collides with an enemy.
		@param pObject1 The first game object in the collision.
		@param pObject2 The second game object in the collision. */
	void PlayerCollidesWithEnemy(GameObject *pObject1, GameObject *pObject2)
	{
		bool m = pObject1->HasMask((ShooterLibrary::CollisionType)CollisionType::PLAYER);
		PlayerShip *pPlayerShip = (PlayerShip *)((m) ? pObject1 : pObject2);
		EnemyShip *pEnemyShip = (EnemyShip *)((!m) ? pObject1 : pObject2);
		pPlayerShip->Hit(std::numeric_limits<float>::max());
		pEnemyShip->Hit(std::numeric_limits<float>::max());
	}


	Level::Level(GameplayScreen *pGameplayScreen)
	{
		m_pGameplayScreen = pGameplayScreen;
		m_isOver = false;

		m_finalCountdownBegan = false;
		m_finalCountdownSeconds = 5;

		SetBackground(new Background());
	}

	void Level::LoadContent(ResourceManager *pResourceManager)
	{
		// smoke particle for missiles
		SmokeTemplate<RotatingParticle> *pTemplate = new SmokeTemplate<RotatingParticle>();
		pTemplate->SetTexture(pResourceManager->Load<Texture>("Textures\\Particle.png"));

		// generate projectile pools
		ProjectilePool *pBlasterPool = new ProjectilePool(this);
		AddProjectilePool(pBlasterPool);
		m_pDrawPools.push_back(pBlasterPool); // render this one separately...

		ProjectilePool *pMissilePool = new ProjectilePool(this);
		AddProjectilePool(pMissilePool);

		// regualar projectiles
		for (int i = 0; i < 100; i++)
		{
			Projectile *pProjectile = new Projectile();
			pProjectile->SetManualDraw(); // ... here too
			pBlasterPool->Add(pProjectile);
		}

		// missiles
		Missile *pMissile;
		for (int i = 0; i < 20; i++)
		{
			pMissile = new Missile();
			pMissile->SetEmitter(new Emitter(GetParticleManager(), pTemplate, 100));
			pMissile->SetAnimation(pResourceManager->Load<Animation>("Animations\\Missile.anim"));
			pMissilePool->Add(pMissile);
		}

		// create player ships
		const int NUM_PLAYERS = 1;
		for (int i = 0; i < NUM_PLAYERS; i++)
		{
			PlayerShip *pPlayerShip = new PlayerShip(i);

			Blaster *pBlaster;

			pBlaster = new Blaster(true);
			pBlaster->SetProjectilePool(pBlasterPool);
			pPlayerShip->AttachWeapon(pBlaster, Vector2::UnitY * -32);

			Launcher *pLauncher;

			pLauncher = new Launcher(false);
			pLauncher->SetProjectilePool(pMissilePool);
			pPlayerShip->AttachWeapon(pLauncher, Vector2::UnitX * -22);

			pLauncher = new Launcher(false);
			pLauncher->SetProjectilePool(pMissilePool);
			pPlayerShip->AttachWeapon(pLauncher, Vector2::UnitX * 22);

			pPlayerShip->LoadContent(pResourceManager);
			AddPlayerShip(pPlayerShip);
		}

		m_playerShipIt = m_playerShips.begin();
		for (; m_playerShipIt != m_playerShips.end(); m_playerShipIt++)
		{
			(*m_playerShipIt)->Initialize(this);
		}

		// create explosions
		for (int i = 0; i < 20; i++)
		{
			Explosion *pExplosion = new Explosion();
			pExplosion->SetAnimation(pResourceManager->Load<Animation>("Animations\\Explosion.anim"));
			m_explosions.push_back(pExplosion);
		}

		ShooterLibrary::Level::LoadContent(pResourceManager);

		// setup collision types
		CollisionManager *pC = GetCollisionManager();

		ShooterLibrary::CollisionType playerShip		= (CollisionType::PLAYER | CollisionType::SHIP);
		ShooterLibrary::CollisionType playerProjectile	= (CollisionType::PLAYER | CollisionType::PROJECTILE);
		ShooterLibrary::CollisionType enemyShip			= (CollisionType::ENEMY | CollisionType::SHIP);
		ShooterLibrary::CollisionType powerUp			= (CollisionType::POWERUP);

		pC->AddNonCollisionType(playerShip, playerProjectile);
		pC->AddCollisionType(playerProjectile, enemyShip, PlayerShootsEnemy);
		pC->AddCollisionType(playerShip, powerUp, PlayerCollectsPowerUp);
		pC->AddCollisionType(playerShip, enemyShip, PlayerCollidesWithEnemy);

		m_levelSeconds = 0;
	}

	
	void Level::HandleInput(const InputState *pInput)
	{
		m_playerShipIt = m_playerShips.begin();
		for (; m_playerShipIt != m_playerShips.end(); m_playerShipIt++)
		{
			(*m_playerShipIt)->HandleInput(pInput);
		}

		if (true && pInput->IsKeyDown(Key::R))
		{
			if (pInput->IsNewMouseButtonPress(MouseButton::LEFT))
			{
				std::cout << m_levelSeconds << ", " << pInput->GetMousePosition().ToString() << std::endl;
			}
			else if (pInput->IsNewMouseButtonPress(MouseButton::RIGHT))
			{
				std::cout << std::endl;
			}
		}
	}

	void Level::Update(const GameTime *pGameTime)
	{
		m_levelSeconds += pGameTime->GetTimeElapsed();

		if (m_finalCountdownBegan && m_finalCountdownSeconds > 0)
		{
			m_finalCountdownSeconds -= pGameTime->GetTimeElapsed();
			if (m_finalCountdownSeconds <= 0) Complete();
		}

		if (!m_isOver)
		{
			// check if players are still alive
			bool isOver = true;
			m_playerShipIt = m_playerShips.begin();
			for (; m_playerShipIt != m_playerShips.end(); m_playerShipIt++)
			{
				if ((*m_playerShipIt)->IsActive())
				{
					// at least one is alive so the game is not over.
					isOver = false; 
					break;
				}
			}

			if (isOver) // all players are dead
			{
				m_isOver = true;
				GetScreenManager()->AddScreen(new LevelOverScreen(m_pGameplayScreen, false));
			}
		}
		else // mission completed successfully
		{
			m_playerShipIt = m_playerShips.begin();
			for (; m_playerShipIt != m_playerShips.end(); m_playerShipIt++)
			{
				PlayerShip *pPlayerShip = (*m_playerShipIt);
				if (pPlayerShip->IsActive())
				{
					Vector2 target = pPlayerShip->GetPosition();
					target.Y = -100;
					pPlayerShip->SetAITarget(target);
				}
			}
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
		ShooterLibrary::Level::Draw(pSpriteBatch);
		
		pSpriteBatch->Begin(SpriteSortMode::DEFERRED, BlendState::ADDITIVE);

		m_explosionIt = m_explosions.begin();
		for (; m_explosionIt != m_explosions.end(); m_explosionIt++)
		{
			(*m_explosionIt)->Draw(pSpriteBatch);
		}

		m_pDrawPoolIt = m_pDrawPools.begin();
		for (; m_pDrawPoolIt != m_pDrawPools.end(); m_pDrawPoolIt++)
		{
			(*m_pDrawPoolIt)->Draw(pSpriteBatch);
		}
		
		pSpriteBatch->End();
	}

	void Level::AddPlayerShip(PlayerShip *pPlayerShip)
	{
		AddGameObject(pPlayerShip);
		m_playerShips.push_back(pPlayerShip);
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