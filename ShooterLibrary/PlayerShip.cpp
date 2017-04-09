
/*      .                         ,'`.       .                         
   .                  .."    _.-;' ⁄‚ `.              .			`      
              _.-"`.##%"_.--" ,' ⁄`     `.           "#"     ___,,od000
           ,'"-_ _.-.--"\   ,'            `-_       '%#%',,/00000000000
         ,'     |_.'     )`/-     __..--""`-_`-._    J L/00000000000000
 . +   ,'   _.-"        / /   _-""           `-._`-_/___\///0000   000M
     .'_.-""      '    :_/_.-'                 _,`-/__V__\0000    00MMM
 . _-""                         .        '   _,/000\  |  /000    0MMMMM
_-"   .       '     .              .        ,/   000\ | /000000000MMMMM
       `       Shooter Library       '     ,/     000\|/000000000MMMMMM
.       © 2017 - Shuriken Studios LLC     ,/0    00000|0000000000MMMMMM */

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
		SetCollisionRadius(40);
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
			GetSpriteBatch()->Draw(m_pTexture, GetPosition(), Color::Blue, m_textureOrigin, Vector2::One, 0, 1);
		}
	}

	void PlayerShip::HandleInput(InputState *pInput)
	{
		Vector2 direction = Vector2::Zero;
		if (pInput->IsKeyDown(Key::DOWN)) direction.Y++;
		if (pInput->IsKeyDown(Key::UP)) direction.Y--;
		if (pInput->IsKeyDown(Key::RIGHT)) direction.X++;
		if (pInput->IsKeyDown(Key::LEFT)) direction.X--;

		// Normalize the direction
		if (direction.X != 0 && direction.Y != 0)
		{
			direction *= Math::NORMALIZE_PI_OVER4;
		}

		// gamepad overrides keyboard input
		//Vector2 thumbstick = pInput->GetGamePadState(0).Thumbsticks.Left;
		//if (thumbstick != Vector2::Zero()) direction = thumbstick;

		SetDesiredDirection(direction);

		uint32_t type = TRIGGERTYPE_NONE;
		if (pInput->IsKeyDown(Key::F)) type |= TRIGGERTYPE_PRIMARY;
		if (pInput->IsKeyDown(Key::D)) type |= TRIGGERTYPE_SECONDARY;
		if (pInput->IsKeyDown(Key::S)) type |= TRIGGERTYPE_SPECIAL;
		FireWeapons((TriggerType)type);
		
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
		if (pGameObject1->IsMask(COLLISIONTYPE_PLAYER | COLLISIONTYPE_SHIP)) return static_cast<PlayerShip *>(pGameObject1);
		if (pGameObject2->IsMask(COLLISIONTYPE_PLAYER | COLLISIONTYPE_SHIP)) return static_cast<PlayerShip *>(pGameObject2);

		return nullptr;
	}
}