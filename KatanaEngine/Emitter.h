
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

#pragma once

namespace KatanaEngine
{

	/** @brief The source of output for a particle effect.  */
	class Emitter
	{

	public:

		/** @brief Instantiate a particle emitter object.
			@param pManager A pointer to the particle manager that will manage emitted particles. */
		Emitter(ParticleManager *pManager);

		/** @brief Instantiate a particle emitter object.
			@param pManager A pointer to the particle manager that will manage emitted particles.
			@param pTemplate A pointer to the template that the particles will use to update and
			for initialization.

			@overload */
		Emitter(ParticleManager *pManager, ParticleTemplate *pTemplate);

		/** @brief Instantiate a particle emitter object.
			@param pManager A pointer to the particle manager that will manage emitted particles.
			@param pTemplate A pointer to the template that the particles will use to update and
			for initialization.
			@param particlesPerSecond The number of particles that will be emitted per second.

			@overload */
		Emitter(ParticleManager *pManager, ParticleTemplate *pTemplate, const int particlesPerSecond);

		virtual ~Emitter() { }

		/** @brief Called when the game has determined that game logic needs
			to be processed.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime);

		/** @brief Sets the output percentage for the emitter.
			@param output The value for the output. Zero is off, and one is full output.
			@remark An output greater than one will work, and will produce an output beyond 100%.
			Doing this can be usefull for testing but is not recommended for actual gameplay. */
		virtual void SetOutput(const float output) { m_output = output; }

		/** @brief Sets the position of the emitter.
			@param position The new position.
			@remark By default, the position of particles emitted will be interpolated between the
			emitter's current and previous position. To cancel this effect, you can simply call
			SetPosition() twice with the same position value. */
		virtual void SetPosition(const Vector2 position);

		/** @brief Sets the template that the particles will use to update and for initialization.
			@param pTemplate A pointer to the template. */
		virtual void SetTemplate(ParticleTemplate *pTemplate) { m_pTemplate = pTemplate; }

		/** @brief Sets the number of particles that will be emitted per second, when the output
			is set to one.
			@param particlesPerSecond The number of particles per second to emit.
			@see SetOutput() */
		virtual void SetParticlesPerSecond(float particlesPerSecond) { m_particlesPerSecond = particlesPerSecond; }


	private:

		float m_output;

		float m_leftoverParticles;

		int m_particlesPerSecond;

		ParticleManager *m_pManager;

		ParticleTemplate *m_pTemplate;

		Vector2 m_position;
		Vector2 m_previousPosition;

	};
}