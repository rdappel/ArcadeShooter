
#include "ShooterLibrary.h"

namespace ShooterLibrary
{
	void ProjectilePool::Add(Projectile *pProjectile)
	{
		m_pLevel->AddGameObject(pProjectile);
		m_projectiles.push_back(pProjectile);
	}
}