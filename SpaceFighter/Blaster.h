
#pragma once

#include "Weapon.h"

class Blaster : public Weapon
{

public:


	Blaster(const bool isActive) : Weapon(isActive)
	{
		m_cooldown = 0;
		m_cooldownSeconds = 0.25;
	}

	virtual ~Blaster() { }

	virtual void Update(const GameTime *pGameTime)
	{
		if (m_cooldown > 0) m_cooldown -= pGameTime->GetTimeElapsed();
	}

	virtual bool CanFire() const { return m_cooldown <= 0; }

	virtual void ResetCooldown() { m_cooldown = 0; }

	virtual float GetCooldownSeconds() { return m_cooldownSeconds; }

	virtual void SetCooldownSeconds(const float seconds) { m_cooldownSeconds = seconds; }

	virtual void Fire(TriggerType triggerType)
	{
		bool ia = IsActive();
		bool cf = CanFire();

		if (IsActive() && CanFire())
		{
			if (triggerType.Contains(GetTriggerType()))
			{
				Projectile *pProjectile = GetProjectile();
				if (pProjectile)
				{
					pProjectile->Activate(GetPosition(), true);
					m_cooldown = m_cooldownSeconds;
				}
			}
		}
	}


private:

	float m_cooldown;
	float m_cooldownSeconds;

};