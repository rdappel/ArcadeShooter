
#include "ShooterLibrary.h"

namespace ShooterLibrary
{

	void ProjectilePool::Draw(SpriteBatch *pSpriteBatch)
	{
		m_projectileIt = m_projectiles.begin();
		for (; m_projectileIt != m_projectiles.end(); m_projectileIt++)
		{
			(*m_projectileIt)->Draw(pSpriteBatch);
		}
	}


	void ProjectilePool::Add(Projectile *pProjectile)
	{
		m_pLevel->AddGameObject(pProjectile);
		m_projectiles.push_back(pProjectile);
	}

}