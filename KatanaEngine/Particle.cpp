/* ---------------------------------------------------------------  /

	 ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗ 
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
        Katana Engine \/ © 2012 - Shuriken Studios LLC

/  --------------------------------------------------------------- */

#include "KatanaEngine.h"

namespace KatanaEngine
{

	SpriteBatch *Particle::s_pSpriteBatch = nullptr;


	Particle::Particle()
	{
		m_lifeSeconds = 0;
		m_color = Color::White;
		m_scale = Vector2::One;
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
			Texture *pTexture = m_pTemplate->GetTexture();
			Color color = m_color * m_alpha;
			Vector2 center = pTexture->GetCenter();
			s_pSpriteBatch->Draw(pTexture, m_position, color, center, m_scale, m_rotation);
		}
	}

	float Particle::GetInterpolationValue()
	{
		if (m_lifeSeconds <= 0) return 0;
		if (m_lifeSeconds >= m_lifespan) return 1;

		return (m_lifeSeconds / m_lifespan);
	}
}
