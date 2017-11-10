
#include "Projectile.h"

Texture *Projectile::s_pTexture = nullptr;

Projectile::Projectile()
{
	SetSpeed(500);
	SetDamage(1);
	SetDirection(-Vector2::UNIT_Y);
	SetCollisionRadius(9);

	m_drawnByLevel = true;
}

void Projectile::Update(const GameTime *pGameTime)
{
	if (IsActive())
	{
		Vector2 translation = m_direction * m_speed * pGameTime->GetTimeElapsed();
		TranslatePosition(translation);

		Vector2 position = GetPosition();
		Vector2 size = s_pTexture->GetSize();

		// Is the projectile off the screen?
		if (position.Y < -size.Y) Deactivate();
		else if (position.X < -size.X) Deactivate();
		else if (position.Y > Game::GetScreenHeight() + size.Y) Deactivate();
		else if (position.X > Game::GetScreenWidth() + size.X) Deactivate();
	}

	GameObject::Update(pGameTime);
}

void Projectile::Draw(SpriteBatch *pSpriteBatch)
{
	if (IsActive())
	{
		pSpriteBatch->Draw(s_pTexture, GetPosition(), Color::White, s_pTexture->GetCenter());
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

CollisionType Projectile::GetCollisionType() const
{
	CollisionType shipType = WasShotByPlayer() ? CollisionType::PLAYER : CollisionType::ENEMY;
	return (shipType | GetProjectileType());
}