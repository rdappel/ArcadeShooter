
#include "ShooterLibrary.h"


PlayerShip::PlayerShip()
{
	GameObject::Activate();

	m_pTexture = nullptr;
	m_textureOrigin = Vector2::Zero;

	SetPosition(Game::GetScreenCenter().X, Game::GetScreenHeight() - 100);
	SetCollisionRadius(50);
}

void PlayerShip::Update(const GameTime *pGameTime)
{
	// Update player position
	Vector2 targetVelocity = m_desiredDirection * GetSpeed() * pGameTime->GetTimeElapsed();
	m_velocity = Vector2::Lerp(m_velocity, targetVelocity, 0.1f);
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
	const int LEFT = 0;
	const int RIGHT = Game::GetScreenWidth();
	const int TOP = 0;
	const int BOTTOM = Game::GetScreenHeight();

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
