
#include "SampleLevel.h"
#include "SamplePlayerShip.h"

SampleLevel::SampleLevel()
{
	m_pPlayerShip = new	SamplePlayerShip();
}

void SampleLevel::LoadContent()
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

	Level::LoadContent();

	m_pPlayerShip->SetSampleLevel(this);
}

void SampleLevel::AddGameObject(GameObject *pGameObject)
{
	Level::AddGameObject(pGameObject);
}

Projectile *SampleLevel::GetInactiveProjectile()
{
	m_projectileIt = m_projectiles.begin();
	for (; m_projectileIt != m_projectiles.end(); m_projectileIt++)
	{
		if (!(*m_projectileIt)->IsActive()) return *m_projectileIt;
	}

	return nullptr;
}


PlayerShip *SampleLevel::GetPlayerShip()
{
	return m_pPlayerShip;
}