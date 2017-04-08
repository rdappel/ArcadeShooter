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
	ParticleManager::ParticleManager(Game *pGame)
	{
		m_pGame = pGame;
		m_pSpriteBatch = pGame->GetSpriteBatch();
		Particle::SetSpriteBatch(m_pSpriteBatch);
	}

	ResourceManager *ParticleManager::GetResourceManager() const
	{
		return GetGame()->GetResourceManager();
	}

	void ParticleManager::Update(const GameTime *pGameTime)
	{
		m_it = m_particles.begin();
		for (; m_it != m_particles.end();)
		{
			Particle *pParticle = *m_it;

			if (pParticle->IsActive())
			{
				pParticle->Update(pGameTime);
				++m_it;
			}
			else
			{
				m_it = m_particles.erase(m_it);
			}
		}
	}

	void ParticleManager::Draw(const GameTime *pGameTime)
	{
		m_pSpriteBatch->Begin(SpriteSortMode::TEXTURE, BlendState::ADDITIVE);
		m_it = m_particles.begin();
		for (; m_it != m_particles.end(); ++m_it)
		{
			(*m_it)->Draw(pGameTime);
		}
		m_pSpriteBatch->End();
	}
}