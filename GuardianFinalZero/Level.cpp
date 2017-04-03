
#include "GuardianFinalZero.h"

namespace GuardianFinalZero
{
	Level::Level()
	{
		m_pPlayerShip = new	PlayerShip();
	}

	void Level::LoadContent()
	{
		Texture *pTexture = GetResourceManager()->Load<Texture>("Textures\\PlayerShip.png");
		m_pPlayerShip->SetTexture(pTexture);
		m_pPlayerShip->SetLevel(this);

		for (int i = 0; i < 60; i++)
		{
			ShooterLibrary::Projectile *pProjectile = new ShooterLibrary::Projectile();
			m_projectiles.push_back(pProjectile);
			AddGameObject(pProjectile);
		}

		ShooterLibrary::Level::LoadContent();
	}

	ShooterLibrary::Projectile *Level::GetInactiveProjectile()
	{
		m_projectileIt = m_projectiles.begin();
		for (; m_projectileIt != m_projectiles.end(); m_projectileIt++)
		{
			if (!(*m_projectileIt)->IsActive()) return *m_projectileIt;
		}

		return nullptr;
	}
}