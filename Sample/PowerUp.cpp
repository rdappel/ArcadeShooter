
#include "Sample.h"

namespace Sample
{
	Texture *PowerUp::s_pTexture = nullptr;
	Texture *PowerUp::s_pGlowTexture = nullptr;

	PowerUp::PowerUp()
	{
		SetCollisionRadius(1);
		m_pMagnetDistance = 300;
	}

	void PowerUp::Update(const GameTime *pGameTime)
	{
		if (IsActive())
		{
			if (m_pTarget && !m_pTarget->IsActive()) m_pTarget = nullptr;

			if (m_pTarget)
			{
				float dist = m_pMagnetDistance * m_pMagnetDistance;
				if (Vector2::DistanceSquared(GetPosition(), m_pTarget->GetPosition()) > dist)
				{
					m_pTarget = nullptr;
				}
			}

			m_targetCheck--;
			if (m_targetCheck <= 0)
			{
				m_targetCheck = Math::GetRandomInt(8, 9);
				m_pTarget = m_pLevel->GetClosestObject<PlayerShip>(GetPosition(), m_pMagnetDistance);
			}

			if (m_pTarget)
			{
				m_velocity = m_pTarget->GetPosition() - GetPosition();
				float dist = Vector2::Distance(m_pTarget->GetPosition(), GetPosition());
				m_velocity /= dist; // normalize
				m_velocity *= (m_pMagnetDistance / dist);
			}

			TranslatePosition(m_velocity);
		}

		GameObject::Update(pGameTime);
	}

	void PowerUp::Draw(const GameTime *pGameTime)
	{
		float alpha = ((sin(pGameTime->GetTotalTime() * 4) + 1) / 8) + 0.75f;
		Color c = Color::Orange * alpha;

		GetSpriteBatch()->Draw(s_pGlowTexture, GetPosition(), c, s_pTexture->GetSize() / 2, Vector2::One / 2);
		GetSpriteBatch()->Draw(s_pTexture, GetPosition(), Color::White, s_pTexture->GetSize() / 2, Vector2::One / 2);
	}

	void PowerUp::Activate(const Vector2 position, Level *pLevel)
	{
		m_pLevel = pLevel;
		m_pTarget = nullptr;
		m_targetCheck = 0;
		m_velocity = Vector2::GetRandom(true);

		GameObject::Activate();
		SetPosition(position);
	}

	PowerUp *PowerUp::Resolve(GameObject *pGameObject1, GameObject *pGameObject2)
	{
		if (pGameObject1->HasMask(COLLISIONTYPE_POWERUP)) return static_cast<PowerUp *>(pGameObject1);
		if (pGameObject2->HasMask(COLLISIONTYPE_POWERUP)) return static_cast<PowerUp *>(pGameObject2);

		return nullptr;
	}
}