
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
	/** @brief A particle instance that rotates. */
	class RotatingParticle : public Particle
	{

	public:

		virtual ~RotatingParticle() { }

		/** @brief Sets the particle's rotational velocity.
			@param velocity The rotational velocity value. */
		virtual void SetRotationVelocity(const float velocity) { m_rotationVelocity = velocity; }

		/** @brief Gets the rotational velocity of the particle.
			@return Returns the particle's rotational velocity.  */
		virtual float GetRotationVelocity() const { return m_rotationVelocity; }


	private:

		float m_rotationVelocity;

	};
}
