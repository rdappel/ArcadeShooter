#pragma once


namespace Sample
{
	template <typename T>
	class SmokeTemplate : public ParticleTemplate
	{

	public:

		SmokeTemplate()
		{
			GenerateParticles<T>(100); 
			SetParticleLifespan(1);
		}

		virtual ~SmokeTemplate() { }

		virtual void InitializeParticle(Particle *pParticle)
		{
			RotatingParticle *pT = static_cast<RotatingParticle *>(pParticle);
			assert(pT && "Type of template T is not compatible.");

			ParticleTemplate::InitializeParticle(pT);

			pT->SetScale(Vector2::One * 0.1f);
			pT->SetAlpha(1);

			pT->SetRotation(Math::GetRandomFloat() * Math::PI * 2);
			pT->SetRotationVelocity(Math::GetRandomFloat() * 0.2f - 0.1f);

			pT->SetPosition(pT->GetPosition() + Vector2::GetRandom(true) * 2);
		}

		virtual void UpdateParticle(Particle *pParticle, const GameTime *pGameTime)
		{
			RotatingParticle *pT = static_cast<RotatingParticle *>(pParticle);
			assert(pT && "Type of template T is not compatible.");

			float value = pT->GetInterpolationValue();
			float scale = (1 - value) * 0.25f + 0.1f;
			pT->SetScale(Vector2::One * scale);
			pT->SetAlpha(value * 0.25f);

			float rotation = pT->GetRotation() + pT->GetRotationVelocity();

			pT->SetRotation(rotation);
		}

		virtual Particle *GetInactiveParticle()
		{
			return GetInactiveParticleOfType<T>();
		}
	};
}