
#include "Sample.h"

namespace Sample
{
	Texture *BioEnemyShip::s_pTexture = nullptr;

	BioEnemyShip::BioEnemyShip()
	{
		SetSpeed(250);
		SetMaxHitPoints(1);
		SetCollisionRadius(20);
	}

	void BioEnemyShip::Update(const GameTime *pGameTime)
	{
		if (IsActive())
		{
			float x = sin(pGameTime->GetTotalTime() * Math::PI) * GetSpeed() / 60;
			TranslatePosition(x, GetSpeed() * pGameTime->GetTimeElapsed());

			if (GetPosition().Y > Game::GetScreenHeight() + 50) Deactivate();
		}

		EnemyShip::Update(pGameTime);
	}

	void BioEnemyShip::Draw(const GameTime *pGameTime)
	{
		if (IsActive())
		{
			GetSpriteBatch()->Draw(s_pTexture, GetPosition(), Color::White, s_pTexture->GetCenter());
		}
	}
}