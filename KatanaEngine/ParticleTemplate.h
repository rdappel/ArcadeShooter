
/*	 ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗ 
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
        Katana Engine \/ © 2012 - Shuriken Studios LLC              */

#pragma once

namespace KatanaEngine
{
	/** @brief Base class for particle templates which are used to control the updating of a corresponding particle type. */
	class ParticleTemplate
	{

		friend void Particle::Update(const GameTime *pGameTime);
		friend void Particle::Draw(SpriteBatch *pSpriteBatch);
		friend void Emitter::Update(const GameTime *pGameTime);

	public:


		/** @brief Instantiates a new particle template object.
			@param poolExpands Allows the pool to dynamically create
			particles when it's empty. */
		ParticleTemplate(const bool poolExpands = true);

		virtual ~ParticleTemplate();

		/** @brief Get the next available particle.
			@return Returns a pointer to the particle. */
		virtual Particle *GetInactiveParticle() = 0;

		/** @brief Sets the texture.
			@param pTexture The texture to use. */
		virtual void SetTexture(Texture *pTexture) { m_pTexture = pTexture; }


	protected:

		/** @brief Gets the texture to render.
			@return Returns a ponter to the texture. */
		virtual Texture *GetTexture() { return m_pTexture; }

		/** @brief Sets the lifespan of the particle in seconds.
			@param seconds The time in seconds that the particle will live. */
		virtual void SetParticleLifespan(const float seconds) { m_pParticleLifespan = seconds; }

		/** @brief Initializes a particle.
			@param pParticle The particle to initialize. */
		virtual void InitializeParticle(Particle *pParticle);

		/** @brief Updates a particle.
			@param pParticle The particle to update.
			@param pGameTime Timing values including time since last update. */
		virtual void UpdateParticle(Particle *pParticle, const GameTime *pGameTime) { }

		/** @brief Gets a particle of a specific type.
			@return Returns a pointer to an inactive particle matching the template type. */
		template <typename T>
		T *GetInactiveParticleOfType()
		{
			m_it = m_particles.begin();
			for (; m_it != m_particles.end(); ++m_it)
			{
				bool active = (*m_it)->IsActive();
				if (!active) return (T *)(*m_it);
			}

			if (m_poolExpands) return GenerateParticles<T>();

			return nullptr;
		}

		/** @brief Generates particles of a specific type.
			@return Returns a pointer to an inactive particle matching the template type. */
		template <typename T>
		T *GenerateParticles(const int count = 1)
		{
			T *pT = nullptr;

			for (int i = 0; i < count; ++i)
			{
				pT = new T();
				Particle *pParticle = (Particle *)pT;
				pParticle->SetTemplate(this);
				m_particles.push_back(pParticle);
			}

			return pT;
		}


	private:

		Texture *m_pTexture;

		float m_pParticleLifespan;

		std::vector<Particle *> m_particles;
		std::vector<Particle *>::iterator m_it;

		bool m_poolExpands;

	};
}