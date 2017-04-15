
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
	class ParticleTemplate;

	/** @brief A single component of a particle system.  */
	class Particle
	{

		friend class ParticleTemplate;
		friend class ParticleManager;
		friend class Emitter;

	public:

		Particle();
		virtual ~Particle() { s_count--; }

		/** @brief A value representing the percentage of the particle's lifespan.
			@return Returns the interpolated lifespan value. */
		virtual float GetInterpolationValue();


		/** @brief Sets the lifespan of the particle in seconds.
			@param seconds The time in seconds that the particle will live. */
		virtual void SetLifespan(const float seconds) { m_lifespan = seconds; }

		/** @brief Sets template responsible for updating the particle.
			@param pTemplate The template that updates and initializes the particle. */
		virtual void SetTemplate(ParticleTemplate *pTemplate) { m_pTemplate = pTemplate; }

		/** @brief Sets the particle's position.
			@param position The particle's new position. */
		virtual void SetPosition(const Vector2 position) { m_position = position; }

		/** @brief Gets the position of the particle.
			@return Returns the particle's position.  */
		virtual Vector2 &GetPosition() { return m_position; }

		/** @brief Sets the particle's alpha value (opacity).
			@param alpha The alpha value. */
		virtual void SetAlpha(const float alpha) { m_alpha = alpha; }

		/** @brief Gets the alpha value (opacity) of the particle.
			@return Returns the particle's alpha value.  */
		virtual float GetAlpha() const { return m_alpha; }

		/** @brief Sets the particle's scale.
			@param scale The scale value. */
		virtual void SetScale(const Vector2 scale) { m_scale = scale; }

		/** @brief Gets the scale of the particle.
			@return Returns the particle's scale.  */
		virtual Vector2 GetScale() const { return m_scale; }

		/** @brief Sets the particle's rotation.
			@param rotation The rotation value. */
		virtual void SetRotation(const float rotation) { m_rotation = rotation; }

		/** @brief Gets the rotation of the particle.
			@return Returns the particle's rotation.  */
		virtual float GetRotation() const { return m_rotation; }

		/** @brief Gets the index of the particle.
			@return Returns the particle's index.  */
		virtual uint32_t GetIndex() const { return m_index; }


	private:

		static uint32_t s_count;

		uint32_t m_index;

		ParticleTemplate *m_pTemplate;

		float m_lifespan;
		float m_lifeSeconds;

		Vector2 m_position;
		Color m_color;

		float m_alpha;
		float m_rotation;
		Vector2 m_scale;

		virtual void Activate() { m_lifeSeconds = m_lifespan; }

		virtual bool IsActive() const { return m_lifeSeconds > 0; }

		virtual void Update(const GameTime *pGameTime);

		virtual void Draw(SpriteBatch *pSpriteBatch);

	};
}