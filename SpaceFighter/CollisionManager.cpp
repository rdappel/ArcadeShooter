
#include "CollisionManager.h"


void CollisionManager::AddCollisionType(const CollisionType type1, const CollisionType type2, OnCollision callback)
{
	Collision c;
	c.Type1 = (type1 < type2) ? type1 : type2;
	c.Type2 = (type1 > type2) ? type1 : type2;
	c.Callback = callback;

	m_collisions.push_back(c);
}

void CollisionManager::CheckCollision(GameObject *pGameObject1, GameObject *pGameObject2)
{
	CollisionType t1 = pGameObject1->GetCollisionType();
	CollisionType t2 = pGameObject2->GetCollisionType();

	if (t1 == t2 || t1 == CollisionType::NONE || t2 == CollisionType::NONE) return;

	bool swapped = false;
	if (t1 > t2)
	{
		std::swap(t1, t2);
		swapped = true;
	}

	m_nonCollisionIt = m_nonCollisions.begin();
	for (; m_nonCollisionIt != m_nonCollisions.end(); m_nonCollisionIt++)
	{
		NonCollision nc = *m_nonCollisionIt;
		if ((nc.Type1 == t1 && nc.Type2 == t2)) return;
	}

	m_collisionIt = m_collisions.begin();
	for (; m_collisionIt != m_collisions.end(); m_collisionIt++)
	{
		Collision c = *m_collisionIt;
		if ((c.Type1 == t1 && c.Type2 == t2))
		{
			Vector2 difference = pGameObject1->GetPosition() - pGameObject2->GetPosition();

			float radiiSum = pGameObject1->GetCollisionRadius() + pGameObject2->GetCollisionRadius();
			float radiiSumSquared = radiiSum * radiiSum;

			if (difference.LengthSquared() <= radiiSumSquared)
			{
				if (!swapped) c.Callback(pGameObject1, pGameObject2);
				else c.Callback(pGameObject2, pGameObject1);
			}
			return;
		}
	}

	AddNonCollisionType(t1, t2);
}

void CollisionManager::AddNonCollisionType(const CollisionType type1, const CollisionType type2)
{
	NonCollision nc;
	nc.Type1 = (type1 < type2) ? type1 : type2;
	nc.Type2 = (type1 > type2) ? type1 : type2;
	m_nonCollisions.push_back(nc);
}