
#include "GuardianFinalZero.h"

namespace GuardianFinalZero
{
	PlayerShip::PlayerShip()
	{
		m_coolDownTime = 0;

		SetSpeed(450);
		SetResponsiveness(0.1);
		SetInvulnurable();
	}

	void PlayerShip::Update(const GameTime *pGameTime)
	{
		m_coolDownTime -= pGameTime->GetTimeElapsed();
		
		ShooterLibrary::PlayerShip::Update(pGameTime);
	}

	void PlayerShip::Draw(const GameTime *pGameTime)
	{
		ShooterLibrary::PlayerShip::Draw(pGameTime);
	}

	void PlayerShip::Fire()
	{
		if (CanFire())
		{
			ShooterLibrary::Projectile *pProjectile = nullptr;
			pProjectile = m_pLevel->GetInactiveProjectile();
			if (pProjectile)
			{
				pProjectile->Activate(GetPosition() - Vector2(0, 32));
				m_coolDownTime = 0.25f;
			}
		}
	}

	float PlayerShip::GetResponsiveness() const
	{
		float firingDrag = 0.2f;
		if (CanFire()) firingDrag = 1;
		return ShooterLibrary::PlayerShip::GetResponsiveness() * firingDrag;
	}
}