
/*   .oooooo..o       .o.       ooo        ooooo ooooooooo.   ooooo        oooooooooooo
	d8P'    `Y8      .888.      `88.       .888' `888   `Y88. `888'        `888'     `8
	Y88bo.          .8"888.      888b     d'888   888   .d88'  888          888
	 `"Y8888o.     .8' `888.     8 Y88. .P  888   888ooo88P'   888          888oooo8
		 `"Y88b   .88ooo8888.    8  `888'   888   888          888          888    "
	oo     .d8P  .8'     `888.   8    Y     888   888          888       o  888       o
	8""88888P'  o88o     o8888o o8o        o888o o888o        o888ooooood8 o888ooooood8

					        Sample © 2017 - Shuriken Studios LLC                          */

#pragma once

namespace Sample
{
	template <typename T>
	class SmokeTemplate : public ParticleTemplate
	{

	public:

		int frames;

		SmokeTemplate()
		{
			GenerateParticles<T>(1); 
			SetParticleLifespan(1);
			m_poolExpands = false;
		}

		virtual ~SmokeTemplate() { }

		virtual void InitializeParticle(Particle *pParticle)
		{
			RotatingParticle *pT = static_cast<RotatingParticle *>(pParticle);
			assert(pT && "Type of template T is not compatible.");

			ParticleTemplate::InitializeParticle(pT);

			pT->SetScale(Vector2::One * 0.1f);
			pT->SetAlpha(0.25f);

			pT->SetRotation(Math::GetRandomFloat() * Math::PI * 2);
			pT->SetRotationVelocity(Math::GetRandomFloat() * 0.2f - 0.1f);

			pT->SetPosition(pT->GetPosition() + Vector2::GetRandom(true) * 2);

			frames = 0;
		}

		virtual void UpdateParticle(Particle *pParticle, const GameTime *pGameTime)
		{
			RotatingParticle *pT = static_cast<RotatingParticle *>(pParticle);
			assert(pT && "Type of template T is not compatible.");

			float value = pT->GetInterpolationValue();
			float scale = (1 - value) * 0.25f + 0.1f;
			pT->SetScale(Vector2::One * scale);
			pT->SetAlpha(value * 0.25f);

			//std::cout << "INTERP: \t" << value << "\tFR: " << frames++ << "\tTT: " << pGameTime->GetTotalTime() << std::endl ;

			float rotation = pT->GetRotation() + pT->GetRotationVelocity();

			pT->SetRotation(rotation);
		}

		virtual Particle *GetInactiveParticle()
		{
			return GetInactiveParticleOfType<T>();
		}
	};
}