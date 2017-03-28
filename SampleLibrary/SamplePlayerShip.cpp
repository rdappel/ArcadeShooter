
#include "SamplePlayerShip.h"

SamplePlayerShip::SamplePlayerShip()
{
	m_coolDownTime = 0;

	SetSpeed(450);
	SetResponsiveness(0.1);
	SetInvulnurable();
}

void SamplePlayerShip::Update(const GameTime *pGameTime)
{
	m_coolDownTime -= pGameTime->GetTimeElapsed();

	if (m_pThrusterAnimation) m_pThrusterAnimation->Update(pGameTime);

	PlayerShip::Update(pGameTime);
}

void SamplePlayerShip::Draw(const GameTime *pGameTime)
{
	if (m_pThrusterAnimation)
	{
		Vector2 origin(m_pThrusterAnimation->GetCurrentFrame()->Width / 2, 0);
		GetSpriteBatch()->Draw(m_pThrusterAnimation, GetPosition() + Vector2(-2, 14), Color::White, origin);
	}

	PlayerShip::Draw(pGameTime);
}

void SamplePlayerShip::Fire()
{
	if (CanFire())
	{
		Projectile *pProjectile = m_pLevel->GetInactiveProjectile();
		if (pProjectile)
		{
			pProjectile->Activate(GetPosition() - Vector2(0, 32));
			m_coolDownTime = 0.25f;
		}
	}
}

float SamplePlayerShip::GetResponsiveness() const
{
	float firingDrag = 0.2f;
	if (CanFire()) firingDrag = 1;
	return PlayerShip::GetResponsiveness() * firingDrag;
}