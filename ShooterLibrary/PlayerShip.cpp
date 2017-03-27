
#include "ShooterLibrary.h"


PlayerShip::PlayerShip()
{
	GameObject::Activate();

	m_pTexture = nullptr;
	m_textureOrigin = Vector2::Zero;

	m_responsiveness = 0.1f;

	SetPosition(Game::GetScreenCenter().X, Game::GetScreenHeight() - 100);
	SetCollisionRadius(50);
}

void PlayerShip::Update(const GameTime *pGameTime)
{
	// Update player position
	Vector2 targetVelocity = m_desiredDirection * GetSpeed() * pGameTime->GetTimeElapsed();
	m_velocity = Vector2::Lerp(m_velocity, targetVelocity, GetResponsiveness());
	TranslatePosition(m_velocity);
	ConfineToScreen();

	Ship::Update(pGameTime);
}

void PlayerShip::Draw(const GameTime *pGameTime)
{
	if (m_pTexture)
	{
		GetSpriteBatch()->Draw(m_pTexture, GetPosition(), Color::White, m_textureOrigin);
	}
}

void PlayerShip::ConfineToScreen()
{
	// Screen edges
	const int PADDING = 16;
	const int LEFT = PADDING;
	const int RIGHT = Game::GetScreenWidth() - PADDING;
	const int TOP = PADDING;
	const int BOTTOM = Game::GetScreenHeight() - PADDING;

	Vector2 position = GetPosition();

	// Check screen edges
	if (position.X - m_textureOrigin.X < LEFT)
	{
		SetPosition(LEFT + m_textureOrigin.X, position.Y);
	}
	if (position.X + m_textureOrigin.X > RIGHT)
	{
		SetPosition(RIGHT - m_textureOrigin.X, position.Y);
	}
	if (position.Y - m_textureOrigin.Y < TOP)
	{
		SetPosition(position.X, TOP + m_textureOrigin.Y);
	}
	if (position.Y + m_textureOrigin.Y > BOTTOM)
	{
		SetPosition(position.X, BOTTOM - m_textureOrigin.Y);
	}
}


void PlayerShip::SetTexture(Texture *pTexture)
{
	m_pTexture = pTexture;
	m_textureOrigin.Set(m_pTexture->GetSize() / 2);
}

void PlayerShip::SetResponsiveness(const float responsiveness)
{
	m_responsiveness = Math::Clamp(0, 1, responsiveness);
}