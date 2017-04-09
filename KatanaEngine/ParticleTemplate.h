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

#pragma once

namespace KatanaEngine
{
	/** @brief Base class for particle templates which are used to control the updating of a corresponding particle type. */
	class ParticleTemplate
	{

		friend void Particle::Draw(const GameTime *pGameTime);
		friend void Particle::Update(const GameTime *pGameTime);


	public:

		ParticleTemplate(const bool poolExpands = true);
		virtual ~ParticleTemplate();

		virtual Particle *GetInactiveParticle() = 0;

		virtual void SetTexture(Texture *pTexture) { m_pTexture = pTexture; }

		virtual void InitializeParticle(Particle *pParticle);


	protected:

		virtual Texture *GetTexture() { return m_pTexture; }

		virtual void SetParticleLifespan(const float lifespan) { m_pParticleLifespan = lifespan; }

		virtual void UpdateParticle(Particle *pParticle, const GameTime *pGameTime) { }

		template <typename T>
		T *GetInactiveParticleOfType()
		{
			m_it = m_particles.begin();
			for (; m_it != m_particles.end(); ++m_it)
			{
				if (!(*m_it)->IsActive())
				{
					return static_cast<T *>(*m_it);
				}
			}

			if (m_poolExpands)
			{
				return GenerateParticles<T>();
			}

			return nullptr;
		}

		template <typename T>
		T *GenerateParticles(const int count = 1)
		{
			T *pT = nullptr;

			for (int i = 0; i < count; ++i)
			{
				pT = new T();
				Particle *pParticle = static_cast<Particle *>(pT);
				pParticle->SetTemplate(this);
				m_particles.push_back(pParticle);
			}

			return pT;
		}


	private:

		Texture *m_pTexture;

		float m_pParticleLifespan;

		bool m_poolExpands;

		std::vector<Particle *> m_particles;
		std::vector<Particle *>::iterator m_it;

	};
}