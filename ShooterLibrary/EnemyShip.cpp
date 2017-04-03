
#include "ShooterLibrary.h"

namespace ShooterLibrary
{
	EnemyShip::EnemyShip()
	{
		SetMaxHitPoints(1);
		SetCollisionRadius(20);
	}

	void EnemyShip::Update(const GameTime *pGameTime)
	{
		if (m_delaySeconds > 0)
		{
			m_delaySeconds -= pGameTime->GetTimeElapsed();

			if (m_delaySeconds <= 0)
			{
				GameObject::Activate();
			}
		}

		Ship::Update(pGameTime);
	}

	void EnemyShip::Initialize(const Vector2 position, const double delaySeconds)
	{
		SetPosition(position);
		m_delaySeconds = delaySeconds;

		Ship::Initialize();
	}
}