#include "ShooterLibrary.h"

Ship::Ship()
{
	SetPosition(0, 0);
	SetCollisionRadius(10);

	m_speed = 300;
	m_maxHitPoints = 3;
	m_isInvulnurable = false;

	Initialize();
}

void Ship::Hit(const float damage)
{
	if (!m_isInvulnurable)
	{
		m_hitPoints -= damage;
		std::cout << "HIT! >> HP: " << m_hitPoints << std::endl;

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