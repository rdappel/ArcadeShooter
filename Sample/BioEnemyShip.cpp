
/*   .oooooo..o       .o.       ooo        ooooo ooooooooo.   ooooo        oooooooooooo
	d8P'    `Y8      .888.      `88.       .888' `888   `Y88. `888'        `888'     `8
	Y88bo.          .8"888.      888b     d'888   888   .d88'  888          888
	 `"Y8888o.     .8' `888.     8 Y88. .P  888   888ooo88P'   888          888oooo8
		 `"Y88b   .88ooo8888.    8  `888'   888   888          888          888    "
	oo     .d8P  .8'     `888.   8    Y     888   888          888       o  888       o
	8""88888P'  o88o     o8888o o8o        o888o o888o        o888ooooood8 o888ooooood8

					        Sample © 2017 - Shuriken Studios LLC                          */

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

	void BioEnemyShip::Draw(SpriteBatch *pSpriteBatch)
	{
		if (IsActive())
		{
			pSpriteBatch->Draw(s_pTexture, GetPosition(), Color::White, s_pTexture->GetCenter());
		}
	}


	void BioEnemyShip::Hit(const float damage)
	{
		EnemyShip::Hit(damage);

		if (!IsActive())
		{
			Level *pLevel = static_cast<Level *>(GetCurrentLevel());

			if (GetIndex() == 3 || GetIndex() == 7)
			{
				pLevel->SpawnPowerUp(GetPosition());
			}
			
			pLevel->SpawnExplosion(GetPosition(), 0.75f);
		}
	}
}