
#include "Sample.h"

using ShooterLibrary::Projectile;

namespace Sample
{
	PlayerShip::PlayerShip()
	{
		SetSpeed(450);
		SetResponsiveness(0.1);
		//SetInvulnurable();
	}

	void PlayerShip::Update(const GameTime *pGameTime)
	{
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

	float PlayerShip::GetResponsiveness() const
	{
		float firingDrag = 0.2f;
		//if (CanFire()) firingDrag = 1;
		return ShooterLibrary::PlayerShip::GetResponsiveness() * firingDrag;
	}

	PlayerShip *PlayerShip::Resolve(GameObject *pGameObject1, GameObject *pGameObject2)
	{
		if (pGameObject1->IsMask(COLLISIONTYPE_PLAYER | COLLISIONTYPE_SHIP)) return static_cast<PlayerShip *>(pGameObject1);
		if (pGameObject2->IsMask(COLLISIONTYPE_PLAYER | COLLISIONTYPE_SHIP)) return static_cast<PlayerShip *>(pGameObject2);

		return nullptr;
	}
}