
/*
     ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗ 
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
        Katana Engine \/ © 2012 - Shuriken Studios LLC
			    http://www.shurikenstudios.com
*/

#include "KatanaEngine.h"

namespace KatanaEngine
{
	ParticleTemplate::ParticleTemplate(const bool poolExpands)
	{
		m_pParticleLifespan = 1;
		m_poolExpands = poolExpands;
	}

	ParticleTemplate::~ParticleTemplate()
	{
		m_it = m_particles.begin();
		for (; m_it != m_particles.end(); ++m_it) delete (*m_it);
	}

	void ParticleTemplate::InitializeParticle(Particle *pParticle)
	{
		pParticle->SetLifespan(m_pParticleLifespan);
		pParticle->Activate();
	}
}