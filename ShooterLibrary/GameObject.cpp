
#include "ShooterLibrary.h"

namespace ShooterLibrary
{
	int GameObject::s_count = 0;
	Level *GameObject::s_pCurrentLevel = nullptr;

	GameObject::GameObject()
	{
		m_index = s_count;
		s_count++;

		m_isActive = false;
		m_collisionRadius = 0;
	}

	/**
	bool GameObject::AreObjectsColliding(GameObject *pObject1, GameObject *pObject2, CollisionInstructions *pIns1, CollisionInstructions *pIns2)
	{
		CollisionMask mask1 = pObject1->GetCollisionMask();
		CollisionMask mask2 = pObject2->GetCollisionMask();

		if (mask1 == CollisionMask::NONE || mask2 == CollisionMask::NONE) return false;
		if (mask1 == mask2) return false;

		int mask = (int)mask1 | (int)mask2;
		bool match = false;

		static const int playerShip = PLAYER | SHIP;
		static const int enemyShip = ENEMY | SHIP;
		static const int playerProjectile = PLAYER | PROJECTILE;

		match |= CheckCollisionMask(mask, playerShip, enemyShip);
		match |= CheckCollisionMask(mask, playerShip, enemyProjectile);
		match |= CheckCollisionMask(mask, playerProjectile, enemyShip);
		match |= CheckCollisionMask(mask, playerShip, CollisionMask::POWER_UP);

		if (match)
		{
			Vector2 difference = pObject1->m_position - pObject2->m_position;

			float radiiSum = pObject1->m_collisionRadius + pObject2->m_collisionRadius;
			float radiiSumSquared = radiiSum * radiiSum;

			bool colliding = (difference.DistanceSquared() <= radiiSumSquared);

			if (colliding)
			{
				PlayerShip *pPlayerShip;
				EnemyShip *pEnemyShip;
				Projectile *pProjectile;

				ResetInstructions(pIns1);
				ResetInstructions(pIns2);

				if (mask & (int)playerShip)
				{
					pPlayerShip = static_cast<PlayerShip *>(pObject2);
					if (mask & (int)enemyShip)
					{
						pIns2->removeObject = true;
						return true;
					}
				}
				else if (mask & (int)enemyShip)
				{
					pEnemyShip = static_cast<EnemyShip *>(pObject1);
					if (mask & (int)playerProjectile)
					{
						pProjectile = dynamic_cast<Projectile *>(pObject2);
						pIns1->damageToObject = pProjectile->GetDamage();
						pIns2->removeObject = true;
						return true;
					}
				}
			}
		}

		return false;
	}
	*/

	void GameObject::Update(const GameTime *pGameTime)
	{
		if (IsActive() && s_pCurrentLevel)
		{
			s_pCurrentLevel->UpdateSectorPosition(this);
		}
	}

	Vector2 GameObject::GetHalfDimensions() const
	{
		return Vector2(m_collisionRadius, m_collisionRadius);
	}

	/**
	void GameObject::ResetInstructions(CollisionInstructions *pInstructions)
	{
		pInstructions->damageToObject = 0.0f;
		pInstructions->removeObject = false;
	}
	/**/

	void GameObject::SetPosition(const float x, const float y)
	{
		m_previousPosition = m_position;
		m_position.Set(x, y);
	}

	void GameObject::SetPosition(const Vector2 &position)
	{
		SetPosition(position.X, position.Y);
	}

	void GameObject::TranslatePosition(const float x, const float y)
	{
		SetPosition(m_position.X + x, m_position.Y + y);
	}

	void GameObject::TranslatePosition(const Vector2 &offset)
	{
		TranslatePosition(offset.X, offset.Y);
	}
}