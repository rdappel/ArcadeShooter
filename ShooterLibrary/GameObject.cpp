
#include "ShooterLibrary.h"

int GameObject::s_count = 0;
Level *GameObject::s_pCurrentLevel = nullptr;

GameObject::GameObject()
{
	m_index = s_count;
	s_count++;

	m_isActive = false;
	m_collisionRadius = 0;
}

bool GameObject::AreObjectsColliding(GameObject *pObject1, GameObject *pObject2, CollisionInstructions *pIns1, CollisionInstructions *pIns2)
{
	CollisionMask mask1 = pObject1->GetCollisionMask();
	CollisionMask mask2 = pObject2->GetCollisionMask();

	if (mask1 == CollisionMask::NONE || mask2 == CollisionMask::NONE) return false;
	if (mask1 == mask2) return false;

	int mask = (int)mask1 | (int)mask2;
	bool match = false;
	CheckCollisionMask(mask, match, CollisionMask::PLAYER_SHIP, CollisionMask::ENEMY_SHIP);
	CheckCollisionMask(mask, match, CollisionMask::PLAYER_SHIP, CollisionMask::ENEMY_PROJECTILE);
	CheckCollisionMask(mask, match, CollisionMask::PLAYER_SHIP, CollisionMask::POWER_UP);
	CheckCollisionMask(mask, match, CollisionMask::PLAYER_PROJECTILE, CollisionMask::ENEMY_SHIP);


	//match |= ((mask & ((int)CollisionMask::PLAYER_SHIP | (int)CollisionMask::ENEMY_SHIP)) > 0);
	//match |= ((mask & ((int)CollisionMask::PLAYER_SHIP | (int)CollisionMask::ENEMY_PROJECTILE)) > 0);
	//match |= ((mask & ((int)CollisionMask::PLAYER_SHIP | (int)CollisionMask::POWER_UP)) > 0);
	//match |= ((mask & ((int)CollisionMask::PLAYER_PROJECTILE | (int)CollisionMask::ENEMY_SHIP)) > 0);

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

			if (mask & (int)CollisionMask::PLAYER_SHIP)
			{
				pPlayerShip = static_cast<PlayerShip *>(pObject2);
				if (mask & (int)CollisionMask::ENEMY_SHIP)
				{
					pIns2->removeObject = true;
					return true;
				}
			}
			else if (mask & (int)CollisionMask::ENEMY_SHIP)
			{
				pEnemyShip = static_cast<EnemyShip *>(pObject1);
				if (mask & (int)CollisionMask::PLAYER_PROJECTILE)
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

void GameObject::Update(const GameTime *pGameTime)
{
	if (IsActive() && s_pCurrentLevel)
	{
		s_pCurrentLevel->UpdateSectorPosition(this);
	}
}

void GameObject::ResetInstructions(CollisionInstructions *pInstructions)
{
	pInstructions->damageToObject = 0.0f;
	pInstructions->removeObject = false;
}

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

void GameObject::CheckCollisionMask(const int mask, bool &match,
	const CollisionMask mask1, const CollisionMask mask2)
{
	match |= ((mask & ((int)mask1 | (int)mask2)) > 0);
}