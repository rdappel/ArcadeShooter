
#include "ShooterLibrary.h"

EnemyShip::EnemyShip()
{
	// Set starting attributes
	m_position.X = Game::GetScreenWidth() / 2;
	m_position.Y = -100.0f;

	m_speed = 250.0f;

	m_isActive = false;
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
	m_position = position;
	m_delaySeconds = delaySeconds;

	Ship::Initialize();
}

void EnemyShip::Fire()
{
	// TODO: Make enemies fire?
}