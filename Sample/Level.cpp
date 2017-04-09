
#include "Sample.h"

using ShooterLibrary::Projectile;
using ShooterLibrary::EnemyShip;
using ShooterLibrary::GameObject;
using ShooterLibrary::CollisionManager;
using ShooterLibrary::TriggerType;
using ShooterLibrary::Weapon;
using ShooterLibrary::Gun;

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
		//pPlayerShip->PowerUp();
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

		ProjectilePool *pPool;
		Weapon *pWeapon;
		
		pPool = new ProjectilePool(this);
		m_pProjectilePools.push_back(pPool);
		pWeapon = new Gun<Projectile>(true);
		pWeapon->SetProjectilePool(pPool);
		m_pPlayerShip->AttachWeapon(pWeapon, Vector2::UnitY * -32);

		pPool = new ProjectilePool(this);
		m_pProjectilePools.push_back(pPool);
		pWeapon = new Gun<Projectile>(true);
		pWeapon->SetProjectilePool(pPool);
		pWeapon->SetFireType(TriggerType::TRIGGERTYPE_SECONDARY);
		m_pPlayerShip->AttachWeapon(pWeapon, Vector2::UnitX * -32);

	}

	void Level::LoadContent()
	{
		Texture *pTexture = GetResourceManager()->Load<Texture>("Textures\\PlayerShip.png");
		m_pPlayerShip->SetTexture(pTexture);
		m_pPlayerShip->SetLevel(this);

		Animation *pAnimation = GetResourceManager()->Load<Animation>("Animations\\Thruster.anim");
		if (pAnimation)
		{
			pAnimation->SetTexture(GetResourceManager()->Load<Texture>("Textures\\Thruster_01.png"));
			if (pAnimation->GetTexture())
			{
				m_pPlayerShip->SetThrusterAnimation(pAnimation);
				pAnimation->Play();
			}
		}

		m_pProjectilePools[0]->Fill<Projectile>(100);
		m_pProjectilePools[1]->Fill<Projectile>(100);
		
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