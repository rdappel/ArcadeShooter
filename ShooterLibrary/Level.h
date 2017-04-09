
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

		/** @brief Called when resources need to be loaded. */
		virtual void LoadContent();

		/** @brief Called when resources need to be unloaded. Override this
			method to unload any game-specific resources. */
		virtual void UnloadContent() { }

		/** @brief Called when the game has determined that player input
			needs to be processed.
			@param pInput The current state of all player input devices. */
		virtual void HandleInput(InputState *pInput);

		/** @brief Called when the game has determined that game logic needs
			to be processed.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime);

		/** @brief Called when the game determines it is time to draw a frame.
			@param pGameTime Timing values including time since last update. */
		virtual void Draw(const GameTime *pGameTime);

		/** @brief Adds a GameObject so it can be managed by the level.
			@param pGameObject A pointer to the GameObject that will be added
			to the level. */
		virtual void AddGameObject(GameObject *pGameObject);

		/** @brief Updates an object's position on the sector grid.
			@param pGameObject The game object who's position will be updated.
			@remark This should happen automatically as long as a game object's
			Update() calls
			GameObject::Update(). */
		virtual void UpdateSectorPosition(GameObject *pGameObject);

		/** @brief Gets the player ship.
			@return Returns a pointer to the player ship.
			@todo Change this to allow for multi-player support. */
		virtual PlayerShip *GetPlayerShip() = 0;

		/** @brief Gets the SpriteBatch used to render the level.
			@return Returns a pointer to the level's SpriteBatch. */
		virtual SpriteBatch *GetSpriteBatch() const { return m_pGameplayScreen->GetSpriteBatch(); }

		/** @brief Sets the GameplayScreen instance for the level.
			@param pGameplayscreen A pointer to the GameplayScreen. */
		virtual void SetGameplayScreen(GameplayScreen *pGameplayscreen) { m_pGameplayScreen = pGameplayscreen; }

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

		/** @brief Gets the GameplayScreen that manages the level.
			@return Returns a pointer to the GameplayScreen. */
		GameplayScreen *GetGameplayScreen() const { return m_pGameplayScreen; }

		/** @brief Gets the ResourceManager for loading the level's resources.
		@return Returns a pointer to the ResourceManager. */
		ResourceManager *GetResourceManager() const { return m_pGameplayScreen->GetResourceManager(); }

		/** @brief Gets the ParticleManager for loading the level's resources.
		@return Returns a pointer to the ResourceManager. */
		ParticleManager *GetParticleManager() const { return m_pGameplayScreen->GetParticleManager(); }


	private:

		GameplayScreen *m_pGameplayScreen = nullptr;

		CollisionManager *m_pCollisionManager = nullptr;;

		std::vector<GameObject *> *m_pSectors;

		Vector2 m_sectorCount;
		Vector2 m_sectorSize;

		unsigned int m_totalSectorCount;

		std::vector<GameObject *> m_gameObjects;
		std::vector<GameObject *>::iterator m_gameObjectIt;

		ALLEGRO_SAMPLE *m_pSample;
		ALLEGRO_SAMPLE_ID m_sampleID;

		void CheckCollisions(std::vector<GameObject *> &sector);

		virtual Vector2 GetSectorCount() const { return m_sectorCount; }

		virtual Vector2 GetSectorSize() const { return m_sectorSize; }

		virtual unsigned int GetTotalSectorCount() const { return m_totalSectorCount; }

		virtual std::vector<GameObject *> *GetSectors() { return m_pSectors; }

	};
}