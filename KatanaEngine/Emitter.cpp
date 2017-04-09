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
	Emitter::Emitter(ParticleManager *pManager)
		: Emitter (pManager, nullptr) { }

	Emitter::Emitter(ParticleManager *pManager, ParticleTemplate *pTemplate)
		: Emitter (pManager, pTemplate, 100){ }

	Emitter::Emitter(ParticleManager *pManager, ParticleTemplate *pTemplate, const int particlesPerSecond)
	{
		m_pManager = pManager;
		m_output = 1;
		m_leftoverParticles = 0;

		SetTemplate(pTemplate);
		SetParticlesPerSecond(particlesPerSecond);
	}
	
	void Emitter::Update(const GameTime *pGameTime)
	{
		float newParticles = pGameTime->GetTimeElapsed() * m_particlesPerSecond;
		m_leftoverParticles += newParticles * m_output;
		
		int particlesToDraw = (int)m_leftoverParticles;
		m_leftoverParticles -= particlesToDraw;

		for (int i = 0; i < particlesToDraw; i++)
		{
			Particle *pParticle = m_pTemplate->GetInactiveParticle();
			if (pParticle)
			{
				float value = (float)i + 1 / (float)particlesToDraw;
				Vector2 position = Vector2::Lerp(m_previousPosition, m_position, value);
				pParticle->SetPosition(position);
				m_pTemplate->InitializeParticle(pParticle);

				m_pManager->AddParticle(pParticle);
			}
		}
	}

	void Emitter::SetPosition(const Vector2 position)
	{
		m_previousPosition = m_position;
		m_position = position;
	}
}