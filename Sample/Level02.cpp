
/*   .oooooo..o       .o.       ooo        ooooo ooooooooo.   ooooo        oooooooooooo
	d8P'    `Y8      .888.      `88.       .888' `888   `Y88. `888'        `888'     `8
	Y88bo.          .8"888.      888b     d'888   888   .d88'  888          888
	 `"Y8888o.     .8' `888.     8 Y88. .P  888   888ooo88P'   888          888oooo8
		 `"Y88b   .88ooo8888.    8  `888'   888   888          888          888    "
	oo     .d8P  .8'     `888.   8    Y     888   888          888       o  888       o
	8""88888P'  o88o     o8888o o8o        o888o o888o        o888ooooood8 o888ooooood8

					        Sample © 2017 - Shuriken Studios LLC                          */

#include "Sample.h"

using ShooterLibrary::EnemyShip;

namespace Sample
{

	/** @brief Callback function for when the level is completed.
		@param pGameObject The game object that completed the level. Usually an enenmy
		that was destroyed. */
	void Level02Completed(GameObject *pGameObject)
	{
		Level *pLevel = (Level *)(pGameObject->GetCurrentLevel());
		pLevel->BeginCompletionCountdown();
	}


	Level02::Level02(GameplayScreen *pGameplayScreen)
		: Level(pGameplayScreen)
	{ }


	void Level02::LoadContent(ResourceManager *pResourceManager)
	{
		Animation *pAnimation;
		Texture *pTexture = pResourceManager->Load<Texture>("Textures\\BioMech.png");

		BioEnemyShip *pEnemyShip;

		int x[] = {
			800, 900, 700,					// wave 1
			800, 800,						// wave 2
			400, 600, 800, 1200, 1000, 800	// wave 3
		};
		
		int xIndex = 0;

		// wave 1 => small
		for (int i = 0; i < 3; i++)
		{
			pEnemyShip = new BioEnemyShip();
			pAnimation = pResourceManager->Load<Animation>("Animations\\BioMechSmall.anim");
			pAnimation->SetTexture(pTexture);
			pEnemyShip->SetAnimation(pAnimation);
			AddGameObject(pEnemyShip);
			pEnemyShip->Initialize(Vector2(x[xIndex], -50), 4.0 + 0.45 * i);
			xIndex++;
		}

		// wave 2 => med
		for (int i = 0; i < 2; i++)
		{
			pEnemyShip = new BioEnemyShip();
			pAnimation = pResourceManager->Load<Animation>("Animations\\BioMechMedium.anim");
			pAnimation->SetTexture(pTexture);
			pEnemyShip->SetAnimation(pAnimation);
			pEnemyShip->SetSpeed(140);
			pEnemyShip->SetMaxHitPoints(4);
			AddGameObject(pEnemyShip);
			pEnemyShip->Initialize(Vector2(x[xIndex], -50), 8.0 + 0.64 * i);
			xIndex++;
		}

		// wave 3 => small, med, large, small, med large
		for (int j = 0; j < 2; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				pEnemyShip = new BioEnemyShip();
				switch (i)
				{
				case 0:
					pAnimation = pResourceManager->Load<Animation>("Animations\\BioMechSmall.anim");
					break;
				case 1:
					pAnimation = pResourceManager->Load<Animation>("Animations\\BioMechMedium.anim");
					pEnemyShip->SetSpeed(140);
					pEnemyShip->SetMaxHitPoints(4);
					break;
				case 2:
					pAnimation = pResourceManager->Load<Animation>("Animations\\BioMechLarge.anim");
					pEnemyShip->SetSpeed(80);
					pEnemyShip->SetMaxHitPoints(10);
					break;
				}
				pAnimation->SetTexture(pTexture);
				pEnemyShip->SetAnimation(pAnimation);
				AddGameObject(pEnemyShip);
				pEnemyShip->Initialize(Vector2(x[xIndex], -50), 16 + 1.75 * i + j * 12);
				xIndex++;
			}
		}

		pEnemyShip->SetDeactivateCallback(Level02Completed);

		PowerUp::SetTexture(pResourceManager->Load<Texture>("Textures\\PowerUp.png"));
		PowerUp::SetGlowTexture(pResourceManager->Load<Texture>("Textures\\PowerUpGlow.png"));
		PowerUp::SetColorTexture(pResourceManager->Load<Texture>("Textures\\PowerUpColor.png"));
		
		Level::LoadContent(pResourceManager);
	}
}