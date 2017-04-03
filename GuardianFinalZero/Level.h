
#pragma once

#include "GuardianFinalZero.h"

namespace GuardianFinalZero
{
	class Level : public ShooterLibrary::Level
	{

	public:

		Level();

		virtual ~Level() { }

		virtual PlayerShip *GetPlayerShip() { return m_pPlayerShip; }

		virtual void LoadContent();

		virtual ShooterLibrary::Projectile *GetInactiveProjectile();

	private:

		PlayerShip *m_pPlayerShip;

		std::vector<ShooterLibrary::Projectile *> m_projectiles;
		std::vector<ShooterLibrary::Projectile *>::iterator m_projectileIt;

	};
}