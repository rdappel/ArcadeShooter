
/*	 ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗ 
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
        Katana Engine \/ © 2012 - Shuriken Studios LLC              */

#include "KatanaEngine.h"

namespace KatanaEngine
{

	uint32_t Particle::s_count = 0;

	Particle::Particle()
	{
		m_lifeSeconds = 0;
		m_color = Color::White;
		m_scale = Vector2::ONE;
		m_alpha = 0;
		m_rotation = 0;

		m_index = s_count;
		s_count++;
	}

	void Particle::Update(const GameTime *pGameTime)
	{
		m_lifeSeconds -= pGameTime->GetTimeElapsed();
		if (IsActive())
		{
			m_pTemplate->UpdateParticle(this, pGameTime);
		}
		
	}

	void Particle::Draw(SpriteBatch *pSpriteBatch)
	{
		if (IsActive())
		{
			Texture *pTexture = m_pTemplate->GetTexture();
			Color color = m_color * m_alpha;
			Vector2 center = pTexture->GetCenter();
			pSpriteBatch->Draw(pTexture, m_position, color, center, m_scale, m_rotation);
		}
	}

	float Particle::GetInterpolationValue()
	{
		if (m_lifeSeconds <= 0) return 0;
		if (m_lifeSeconds >= m_lifespan) return 1;

		return (m_lifeSeconds / m_lifespan);
	}
}
