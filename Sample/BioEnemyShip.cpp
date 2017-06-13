
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
			m_pAnimation->Update(pGameTime);

			float x = sin(pGameTime->GetTotalTime() * Math::PI  + GetIndex()) * GetSpeed() / 60;
			if (GetSpeed() < 200) x *= 1.6f; // todo: remove this
			TranslatePosition(x, GetSpeed() * pGameTime->GetTimeElapsed() * 1.2f);

			if (GetPosition().Y > Game::GetScreenHeight() + 50) Deactivate();
		}

		EnemyShip::Update(pGameTime);
	}


	void BioEnemyShip::Draw(SpriteBatch *pSpriteBatch)
	{
		if (IsActive())
		{
			Region frame = *(m_pAnimation->GetCurrentFrame());
			frame.X = 0;
			frame.Y = 0;
			pSpriteBatch->Draw(m_pAnimation, GetPosition(), Color::White, frame.GetCenter(), Vector2::ONE, Math::PI, 1);
		}
	}


	void BioEnemyShip::Hit(const float damage)
	{
		EnemyShip::Hit(damage);

		if (!IsActive())
		{
			Level *pLevel = (Level *)GetCurrentLevel();

			if (GetIndex() == 5 || GetIndex() == 13)
			{
				pLevel->SpawnPowerUp(GetPosition(), PowerUpType::FireRate);
			}
			if (GetIndex() == 8 || GetIndex() == 11)
			{
				pLevel->SpawnPowerUp(GetPosition(), PowerUpType::MissileLauncher);
			}
			
			pLevel->SpawnExplosion(GetPosition(), 0.75f);
		}
	}
}