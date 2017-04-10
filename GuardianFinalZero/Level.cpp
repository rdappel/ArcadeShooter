/*
                  '888 88888888888 888888888',8888'
                    88 888888888888 8888888',8888'
                     8 8888             ,8',8888'
          ==̲=̲=̲=̲=̲=̲=== 8 8888 ========== ,8 ,̲8̲88̲8_==============
          /  ____/__ 8_̲88̲8̲8̲8̲88̲88̲8̲8̲8__ ,̲8__/ //_/____ _ ____
	     / /  __ / / / /ˊ __ `// ___/ˊ __  /__ ˊ __ `// __ \
	    / /__/ // /_/ // /_/ // /   / /_/ // // /_/ // / / /
	    \_____/ \__,_/ \__,_//_/    \__,_//_/ \__,_//_/ /_/
      ============== 8 8888 ===== ,8',8888' ===============
                    88 8888      ,8',8888888888888 
                   ,88 8888     ,8',888888888888888,
				   
				          ファイナル ゼロ

               Guardian FZ © 2017 - Shuriken Studios LLC          */

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