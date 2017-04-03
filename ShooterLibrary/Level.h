
#pragma once

namespace ShooterLibrary
{
	class GameObject;

	class Level
	{

	public:

		Level();
		virtual ~Level();

		virtual void LoadContent();

		virtual void UnloadContent() { };

		virtual void HandleInput(InputState *pInput);

		virtual void Update(const GameTime *pGameTime);

		virtual void Draw(const GameTime *pGameTime);

		virtual void AddGameObject(GameObject *pGameObject);

		virtual void UpdateSectorPosition(GameObject *pGameObject);

		//virtual ParticleManager *GetParticleManager() { return &m_particleManager; }

		virtual PlayerShip *GetPlayerShip() = 0;// { return m_pPlayerShip; }

		virtual SpriteBatch *GetSpriteBatch() const { return m_pGameplayScreen->GetSpriteBatch(); }

		virtual void SetGameplayScreen(GameplayScreen *pGameplayscreen) { m_pGameplayScreen = pGameplayscreen; }

		template <typename T>
		T *GetClosestObject(const Vector2 position, const float range)
		{
			float squaredRange = range * range;
			if (range <= 0) squaredRange = std::numeric_limits<float>::infinity();
			float squaredDistance;

			std::vector<GameObject *>::iterator m_it = m_gameObjects.begin();
			T *pClosest = nullptr;

			for (; m_it != m_gameObjects.end(); m_it++)
			{
				GameObject *pGameObject = *m_it;
				if (!pGameObject->IsActive()) continue;

				squaredDistance = (position - pGameObject->GetPosition()).DistanceSquared();
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

		GameplayScreen *GetGameplayScreen() const { return m_pGameplayScreen; }

		ResourceManager *GetResourceManager() const { return m_pGameplayScreen->GetResourceManager(); }

		Vector2 m_sectorCount;

		Vector2 m_sectorSize;

		std::vector<GameObject *> *m_pSectors;

		unsigned int m_totalSectorCount;


	private:

		GameplayScreen *m_pGameplayScreen = nullptr;

		std::vector<GameObject *> m_gameObjects;
		std::vector<GameObject *>::iterator m_gameObjectIt;

		ALLEGRO_SAMPLE *m_pSample;
		ALLEGRO_SAMPLE_ID m_sampleID;

		void CheckCollisions(std::vector<GameObject *> &sector);

	};
}