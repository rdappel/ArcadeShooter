
#include "Level01.h"
#include "BioEnemyShip.h"

Level01::Level01()
{
}


void Level01::LoadContent()
{
	ResourceManager *pResource = GetGameplayScreen()->GetResourceManager();
	Texture *pTexture = pResource->Load<Texture>("Textures\\BioEnemySmall.png");
	BioEnemyShip::SetTexture(pTexture);
	
	for (int i = 0; i < 10; i++)
	{
		EnemyShip *pEnemyShip = new BioEnemyShip();
		pEnemyShip->Initialize(Vector2(100 * i + 200, -50), 5 * (i + 1));
		AddGameObject(pEnemyShip);
	}
	
	//PowerUp::SetTexture(pResource->Load<Texture>("Textures\\PowerUp.png"));
	//PowerUp::SetGlowTexture(pResource->Load<Texture>("Textures\\PowerUpGlow.png"));

	SampleLevel::LoadContent();
}


void Level01::Update(const GameTime *pGameTime)
{
	/**
	if (m_POWERUPTEST > 0)
	{
		m_POWERUPTEST -= pGameTime->GetTimeElapsed();
		if (m_POWERUPTEST <= 0)
		{
			PowerUp *pPU = new PowerUp();
			pPU->Activate(Game::GetScreenCenter());
			AddGameObject(pPU);
		}
	}
	/**/

	SampleLevel::Update(pGameTime);
}