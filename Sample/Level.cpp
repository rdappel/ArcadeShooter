
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
	// Collision Callbacks
	void PlayerShootsEnemy(GameObject *pObject1, GameObject *pObject2)
	{
		bool m = pObject1->HasMask(COLLISIONTYPE_ENEMY);
		EnemyShip *pEnemyShip = static_cast<EnemyShip *>((m) ? pObject1 : pObject2);
		Projectile *pPlayerProjectile = static_cast<Projectile *>((!m) ? pObject1 : pObject2);
		
		pEnemyShip->Hit(pPlayerProjectile->GetDamage());
		pPlayerProjectile->Deactivate();
	}

	void PlayerCollectsPowerUp(GameObject *pObject1, GameObject *pObject2)
	{
		bool m = pObject1->HasMask(COLLISIONTYPE_POWERUP);
		PowerUp *pPowerUp = static_cast<PowerUp *>((m) ? pObject1 : pObject2);
		PlayerShip *pPlayerShip = static_cast<PlayerShip *>((!m) ? pObject1 : pObject2);
		pPowerUp->Deactivate();
		pPlayerShip->PowerUp();
	}

	void PlayerCollidesWithEnemy(GameObject *pObject1, GameObject *pObject2)
	{
		bool m = pObject1->HasMask(COLLISIONTYPE_PLAYER);
		PlayerShip *pPlayerShip = static_cast<PlayerShip *>((m) ? pObject1 : pObject2);
		pPlayerShip->Hit(1000);
	}


	Level::Level()
	{
		m_pPlayerShip = new	PlayerShip();
	}

	void Level::LoadContent()
	{
		ResourceManager *pRes = GetResourceManager();

		Texture *pTexture = pRes->Load<Texture>("Textures\\PlayerShip.png");
		m_pPlayerShip->SetTexture(pTexture);
		m_pPlayerShip->SetLevel(this);

		Animation *pAnimation = pRes->Load<Animation>("Animations\\Thruster.anim");
		if (pAnimation)
		{
			pAnimation->SetTexture(pRes->Load<Texture>("Textures\\Thruster_01.png"));
			if (pAnimation->GetTexture())
			{
				m_pPlayerShip->SetThrusterAnimation(pAnimation);
				pAnimation->Play();
			}
		}
		
		// weapons
		ProjectilePool *pPool;
		pPool = new ProjectilePool(this);
		AddProjectilePool(pPool);
		Launcher *pLauncher;
		Blaster *pBlaster;
		Missile *pMissile;

		for (int i = 0; i < 100; i++) pPool->Add(new Projectile());

		pBlaster = new Blaster(true);
		pBlaster->SetProjectilePool(pPool);
		m_pPlayerShip->AttachWeapon(pBlaster, Vector2::UnitY * -32);

		pPool = new ProjectilePool(this);
		AddProjectilePool(pPool);
		for (int i = 0; i < 100; i++)
		{
			pMissile = new Missile();
			pMissile->SetAnimation(pRes->Load<Animation>("Animations\\Missile_01.anim"));
			pPool->Add(pMissile);
		}

		pLauncher = new Launcher(false);
		pLauncher->SetProjectilePool(pPool);
		m_pPlayerShip->AttachWeapon(pLauncher, Vector2::UnitX * -22);

		pLauncher = new Launcher(false);
		pLauncher->SetProjectilePool(pPool);
		m_pPlayerShip->AttachWeapon(pLauncher, Vector2::UnitX * 22);


		ShooterLibrary::Level::LoadContent();

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

	void Level::AddGameObject(GameObject *pGameObject)
	{
		ShooterLibrary::Level::AddGameObject(pGameObject);
	}

	void Level::SpawnPowerUp(const Vector2 position)
	{
		PowerUp *pPowerUp = new	PowerUp();
		pPowerUp->Activate(position, this);
		AddGameObject(pPowerUp);
	}
}