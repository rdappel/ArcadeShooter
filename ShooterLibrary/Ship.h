#pragma once

#include "ShooterLibrary.h"


class Ship : public GameObject
{
public:

	Ship();
	virtual ~Ship() { }

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(const GameTime *pGameTime) = 0;

	virtual void Fire() = 0;

	virtual void Hit(const float damage);

	virtual bool IsInvulnurable() const { return m_isInvulnurable; }

	virtual std::string ToString() const { return "Ship"; }

	virtual CollisionMask GetCollisionMask() const { return CollisionMask::ENEMY_SHIP; }


protected:

	virtual void Initialize();

	virtual float GetSpeed() const { return m_speed; }

	virtual void SetSpeed(const float speed) { m_speed = speed; }

	virtual void SetMaxHitPoints(const float hitPoints) { m_maxHitPoints = hitPoints; }


private:

	float m_speed;

	float m_hitPoints;

	float m_maxHitPoints;

	bool m_isInvulnurable;

};