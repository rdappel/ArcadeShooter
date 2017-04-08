
#pragma once

namespace ShooterLibrary
{
	/** @brief Callback function for handling collisions.
		@see CollisionManager */
	typedef void(*OnCollision)(GameObject *pGameObject1, GameObject *pGameObject2);
	

	/** @brief Handles collisions between game objects.
	
		At the beginning of gameplay, collision types should be added to the manager via 
		CollisionManager::AddCollisionType(). Througout gameplay the Level will make calls to 
		CollisionManager::CheckCollision(), to see if specific game objects are colliding. If
		a collision is detected, the callback parameter that was specified (when the collision
		type was added) will be called.	*/
	class CollisionManager
	{

	public:

		virtual ~CollisionManager() { }


		/** @brief Adds a type of collision occurance to the manager.
			@param type1 The collision mask type of the first object. 
			@param type2 The collision mask type of the second object.
			@param callback The callback function that should run when the specified object types collide. */
		virtual void AddCollisionType(const uint32_t type1, const uint32_t type2, OnCollision callback);

		/** @brief Adds a type of collision occurance to make the manager ignore.
			@param type1 The collision mask type of the first object.
			@param type2 The collision mask type of the second object.
			@remark This function is used as an optimization for objects that commonly collide and don't
			have any affect on gameplay. For example, a player ship that colldes with a projectile that was
			shot by a player. */
		virtual void AddNonCollisionType(const uint32_t type1, const uint32_t type2);

		/** @brief Checks to see if two objects are colliding. If they are the specified callback function
			is run.
			@param pGameObject1 The first GameObject. 
			@param pGameObject2 The second GameObject.
			@remark This should not be called manually, instead it is called by the level during Level::Update()
			@see Level::Update() */
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
