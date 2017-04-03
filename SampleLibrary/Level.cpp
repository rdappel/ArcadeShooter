
#include "Sample.h"

using ShooterLibrary::Projectile;
using ShooterLibrary::GameObject;

namespace Sample
{
	Level::Level()
	{
		m_pPlayerShip = new	PlayerShip();
	}

	void Level::LoadContent()
	{
		Texture *pTexture = GetResourceManager()->Load<Texture>("Textures\\PlayerShip.png");
		m_pPlayerShip->SetTexture(pTexture);

		Animation *pAnimation = GetResourceManager()->Load<Animation>("Animations\\Thruster.anim");
		if (pAnimation)
		{
			pAnimation->SetTexture(GetResourceManager()->Load<Texture>("Textures\\Thruster_01.png"));
			if (pAnimation->GetTexture())
			{
				m_pPlayerShip->SetThrusterAnimation(pAnimation);
				pAnimation->Play();
			}
		}

		for (int i = 0; i < 60; i++)
		{
			Projectile *pProjectile = new Projectile();
			m_projectiles.push_back(pProjectile);
			AddGameObject(pProjectile);
		}

		ShooterLibrary::Level::LoadContent();

		m_pPlayerShip->SetLevel(this);
	}

	void Level::AddGameObject(GameObject *pGameObject)
	{
		ShooterLibrary::Level::AddGameObject(pGameObject);
	}

	Projectile *Level::GetInactiveProjectile()
	{
		m_projectileIt = m_projectiles.begin();
		for (; m_projectileIt != m_projectiles.end(); m_projectileIt++)
		{
			if (!(*m_projectileIt)->IsActive()) return *m_projectileIt;
		}

		return nullptr;
	}


	ShooterLibrary::PlayerShip *Level::GetPlayerShip()
	{
		return m_pPlayerShip;
	}
}