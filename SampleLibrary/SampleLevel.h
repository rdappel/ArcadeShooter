#pragma once

#include "ShooterLibrary.h"

class SamplePlayerShip;

class SampleLevel : public Level
{

public:

	SampleLevel();
	virtual ~SampleLevel() { }
	
	virtual void LoadContent();

	virtual void AddGameObject(GameObject *pGameObject);

	virtual PlayerShip *GetPlayerShip();

	virtual Projectile *GetInactiveProjectile();
		

private:

	SamplePlayerShip *m_pPlayerShip;

	std::vector<Projectile *> m_projectiles;
	std::vector<Projectile *>::iterator m_projectileIt;

};