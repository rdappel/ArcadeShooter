
#include "ShooterLibrary.h"

namespace ShooterLibrary
{
	Texture *Projectile::s_pTexture = nullptr;
	Vector2 Projectile::s_textureOrigin = Vector2::Zero;

	Projectile::Projectile()
	{
		m_speed = 400;
		m_damage = 1;
		m_direction.Set(0, -1);
		SetCollisionRadius(9);
	}

	void Projectile::Update(const GameTime *pGameTime)
	{
		if (IsActive())
		{
			Vector2 translation = m_direction * m_speed * pGameTime->GetTimeElapsed();
			TranslatePosition(translation);

			if (GetPosition().Y < s_textureOrigin.Y) Deactivate();
		}

		GameObject::Update(pGameTime);
	}

	void Projectile::Draw(const GameTime *pGameTime)
	{
		if (s_pTexture)
		{
			GetSpriteBatch()->Draw(s_pTexture, GetPosition(), Color::White, s_textureOrigin);
		}
	}

	void Projectile::Activate(const Vector2 &position, bool isShotByPlayer)
	{
		m_isShotByPlayer = isShotByPlayer;
		SetPosition(position);

		GameObject::Activate();
	}

	void Projectile::SetTexture(Texture *pTexture)
	{
		s_pTexture = pTexture;
		s_textureOrigin.Set(s_pTexture->GetCenter());
	}

	std::string Projectile::ToString() const
	{
		if (m_isShotByPlayer) return "Player Projectile";
		return "Enemy Projectile";
	}

	uint32_t Projectile::GetCollisionMask() const
	{
		if (m_isShotByPlayer) return (PLAYER | PROJECTILE);
		return (ENEMY | PROJECTILE);
	}

	Projectile *Projectile::Resolve(GameObject *pGameObject1, GameObject *pGameObject2)
	{
		if (pGameObject1->HasMask(PROJECTILE)) return static_cast<Projectile *>(pGameObject1);
		if (pGameObject2->HasMask(PROJECTILE)) return static_cast<Projectile *>(pGameObject2);
	}
}