#pragma once

namespace KatanaEngine
{
	class RotatingParticle : public Particle
	{

	public:

		virtual ~RotatingParticle() { }

		virtual void SetRotationVelocity(float rotationVelocity) { m_rotationVelocity = rotationVelocity; }
		virtual float GetRotationVelocity() const { return m_rotationVelocity; }


	private:

		float m_rotationVelocity;

	};
}
