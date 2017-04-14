
/*      .                         ,'`.       .                         
   .                  .."    _.-;' ⁄‚ `.              .			`      
              _.-"`.##%"_.--" ,' ⁄`     `.           "#"     ___,,od000
           ,'"-_ _.-.--"\   ,'            `-_       '%#%',,/00000000000
         ,'     |_.'     )`/-     __..--""`-_`-._    J L/00000000000000
 . +   ,'   _.-"        / /   _-""           `-._`-_/___\///0000   000M
     .'_.-""      '    :_/_.-'                 _,`-/__V__\0000    00MMM
 . _-""                         .        '   _,/000\  |  /000    0MMMMM
_-"   .       '     .              .        ,/   000\ | /000000000MMMMM
       `       Shooter Library       '     ,/     000\|/000000000MMMMMM
.       © 2017 - Shuriken Studios LLC     ,/0    00000|0000000000MMMMMM */

#pragma once

namespace ShooterLibrary
{
	class GameObject;

	/** @brief Base class for all shooter levels. */
	class Level
	{

	public:

		Level();
		virtual ~Level();

		/** @brief Called when resources need to be loaded.
			@param pResourceManager The game's resource manager, used for loading
			and managing game resources. */
		virtual void LoadContent(ResourceManager *pResourceManager);

		/** @brief Called when resources need to be unloaded. Override this
			method to unload any game-specific resources. */
		virtual void UnloadContent();

		/** @brief Called when the game has determined that game logic needs
			to be processed.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime);

		/** @brief Called when the game determines it is time to draw a frame.
			@param pSpriteBatch The game's sprite batch, used for rendering. */
		virtual void Draw(SpriteBatch *pSpriteBatch);

		/** @brief Adds a game object so it can be managed by the level.
			@param pGameObject A pointer to the GameObject that will be added
			to the level. */
		virtual void AddGameObject(GameObject *pGameObject) { m_gameObjects.push_back(pGameObject); }

		/** @brief Should be called when the victory conditions are met for the level. */
		virtual void Complete() { }

		/** @brief Updates an object's position on the sector grid.
			@param pGameObject The game object who's position will be updated.
			@remark This should happen automatically as long as a game object's
			Update() calls
			GameObject::Update(). */
		virtual void UpdateSectorPosition(GameObject *pGameObject);

		/** @brief Get the closest active game object of a specific type.
			@param position The position from which to determine the closest object.
			@param range The maximum distance to allow the search to return an object.
			If the range is negative or zero, the diagonal screen size is used.
			@return Returns a game object of the specified type T, or nullptr if a
			matching object was not found. */
		template <typename T>
		T *GetClosestObject(const Vector2 position, const float range)
		{
			float squaredRange = range * range;
			if (range <= 0)
			{
				int w = Game::GetScreenWidth();
				int h = Game::GetScreenHeight();
				squaredRange = w * w + h * h;
			}
			float squaredDistance;

			std::vector<GameObject *>::iterator m_it = m_gameObjects.begin();
			T *pClosest = nullptr;

			for (; m_it != m_gameObjects.end(); m_it++)
			{
				GameObject *pGameObject = *m_it;
				if (!pGameObject->IsActive()) continue;

				squaredDistance = (position - pGameObject->GetPosition()).LengthSquared();
				if (squaredDistance < squaredRange)
				{
					T *pObject = dynamic_cast<T *>(pGameObject);
					if (pObject)
					{
						pClosest = pObject;
						squaredRange = squaredDistance;
					}
				}
			}

			return pClosest;
		}


	protected:

		/** @brief Initailizes the level's default CollisionManager. */
		virtual void InitializeCollisionManager() { m_pCollisionManager = new CollisionManager(); }

		/** @brief Gets the CollisionManager for testing collisions between game objects.
			@return Returns a pointer to the CollisionManager. */
		virtual CollisionManager *GetCollisionManager() { return m_pCollisionManager; }

		/** @brief Gets the ParticleManager for loading the level's resources.
			@return Returns a pointer to the ResourceManager. */
		virtual ParticleManager *GetParticleManager() const = 0;

		/** @brief Adds a pool of projectiles to the level.
			@param pProjectilePool The pool to add. */
		virtual void AddProjectilePool(ProjectilePool *pProjectilePool) { m_pProjectilePools.push_back(pProjectilePool); }

		/** @brief Sets the background object for the level.
			@param pBackground The level's background. */
		virtual void SetBackground(Background *pBackground) { m_pBackground = pBackground; }

	private:

		CollisionManager *m_pCollisionManager = nullptr;;

		std::vector<GameObject *> *m_pSectors;

		Vector2 m_sectorCount;
		Vector2 m_sectorSize;

		unsigned int m_totalSectorCount;

		std::vector<GameObject *> m_gameObjects;
		std::vector<GameObject *>::iterator m_gameObjectIt;

		ALLEGRO_SAMPLE *m_pSample;
		ALLEGRO_SAMPLE_ID m_sampleID;

		std::vector<ProjectilePool *> m_pProjectilePools;
		
		Background *m_pBackground;

		void CheckCollisions(std::vector<GameObject *> &sector);

		virtual Vector2 GetSectorCount() const { return m_sectorCount; }

		virtual Vector2 GetSectorSize() const { return m_sectorSize; }

		virtual unsigned int GetTotalSectorCount() const { return m_totalSectorCount; }

		virtual std::vector<GameObject *> *GetSectors() { return m_pSectors; }
				
	};
}