
#include "KatanaEngine.h"


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

void ParticleTemplate::SetTexture(Texture *pTexture)
{	
	m_pTexture = pTexture;
	m_textureOrigin = m_pTexture->GetSize() / 2;
	
}