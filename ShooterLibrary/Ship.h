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

	//virtual void SetBulletPool(std::vector<Bullet *> *pBullets) { m_pBullets = pBullets; }

	//virtual void SetMissilePool(std::vector<Missile *> *pMissiles) { m_pMissiles = pMissiles; }

	virtual void Hit(const float damage);

	virtual bool IsInvulnurable() const { return m_isInvulnurable; }

	virtual std::string ToString() const { return "Ship"; }

	virtual int GetCollisionMask() const { return COLLISION_ENEMYSHIP; }

protected:

	float m_speed;

	float m_hitPoints;

	float m_baseHitPoints;

	bool m_isInvulnurable;

	int m_gunIndex;

	std::vector<Vector2> m_gunOffsets;

	//virtual Bullet *GetInactiveBullet();

	//virtual Missile *GetInactiveMissile();

	virtual void Initialize();


private:
	/**
	std::vector<Bullet *>::iterator m_bulletIt;
	std::vector<Bullet *> *m_pBullets = nullptr;

	std::vector<Missile *>::iterator m_missileIt;
	std::vector<Missile *> *m_pMissiles = nullptr;
	/**/

};