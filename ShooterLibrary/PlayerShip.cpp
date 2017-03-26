
#include "ShooterLibrary.h"


PlayerShip::PlayerShip()
{
	GameObject::Activate();

	m_pTexture = nullptr;
	m_textureOrigin = Vector2::Zero;

	SetPosition(Game::GetScreenCenter().X, Game::GetScreenHeight() - 100);
	SetCollisionRadius(50);

	m_speed = 300;
	
	m_bulletCoolDownTime = 0;
	m_missileCoolDownTime = 0;
	m_maxBulletCoolDownTime = 0.05f;
	m_maxMissileCoolDownTime = 1.5f;

	m_gunOffsets.clear();
	m_gunOffsets.push_back(Vector2(-23.0f, -38.0f));
	m_gunOffsets.push_back(Vector2(23.0f, -38.0f));
	m_gunOffsets.push_back(Vector2(-44.0f, -28.0f));
	m_gunOffsets.push_back(Vector2(44.0f, -28.0f));

	/**
	m_pThruster = new Thruster(3);
	m_pThruster->SetTexture("Textures//Thruster_01.png");
	m_thrusterOffset.Set(-3, 86);
	/**/

	m_isInvulnurable = false;
}

PlayerShip::~PlayerShip()
{
	//if (m_pThruster) delete m_pThruster;
}

void PlayerShip::Update(const GameTime *pGameTime)
{
	// Decrement the cooldown timers
	if (m_bulletCoolDownTime > 0)
	{
		m_bulletCoolDownTime -= pGameTime->GetTimeElapsed();
	}
	if (m_missileCoolDownTime > 0)
	{
		m_missileCoolDownTime -= pGameTime->GetTimeElapsed();
	}

	// Update player position
	Vector2 targetVelocity = m_desiredDirection * m_speed * pGameTime->GetTimeElapsed();
	m_velocity = Vector2::Lerp(m_velocity, targetVelocity, 0.1f);
	TranslatePosition(m_velocity);

	ConfineToScreen();

	Ship::Update(pGameTime);
	/**if (m_pThruster)
	{
		m_pThruster->SetPosition(m_position + m_thrusterOffset);
		m_pThruster->Update(pGameTime);
	}/**/
}

void PlayerShip::Draw(const GameTime *pGameTime)
{
	//if (m_pThruster) m_pThruster->Draw(pGameTime);

	if (m_pTexture)
	{
		GetSpriteBatch()->Draw(m_pTexture, GetPosition(), Color::White, m_textureOrigin);
	}
}

void PlayerShip::Fire()
{
	if (IsActive())
	{
		/**
		if (CanFireBullet() && true)
		{
			Bullet *pBullet = GetInactiveBullet();
			if (pBullet)
			{
				Vector2 offset = m_gunOffsets[m_gunIndex];
				m_gunIndex++;
				if (m_gunIndex >= (int)m_gunOffsets.size()) m_gunIndex = 0;
				pBullet->Activate(m_position + offset);
				m_bulletCoolDownTime = m_maxBulletCoolDownTime;
				AudioManager::PlaySample(s_pSample);
			}
		}

		if (CanFireMissile() && true)
		{
			for (int i = 0; i < 6; i++)
			{
				Missile *pMissile = GetInactiveMissile();
				if (pMissile)
				{
					Vector2 offset(40, 0);
					if (i % 2) offset *= -1;
					pMissile->Activate(m_position + offset);

					int index = i / 2;
					int x = (i / 2 + 1) * 40;
					offset.X = x * 1.25f;
					if (i % 2) offset *= -1;
					offset.Y += 20 * index;
					pMissile->SetActivationPosition(m_position + offset);
					pMissile->SetActivationSeconds(0.1f * index + 0.1f);
				}
			}

			m_missileCoolDownTime = m_maxMissileCoolDownTime;
		}/**/
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

