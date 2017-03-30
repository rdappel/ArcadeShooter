
#include "KatanaEngine.h"

Emitter::Emitter(ParticleManager *pManager)
{
	m_pManager = pManager;
	Construct();
}

Emitter::Emitter(ParticleManager *pManager, ParticleTemplate *pTemplate)
{
	m_pManager = pManager;
	m_pTemplate = pTemplate;
	Construct();
}

void Emitter::Construct()
{
	m_output = 0;
	m_particlesPerSecond = 100;
	m_leftoverParticles = 0;
}

void Emitter::Update(const GameTime *pGameTime)
{
	m_leftoverParticles += pGameTime->GetTimeElapsed() * m_particlesPerSecond;

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