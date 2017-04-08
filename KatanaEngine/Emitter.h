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

	/** @brief The source of output for a particle effect.  */
	class Emitter
	{

	public:

		Emitter(ParticleManager *pManager);
		Emitter(ParticleManager *pManager, ParticleTemplate *pTemplate);
		virtual ~Emitter() { }

		virtual void Update(const GameTime *pGameTime);

		virtual void SetOutput(const float output) { m_output = output; }

		virtual void SetPosition(const Vector2 position) { m_position = position; }

		virtual void SetTemplate(ParticleTemplate *pTemplate) { m_pTemplate = pTemplate; }


	private:

		float m_output;

		float m_leftoverParticles;

		int m_particlesPerSecond;

		ParticleManager *m_pManager;

		ParticleTemplate *m_pTemplate;

		Vector2 m_position;
	};
}