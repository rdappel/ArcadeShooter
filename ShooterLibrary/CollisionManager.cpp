
#include "ShooterLibrary.h"

namespace ShooterLibrary
{
	void CollisionManager::AddCollisionType(const uint32_t type1, const uint32_t type2, OnCollision callback)
	{
		Collision c;
		c.Type1 = type1;
		c.Type2 = type2;
		c.Callback = callback;

		m_collisions.push_back(c);
	}
	
	void CollisionManager::CheckCollision(GameObject *pGameObject1, GameObject *pGameObject2)
	{
		uint32_t t1 = pGameObject1->GetCollisionMask();
		uint32_t t2 = pGameObject2->GetCollisionMask();

		static int idx = 0;

		if (t1 == NONE || t2 == NONE || t1 == t2) return;

		m_nonCollisionIt = m_nonCollisions.begin();
		for (; m_nonCollisionIt != m_nonCollisions.end(); m_nonCollisionIt++)
		{
			NonCollision nc = *m_nonCollisionIt;
			if ((nc.Type1 == t1 && nc.Type2 == t2) || (nc.Type1 == t2 && nc.Type2 == t1)) return;
		}

		m_collisionIt = m_collisions.begin();
		for (; m_collisionIt != m_collisions.end(); m_collisionIt++)
		{
			Collision c = *m_collisionIt;
			if ((c.Type1 == t1 && c.Type2 == t2) || (c.Type1 == t2 && c.Type2 == t1))
			{
				Vector2 difference = pGameObject1->GetPosition() - pGameObject2->GetPosition();

				float radiiSum = pGameObject1->GetCollisionRadius() + pGameObject2->GetCollisionRadius();
				float radiiSumSquared = radiiSum * radiiSum;

				if (difference.LengthSquared() <= radiiSumSquared)
				{
					c.Callback(pGameObject1, pGameObject2);
				}
				return;
			}
		}
		
		AddNonCollisionType(t1, t2);
	}

	void CollisionManager::AddNonCollisionType(const uint32_t type1, const uint32_t type2)
	{
		NonCollision nc;
		nc.Type1 = type1;
		nc.Type2 = type2;
		m_nonCollisions.push_back(nc);
	}
}
