

#pragma once

class GameObject;

class Level
{

public:

	Level();
	virtual ~Level();

	static Level *GetCurrentLevel() { return s_pCurrentLevel; }

	virtual void LoadContent();

	virtual void UnloadContent() { };

	virtual void HandleInput(InputState *pInput);

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(const GameTime *pGameTime);

	virtual void AddGameObject(GameObject *pGameObject);

	virtual void UpdateSectorPosition(GameObject *pGameObject);

	//virtual ParticleManager *GetParticleManager() { return &m_particleManager; }

	virtual PlayerShip *GetPlayerShip() { return &m_playerShip; }

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

	Vector2 m_sectorCount;

	Vector2 m_sectorSize;

	// Array of vectors!
	std::vector<GameObject *> *m_pSectors;

	unsigned int m_totalSectorCount;

	//Background *m_pBackground;

	//void SetAudioSample(std::string assetPath);


private:

	static Level *s_pCurrentLevel;

	//std::vector<Explosion *> m_explosions;
	//std::vector<Explosion *>::iterator m_explosionIt;

	PlayerShip m_playerShip;
	/**ParticleManager m_particleManager;

	std::vector<Bullet *> m_bullets;
	std::vector<Bullet *>::iterator m_bulletIt;

	std::vector<Missile *> m_missiles;
	std::vector<Missile *>::iterator m_missileIt;/**/

	std::vector<GameObject *> m_gameObjects;
	std::vector<GameObject *>::iterator m_gameObjectIt;

	ALLEGRO_SAMPLE *m_pSample;
	ALLEGRO_SAMPLE_ID m_sampleID;

	void CheckCollisions(std::vector<GameObject *> &sector);

	//SmokeTemplate<SmokeParticle> *m_pSmokeTemplate;

	void SpawnExplosion(const Vector2 &position);

	void FadeOutAudio() { if (m_pSample) al_stop_sample(&m_sampleID); }
};
