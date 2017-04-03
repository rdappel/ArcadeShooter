
#include "KatanaEngine.h"

namespace KatanaEngine
{
	Particle::Particle()
	{
		m_lifeSeconds = 0;
		m_color = Color::White;
		m_scale = 1;
		m_alpha = 1;
		m_rotation = 0;
	}

	void Particle::Update(const GameTime *pGameTime)
	{
		if (IsActive())
		{
			m_lifeSeconds -= pGameTime->GetTimeElapsed();
		}

		m_pTemplate->UpdateParticle(this, pGameTime);
	}

	void Particle::Draw(const GameTime *pGameTime)
	{
		if (IsActive())
		{
			int index = 0;

			/**
			ALLEGRO_BITMAP *pTexture = m_pTemplate->GetTexture();
			Vector2 textureOrigin = m_pTemplate->GetTextureOrigin();
			Vector2 textureSize = m_pTemplate->GetTextureSize();

			if (pTexture)
			{
				ALLEGRO_COLOR color = m_color;
				color.a = m_alpha;

				int dx = (int)m_position.X;
				int dy = (int)m_position.Y;
				int cx = (int)textureOrigin.X;
				int cy = (int)textureOrigin.Y;
				int sw = (int)textureSize.X;
				int sh = (int)textureSize.Y;

				al_draw_tinted_scaled_rotated_bitmap_region(
					pTexture, 0, 0, sw, sh, color, cx, cy, dx, dy,
					m_scale, m_scale, m_rotation, 0);
			}
			/**/
		}
	}

	float Particle::GetInterpolationValue()
	{
		if (m_lifeSeconds <= 0) return 0;
		if (m_lifeSeconds >= m_lifespan) return 1;

		return (m_lifeSeconds / m_lifespan);
	}
}