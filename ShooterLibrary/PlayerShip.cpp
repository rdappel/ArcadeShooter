
#include "ShooterLibrary.h"


ALLEGRO_SAMPLE *PlayerShip::s_pSample = nullptr;
ALLEGRO_BITMAP *PlayerShip::s_pTexture = nullptr;
Vector2 PlayerShip::s_textureOrigin = Vector2::Zero;

PlayerShip::PlayerShip()
{
	GameObject::Activate();

	// Set the starting position
	m_position.X = Game::GetScreenWidth() / 2;
	m_position.Y = Game::GetScreenHeight() - 100.0f;

	m_speed = 300.0f;
	m_collisionRadius = 50.0f;

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

void PlayerShip::SetTexture(std::string assetPath)
{
	if (s_pTexture)
	{
		al_destroy_bitmap(s_pTexture);
		s_pTexture = nullptr;
	}

	ALLEGRO_BITMAP *pTemp = nullptr;

	//std::string path = Game::GetContentPath();
	//path.append(assetPath);

	/**

	pTemp = al_load_bitmap(path.c_str());
	if (pTemp)
	{
		s_pTexture = pTemp;
		s_textureOrigin.X = al_get_bitmap_width(s_pTexture) / 2;
		s_textureOrigin.Y = al_get_bitmap_height(s_pTexture) / 2;
	}
	/**/
}

void PlayerShip::SetAudioSample(std::string assetPath)
{
	if (s_pSample)
	{
		al_destroy_sample(s_pSample);
		s_pSample = nullptr;
	}

	ALLEGRO_SAMPLE *pTemp = nullptr;
	/**
	std::string path = Game::GetContentDirectory();
	path.append(assetPath);

	pTemp = al_load_sample(path.c_str());
	if (pTemp) s_pSample = pTemp;
	/**/
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
	m_previousPosition = m_position;
	Vector2 targetVelocity = m_desiredDirection * m_speed * pGameTime->GetTimeElapsed();
	m_velocity = Vector2::Lerp(m_velocity, targetVelocity, 0.1f);
	m_position += m_velocity;

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

	if (s_pTexture)
	{
		int x = (int)(m_position.X - s_textureOrigin.X);
		int y = (int)(m_position.Y - s_textureOrigin.Y);

		al_draw_bitmap(s_pTexture, x, y, 0);
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

	// Check screen edges
	if (m_position.X - s_textureOrigin.X < LEFT)
	{
		m_position.X = LEFT + s_textureOrigin.X;
	}
	if (m_position.X + s_textureOrigin.X > RIGHT)
	{
		m_position.X = RIGHT - s_textureOrigin.X;
	}
	if (m_position.Y - s_textureOrigin.Y < TOP)
	{
		m_position.Y = TOP + s_textureOrigin.Y;
	}
	if (m_position.Y + s_textureOrigin.Y > BOTTOM)
	{
		m_position.Y = BOTTOM - s_textureOrigin.Y;
	}
}


int PlayerShip::GetCollisionMask() const
{
	if (m_isInvulnurable) return COLLISION_NONE;
	return COLLISION_PLAYERSHIP;
}
