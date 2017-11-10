
#include "Ship.h"


Ship::Ship()
{
	SetPosition(0, 0);
	SetCollisionRadius(10);

	m_speed = 300;
	m_maxHitPoints = 3;
	m_isInvulnurable = false;

	Initialize();
}

void Ship::Update(const GameTime *pGameTime)
{
	m_weaponIt = m_weapons.begin();
	for (; m_weaponIt != m_weapons.end(); m_weaponIt++)
	{
		(*m_weaponIt)->Update(pGameTime);
	}

	GameObject::Update(pGameTime);
}

void Ship::Hit(const float damage)
{
	if (!m_isInvulnurable)
	{
		m_hitPoints -= damage;

		if (m_hitPoints <= 0)
		{
			GameObject::Deactivate();
		}
	}
}

void Ship::Initialize()
{
	m_hitPoints = m_maxHitPoints;
}

void Ship::FireWeapons(TriggerType type)
{
	m_weaponIt = m_weapons.begin();
	for (; m_weaponIt != m_weapons.end(); m_weaponIt++)
	{
		(*m_weaponIt)->Fire(type);
	}
}

void Ship::AttachWeapon(Weapon *pWeapon, Vector2 position)
{
	pWeapon->SetGameObject(this);
	pWeapon->SetOffset(position);
	m_weapons.push_back(pWeapon);
}