#include "ShooterLibrary.h"

Ship::Ship()
{
	// Set starting attributes
	SetPosition(0, 0);
	SetCollisionRadius(10);

	m_speed = 250;
	m_gunOffsets.push_back(Vector2(0, -30));
	m_baseHitPoints = 3;
	m_isInvulnurable = false;

	Initialize();
}

void Ship::Update(const GameTime *pGameTime)
{
	GameObject::Update(pGameTime);
}
/**
Bullet *Ship::GetInactiveBullet()
{
	if (m_pBullets)
	{
		m_bulletIt = m_pBullets->begin();
		for (; m_bulletIt != m_pBullets->end(); m_bulletIt++)
		{
			Bullet *pBullet = *m_bulletIt;
			if (!pBullet->IsActive()) return pBullet;
		}
	}

	return nullptr;
}

Missile *Ship::GetInactiveMissile()
{
	if (m_pMissiles)
	{
		m_missileIt = m_pMissiles->begin();
		for (; m_missileIt != m_pMissiles->end(); m_missileIt++)
		{
			Missile *pMissile = *m_missileIt;
			if (!pMissile->IsActive()) return pMissile;
		}
	}

	return nullptr;
}
/**/
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
	m_hitPoints = m_baseHitPoints;
}