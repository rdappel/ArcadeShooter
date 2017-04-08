
#include "Sample.h"

using ShooterLibrary::Projectile;

namespace Sample
{
	PlayerShip::PlayerShip()
	{
		m_coolDownTime = 0;
		m_baseCoolDownTime = 0.25f;

		SetSpeed(450);
		SetResponsiveness(0.1);
		//SetInvulnurable();
	}

	void PlayerShip::Update(const GameTime *pGameTime)
	{
		m_coolDownTime -= pGameTime->GetTimeElapsed();

		if (m_pThrusterAnimation) m_pThrusterAnimation->Update(pGameTime);

		ShooterLibrary::PlayerShip::Update(pGameTime);
	}

	void PlayerShip::Draw(const GameTime *pGameTime)
	{
		if (m_pThrusterAnimation)
		{
			Vector2 origin(m_pThrusterAnimation->GetCurrentFrame()->Width / 2, 0);
			GetSpriteBatch()->Draw(m_pThrusterAnimation, GetPosition() + Vector2(-2, 14), Color::White, origin);
		}

		ShooterLibrary::PlayerShip::Draw(pGameTime);
	}

	void PlayerShip::Fire()
	{
 		if (CanFire())
		{
			Projectile *pProjectile = m_pLevel->GetInactiveProjectile();
			if (pProjectile)
			{
				pProjectile->Activate(GetPosition() - Vector2(0, 32));
  				m_coolDownTime = m_baseCoolDownTime;
			}
		}
	}

	void PlayerShip::IncreaseFireRate()
	{
		static const float amount = 0.025f;
		if (m_baseCoolDownTime - amount > 0.05f)
			m_baseCoolDownTime -= amount;
	}

	float PlayerShip::GetResponsiveness() const
	{
		float firingDrag = 0.2f;
		if (CanFire()) firingDrag = 1;
		return ShooterLibrary::PlayerShip::GetResponsiveness() * firingDrag;
	}

	PlayerShip *PlayerShip::Resolve(GameObject *pGameObject1, GameObject *pGameObject2)
	{
		if (pGameObject1->IsMask(PLAYER | SHIP)) return static_cast<PlayerShip *>(pGameObject1);
		if (pGameObject2->IsMask(PLAYER | SHIP)) return static_cast<PlayerShip *>(pGameObject2);

		return nullptr;
	}
}