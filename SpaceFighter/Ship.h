
#pragma once

#include "GameObject.h"
#include "Weapon.h"


class Ship : public GameObject
{
public:
	Ship();
	virtual ~Ship() { }

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(SpriteBatch *pSpriteBatch) = 0;

	virtual void Hit(const float damage);

	virtual bool IsInvulnurable() const { return m_isInvulnurable; }

	virtual void SetInvulnurable(bool isInvulnurable = true) { m_isInvulnurable = isInvulnurable; }

	virtual std::string ToString() const { return "Ship"; }

	virtual CollisionType GetCollisionType() const = 0;

	virtual void AttachWeapon(Weapon *pWeapon, Vector2 position);

	virtual float GetSpeed() const { return m_speed; }

	virtual void SetSpeed(const float speed) { m_speed = speed; }

	virtual void SetMaxHitPoints(const float hitPoints) { m_maxHitPoints = hitPoints; }


protected:

	virtual void Initialize();

	virtual void FireWeapons(TriggerType type = TriggerType::ALL);

	virtual Weapon *GetWeapon(const int index) { if (index < m_weapons.size()) return m_weapons[index]; return nullptr; }

	virtual float GetHitPoints() const { return m_hitPoints; }

	virtual float GetMaxHitPoints() const { return m_maxHitPoints; }


private:

	float m_speed;

	float m_hitPoints;
	float m_maxHitPoints;

	bool m_isInvulnurable;

	std::vector<Weapon *> m_weapons;
	std::vector<Weapon *>::iterator m_weaponIt;
};

