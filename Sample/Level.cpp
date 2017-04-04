
#include "Sample.h"

using ShooterLibrary::Projectile;
using ShooterLibrary::EnemyShip;
using ShooterLibrary::GameObject;
using ShooterLibrary::CollisionManager;

namespace Sample
{
	// Collision Callbacks
	void PlayerShootsEnemy(GameObject *pGameObject1, GameObject *pGameObject2)
	{
		Projectile *pProjectile = Projectile::Resolve(pGameObject1, pGameObject2);
		EnemyShip *pEnemyShip = EnemyShip::Resolve(pGameObject1, pGameObject2);
		pEnemyShip->Hit(pProjectile->GetDamage());
		pProjectile->Deactivate();
	}

	void PlayerCollectsPowerUp(GameObject *pGameObject1, GameObject *pGameObject2)
	{
		PowerUp *pPowerUp = PowerUp::Resolve(pGameObject1, pGameObject2);
		PlayerShip *pPlayerShip = PlayerShip::Resolve(pGameObject1, pGameObject2);
		pPowerUp->Deactivate();
		pPlayerShip->IncreaseFireRate();
	}

	void PlayerCollidesWithEnemy(GameObject *pGameObject1, GameObject *pGameObject2)
	{
		PlayerShip *pPlayerShip = PlayerShip::Resolve(pGameObject1, pGameObject2);
		pPlayerShip->Hit(1000);
	}


	Level::Level()
	{
		m_pPlayerShip = new	PlayerShip();
	}

	void Level::LoadContent()
	{
		Texture *pTexture = GetResourceManager()->Load<Texture>("Textures\\PlayerShip.png");
		m_pPlayerShip->SetTexture(pTexture);

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

		for (int i = 0; i < 60; i++)
		{
			Projectile *pProjectile = new Projectile();
			m_projectiles.push_back(pProjectile);
			AddGameObject(pProjectile);
		}

		ShooterLibrary::Level::LoadContent();

		InitializeCollisionManager();

		CollisionManager *pC = GetCollisionManager();
		pC->AddNonCollisionType((PLAYER | SHIP), (PLAYER | PROJECTILE));
		pC->AddCollisionType((PLAYER | PROJECTILE), (ENEMY | SHIP), PlayerShootsEnemy);
		pC->AddCollisionType((PLAYER | SHIP), (POWER_UP), PlayerCollectsPowerUp);
		pC->AddCollisionType((PLAYER | SHIP), (ENEMY | SHIP), PlayerCollidesWithEnemy);

		m_pPlayerShip->SetLevel(this);
	}

	void Level::AddGameObject(GameObject *pGameObject)
	{
		ShooterLibrary::Level::AddGameObject(pGameObject);
	}

	Projectile *Level::GetInactiveProjectile()
	{
		m_projectileIt = m_projectiles.begin();
		for (; m_projectileIt != m_projectiles.end(); m_projectileIt++)
		{
			if (!(*m_projectileIt)->IsActive()) return *m_projectileIt;
		}

		return nullptr;
	}

	void Level::GeneratePowerUp(const Vector2 position)
	{
		PowerUp *pPowerUp = new	PowerUp();
		pPowerUp->Activate(position, this);
		AddGameObject(pPowerUp);
	}
}