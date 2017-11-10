
#pragma once

#include "GameObject.h"

typedef void(*OnCollision)(GameObject *pGameObject1, GameObject *pGameObject2);


class CollisionManager
{

public:

	virtual ~CollisionManager() { }

	virtual void AddCollisionType(const CollisionType type1, const CollisionType type2, OnCollision callback);

	virtual void AddNonCollisionType(const CollisionType type1, const CollisionType type2);

	virtual void CheckCollision(GameObject *pGameObject1, GameObject *pGameObject2);


private:

	struct NonCollision
	{
		CollisionType Type1;
		CollisionType Type2;
	};

	struct Collision
	{
		CollisionType Type1;
		CollisionType Type2;
		OnCollision Callback;
	};

	std::vector<NonCollision> m_nonCollisions;
	std::vector<NonCollision>::iterator m_nonCollisionIt;

	std::vector<Collision> m_collisions;
	std::vector<Collision>::iterator m_collisionIt;

};