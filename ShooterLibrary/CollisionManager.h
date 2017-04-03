
#pragma once

namespace ShooterLibrary
{
	typedef void(*OnCollision)(GameObject *pGameObject1, GameObject *pGameObject2);
	
	class CollisionManager
	{

	public:

		CollisionManager() { }
		virtual ~CollisionManager() { }

		virtual void AddCollisionType(const uint32_t type1, const uint32_t type2, OnCollision callback);

		virtual void AddNonCollisionType(const uint32_t type1, const uint32_t type2);

		virtual void CheckCollision(GameObject *pGameObject1, GameObject *pGameObject2);

	private:

		struct NonCollision
		{
			uint32_t Type1;
			uint32_t Type2;
		};

		struct Collision
		{
			uint32_t Type1;
			uint32_t Type2;
			OnCollision Callback;
		};

		std::vector<NonCollision> m_nonCollisions;
		std::vector<NonCollision>::iterator m_nonCollisionIt;

		std::vector<Collision> m_collisions;
		std::vector<Collision>::iterator m_collisionIt;

	};
}
