
#pragma once

namespace Sample
{
	class Level01 : public Level
	{

	public:

		Level01();
		virtual ~Level01() { }

		virtual void LoadContent();

		virtual void Update(const GameTime *pGameTime);

		virtual void HandleInput(InputState *pInput);


	private:

		SmokeTemplate<SmokeParticle> *m_pSmokeTemplate;
		Emitter *m_pEmitter;

	};
}