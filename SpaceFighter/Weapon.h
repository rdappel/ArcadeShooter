
#pragma once

#include "KatanaEngine.h"
#include "Projectile.h"
#include "TriggerType.h"

using namespace KatanaEngine;

class Weapon
{

public:

	Weapon(bool isActive = true)
	{
		m_isActive = isActive;
		SetTriggerType(TriggerType::PRIMARY);
	}

	virtual ~Weapon() { }

	virtual void Update(const GameTime *pGameTime) { };

	virtual void Draw(SpriteBatch *pSpriteBatch) { };

	virtual void Fire(TriggerType triggerType) = 0;

	virtual void SetGameObject(GameObject *pGameObject) { m_pGameObject = pGameObject; }

	virtual void SetOffset(Vector2 offset) { m_offset = offset; }

	virtual void SetTriggerType(TriggerType triggerType) { m_triggerType = triggerType; }

	virtual void SetProjectilePool(std::vector<Projectile *> *pProjectiles) { m_pProjectiles = pProjectiles; }

	virtual void Activate() { m_isActive = true; }

	virtual void Dectivate() { m_isActive = false; }

	virtual bool IsActive() const { return m_isActive && m_pGameObject->IsActive(); }


protected:

	virtual TriggerType GetTriggerType() const { return m_triggerType; }

	virtual Vector2 GetPosition() const { return m_pGameObject->GetPosition() + m_offset; }

	virtual Projectile *GetProjectile()
	{
		m_projectileIt = m_pProjectiles->begin();
		for (; m_projectileIt != m_pProjectiles->end(); m_projectileIt++)
		{
			Projectile *pProjectile = *m_projectileIt;
			if (!pProjectile->IsActive()) return pProjectile;
		}

		return nullptr;
	}


private:

	bool m_isActive;

	GameObject *m_pGameObject;

	Vector2 m_offset;

	TriggerType m_triggerType;

	std::vector<Projectile *>::iterator m_projectileIt;
	std::vector<Projectile *> *m_pProjectiles;

};

