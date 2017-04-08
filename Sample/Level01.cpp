
#include "Sample.h"

using ShooterLibrary::EnemyShip;

namespace Sample
{
	Level01::Level01()
	{
	}


	void Level01::LoadContent()
	{
		ResourceManager *pRes = GetGameplayScreen()->GetResourceManager();
		Texture *pTexture = pRes->Load<Texture>("Textures\\BioEnemySmall.png");
		BioEnemyShip::SetTexture(pTexture);

		for (int i = 0; i < 10; i++)
		{
			EnemyShip *pEnemyShip = new BioEnemyShip();
			pEnemyShip->Initialize(Vector2(100 * i + 200, -50), 5 * (i + 1));
			AddGameObject(pEnemyShip);
		}

		PowerUp::SetTexture(pRes->Load<Texture>("Textures\\PowerUp.png"));
		PowerUp::SetGlowTexture(pRes->Load<Texture>("Textures\\PowerUpGlow.png"));

		m_pSmokeTemplate = new SmokeTemplate<SmokeParticle>();
		m_pSmokeTemplate->SetTexture(pRes->Load<Texture>("Textures\\Particle.png"));
		m_pEmitter = new Emitter(GetParticleManager(), m_pSmokeTemplate);

		Level::LoadContent();
	}
	
	void Level01::HandleInput(InputState *pInputState)
	{
		m_pEmitter->SetPosition(pInputState->GetMousePosition().ToVector2());
	}

	void Level01::Update(const GameTime *pGameTime)
	{
		m_pEmitter->SetOutput(1);
		m_pEmitter->Update(pGameTime);

		Level::Update(pGameTime);
	}
}