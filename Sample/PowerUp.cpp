
/*   .oooooo..o       .o.       ooo        ooooo ooooooooo.   ooooo        oooooooooooo
	d8P'    `Y8      .888.      `88.       .888' `888   `Y88. `888'        `888'     `8
	Y88bo.          .8"888.      888b     d'888   888   .d88'  888          888
	 `"Y8888o.     .8' `888.     8 Y88. .P  888   888ooo88P'   888          888oooo8
		 `"Y88b   .88ooo8888.    8  `888'   888   888          888          888    "
	oo     .d8P  .8'     `888.   8    Y     888   888          888       o  888       o
	8""88888P'  o88o     o8888o o8o        o888o o888o        o888ooooood8 o888ooooood8

					        Sample © 2017 - Shuriken Studios LLC                          */

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
			m_alpha = ((sin(pGameTime->GetTotalTime() * 4) + 1) / 8) + 0.75f;

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

	void PowerUp::Draw(SpriteBatch *pSpriteBatch)
	{
		Color c = Color::Orange * m_alpha;

		pSpriteBatch->Draw(s_pGlowTexture, GetPosition(), c, s_pTexture->GetSize() / 2, Vector2::One / 2);
		pSpriteBatch->Draw(s_pTexture, GetPosition(), Color::White, s_pTexture->GetSize() / 2, Vector2::One / 2);
	}

	void PowerUp::Activate(const Vector2 position, Level *pLevel)
	{
		m_pLevel = pLevel;
		m_pTarget = nullptr;
		m_targetCheck = 0;
		m_velocity = Vector2::GetRandom(true) + Vector2::UnitY * 0.4f;

		GameObject::Activate();
		SetPosition(position);
	}
}