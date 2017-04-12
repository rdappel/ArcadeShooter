
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
		virtual ~Particle() { }

		virtual float GetInterpolationValue();

		virtual void SetLifespan(const float lifespan) { m_lifespan = lifespan; }

		virtual void SetTemplate(ParticleTemplate *pTemplate) { m_pTemplate = pTemplate; }

		virtual void SetPosition(const Vector2 position) { m_position = position; }
		virtual Vector2 &GetPosition() { return m_position; }

		virtual void SetAlpha(const float alpha) { m_alpha = alpha; }
		virtual float GetAlpha() const { return m_alpha; }

		virtual void SetScale(const Vector2 scale) { m_scale = scale; }
		virtual Vector2 GetScale() const { return m_scale; }

		virtual void SetRotation(const float rotation) { m_rotation = rotation; }
		virtual float GetRotation() const { return m_rotation; }

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