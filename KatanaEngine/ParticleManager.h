
#pragma once

namespace KatanaEngine
{
	class ParticleManager
	{

	public:

		ParticleManager(Game *pGame);
		virtual ~ParticleManager() { }

		virtual void Update(const GameTime *pGameTime);

		virtual void Draw(const GameTime *pGameTime);

		virtual void AddParticle(Particle *pParticle) { m_particles.push_back(pParticle); }

		Game *GetGame() const { return m_pGame; }

		ResourceManager *GetResourceManager() const;

	private:

		Game *m_pGame;

		std::vector<Particle *> m_particles;
		std::vector<Particle *>::iterator m_it;

	};
}