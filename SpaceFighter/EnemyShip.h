
#pragma once

#include "Ship.h"

class EnemyShip : public Ship
{

public:

	EnemyShip();
	virtual ~EnemyShip() { }

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(SpriteBatch *pSpriteBatch) = 0;

	virtual void Initialize(const Vector2 position, const double delaySeconds);

	virtual void Fire() { }

	virtual void Hit(const float damage);

	virtual std::string ToString() const { return "Enemy Ship"; }

	virtual CollisionType GetCollisionType() const { return CollisionType::ENEMY | CollisionType::SHIP; }


protected:

	virtual double GetDelaySeconds() const { return m_delaySeconds; }


private:

	double m_delaySeconds;

	double m_activationSeconds;


};
