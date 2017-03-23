
#include "ShooterLibrary.h"

int GameObject::s_count = 0;

GameObject::GameObject()
{
	m_index = s_count;
	s_count++;

	m_isActive = false;
	m_collisionRadius = 0;
}

bool GameObject::AreObjectsColliding(GameObject *pObject1, GameObject *pObject2, CollisionInstructions *pIns1, CollisionInstructions *pIns2)
{
	int mask1 = pObject1->GetCollisionMask();
	int mask2 = pObject2->GetCollisionMask();

	if (mask1 == COLLISION_NONE || mask2 == COLLISION_NONE) return false;
	if (mask1 == mask2) return false;

	int mask = mask1 | mask2;
	bool match = false;
	match |= ((mask & (COLLISION_PLAYERSHIP | COLLISION_ENEMYSHIP)) > 0);
	match |= ((mask & (COLLISION_PLAYERSHIP | COLLISION_ENEMYPROJECTILE)) > 0);
	match |= ((mask & (COLLISION_PLAYERSHIP | COLLISION_POWERUP)) > 0);
	match |= ((mask & (COLLISION_PLAYERPROJECTILE | COLLISION_ENEMYSHIP)) > 0);

	if (match)
	{
		// Math
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

			if (mask & COLLISION_PLAYERSHIP)
			{
				pPlayerShip = static_cast<PlayerShip *>(pObject2);
				if (mask & COLLISION_ENEMYSHIP)
				{
					pIns2->removeObject = true;
					pIns2->spawnsExplosion = true;
					return true;
				}
			}
			else if (mask & COLLISION_ENEMYSHIP)
			{
				pEnemyShip = static_cast<EnemyShip *>(pObject1);
				if (mask & COLLISION_PLAYERPROJECTILE)
				{
					pProjectile = dynamic_cast<Projectile *>(pObject2);
					pIns1->damageToObject = pProjectile->GetDamage();
					pIns1->spawnsExplosion = true;
					pIns2->removeObject = true;
					pIns2->spawnsExplosion = (mask & COLLISION_MISSILE);
					return true;
				}
			}
		}
	}

	return false;
}

void GameObject::Update(const GameTime *pGameTime)
{
	if (IsActive() && Level::GetCurrentLevel())
	{
		Level::GetCurrentLevel()->UpdateSectorPosition(this);
	}
}

void GameObject::ResetInstructions(CollisionInstructions *pInstructions)
{
	pInstructions->damageToObject = 0.0f;
	pInstructions->removeObject = false;
	pInstructions->spawnsExplosion = false;
}