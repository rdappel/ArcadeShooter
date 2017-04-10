
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
	Texture *Projectile::s_pTexture = nullptr;

	Projectile::Projectile()
	{
		SetSpeed(400);
		SetDamage(1);
		SetDirection(-Vector2::UnitY);
		SetCollisionRadius(9);
	}

	void Projectile::Update(const GameTime *pGameTime)
	{
		if (IsActive())
		{
			Vector2 translation = m_direction * m_speed * pGameTime->GetTimeElapsed();
			TranslatePosition(translation);

			Vector2 position = GetPosition();
			Vector2 size = s_pTexture->GetSize();

			// is the projectile off the screen?
			if (position.Y < -size.Y) Deactivate();
			else if (position.X < -size.X) Deactivate();
			else if (position.Y > Game::GetScreenHeight() + size.Y) Deactivate();
			else if (position.X > Game::GetScreenWidth() + size.X) Deactivate();
		}

		GameObject::Update(pGameTime);
	}

	void Projectile::Draw(const GameTime *pGameTime)
	{
		if (s_pTexture)
		{
			GetSpriteBatch()->Draw(s_pTexture, GetPosition(), Color::White, s_pTexture->GetCenter());
		}
	}

	void Projectile::Activate(const Vector2 &position, bool wasShotByPlayer)
	{
		m_wasShotByPlayer = wasShotByPlayer;
		SetPosition(position);

		GameObject::Activate();
	}

	std::string Projectile::ToString() const
	{
		return ((WasShotByPlayer()) ? "Player " : "Enemy ") + GetProjectileTypeString();
	}

	uint32_t Projectile::GetCollisionType() const
	{
		return ((WasShotByPlayer()) ? COLLISIONTYPE_PLAYER : COLLISIONTYPE_ENEMY) | GetProjectileType();
	}
}