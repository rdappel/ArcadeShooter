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
	{
		m_pManager = pManager;
		m_pTemplate = pTemplate;
		m_output = 0;
		m_particlesPerSecond = 100;
		m_leftoverParticles = 0;
	}
	
	void Emitter::Update(const GameTime *pGameTime)
	{
		float newParticles = pGameTime->GetTimeElapsed() * m_particlesPerSecond;
		m_leftoverParticles += newParticles * m_output;

		while (m_leftoverParticles >= 1)
		{
			m_leftoverParticles -= 1;
			Particle *pParticle = m_pTemplate->GetInactiveParticle();
			if (pParticle)
			{
				pParticle->SetPosition(m_position);
				pParticle->Activate();
				m_pTemplate->InitializeParticle(pParticle);

				m_pManager->AddParticle(pParticle);
			}
		}
	}
}