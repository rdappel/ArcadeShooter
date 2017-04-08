#pragma once


namespace Sample
{
	class SmokeParticle : public Particle
	{

	public:

		SmokeParticle() { }
		virtual ~SmokeParticle() { }

		virtual void SetRotationVelocity(float rotationVelocity) { m_rotationVelocity = rotationVelocity; }
		virtual float GetRotationVelocity() const { return m_rotationVelocity; }

	private:

		float m_rotationVelocity;

	};

	template <typename T>
	class SmokeTemplate : public ParticleTemplate { };

	template<>
	class SmokeTemplate<SmokeParticle> : public ParticleTemplate
	{

	public:

		SmokeTemplate() { GenerateParticles<SmokeParticle>(100); }
		virtual ~SmokeTemplate() { }

		virtual void InitializeParticle(Particle *pParticle)
		{
			ParticleTemplate::InitializeParticle(pParticle);

			SmokeParticle *pT = static_cast<SmokeParticle *>(pParticle);
			if (pT)
			{
				pT->SetScale(Vector2::One * 0.1f);
				pT->SetAlpha(1);

				pT->SetRotation(GetRandomFloat() * Math::PI * 2);
				pT->SetRotationVelocity(GetRandomFloat() * 0.2f - 0.1f);

				float x = GetRandomFloat() * 6 - 3;
				float y = GetRandomFloat() * 6 - 3;

				pT->SetPosition(pT->GetPosition() + Vector2(x, y));
			}
		}

		virtual float GetRandomFloat()
		{
			return (rand() / (float)RAND_MAX);
		}

		virtual void UpdateParticle(Particle *pParticle, const GameTime *pGameTime)
		{
			SmokeParticle *pT = static_cast<SmokeParticle *>(pParticle);
			if (pT)
			{
				float value = pT->GetInterpolationValue();
				float scale = (1 - value) * 0.25f + 0.1f;
				pT->SetScale(Vector2::One * scale);
				pT->SetAlpha(value * 0.25f);

				float rotation = pT->GetRotation() + pT->GetRotationVelocity();

				pT->SetRotation(rotation);
			}
		}

		virtual Particle *GetInactiveParticle()
		{
			return GetInactiveParticleOfType<SmokeParticle>();
		}
	};
}