
#include "ShooterLibrary.h"


namespace ShooterLibrary
{
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

	void PlayerShip::ConfineToScreen(const int padding)
	{
		const int LEFT = padding;
		const int RIGHT = Game::GetScreenWidth() - padding;
		const int TOP = padding;
		const int BOTTOM = Game::GetScreenHeight() - padding;

		Vector2 *pPosition = &GetPosition();
		if (pPosition->X - m_textureOrigin.X < LEFT)
		{
			SetPosition(LEFT + m_textureOrigin.X, pPosition->Y);
		}
		if (pPosition->X + m_textureOrigin.X > RIGHT)
		{
			SetPosition(RIGHT - m_textureOrigin.X, pPosition->Y);
		}
		if (pPosition->Y - m_textureOrigin.Y < TOP)
		{
			SetPosition(pPosition->X, TOP + m_textureOrigin.Y);
		}
		if (pPosition->Y + m_textureOrigin.Y > BOTTOM)
		{
			SetPosition(pPosition->X, BOTTOM - m_textureOrigin.Y);
		}
	}


	void PlayerShip::SetTexture(Texture *pTexture)
	{
		m_pTexture = pTexture;
		m_textureOrigin.Set(m_pTexture->GetCenter());
	}

	void PlayerShip::SetResponsiveness(const float responsiveness)
	{
		m_responsiveness = Math::Clamp(0, 1, responsiveness);
	}
	
	PlayerShip *PlayerShip::Resolve(GameObject *pGameObject1, GameObject *pGameObject2)
	{
		if (pGameObject1->IsMask(PLAYER | SHIP)) return static_cast<PlayerShip *>(pGameObject1);
		if (pGameObject2->IsMask(PLAYER | SHIP)) return static_cast<PlayerShip *>(pGameObject2);

		return nullptr;
	}
}