
#pragma once

#include "KatanaEngine.h"
#include "PlayerShip.h"
#include "CollisionManager.h"

using namespace KatanaEngine;


class Level
{

public:

	Level();
	virtual ~Level();

	virtual void LoadContent(ResourceManager *pResourceManager);

	virtual void UnloadContent() = 0;

	virtual void HandleInput(const InputState *pInput);

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(SpriteBatch *pSpriteBatch);

	virtual void AddGameObject(GameObject *pGameObject) { m_gameObjects.push_back(pGameObject); }

	virtual void UpdateSectorPosition(GameObject *pGameObject);

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

	virtual CollisionManager *GetCollisionManager() { return m_pCollisionManager; }


private:

	CollisionManager *m_pCollisionManager = nullptr;

	std::vector<GameObject *> *m_pSectors;

	Vector2 m_sectorCount;
	Vector2 m_sectorSize;

	unsigned int m_totalSectorCount;

	std::vector<GameObject *> m_gameObjects;
	std::vector<GameObject *>::iterator m_gameObjectIt;

	PlayerShip *m_pPlayerShip;
	std::vector<Projectile *> m_projectiles;


	void CheckCollisions(std::vector<GameObject *> &sector);

	virtual Vector2 GetSectorCount() const { return m_sectorCount; }

	virtual Vector2 GetSectorSize() const { return m_sectorSize; }

	virtual unsigned int GetTotalSectorCount() const { return m_totalSectorCount; }

	virtual std::vector<GameObject *> *GetSectors() { return m_pSectors; }

};
