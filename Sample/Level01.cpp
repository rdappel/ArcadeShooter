
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
	void Level01Completed(GameObject *pGameObject)
	{
		Level *pLevel = (Level *)(pGameObject->GetCurrentLevel());
		pLevel->BeginCompletionCountdown();
	}


	Level01::Level01(GameplayScreen *pGameplayScreen)
		: Level(pGameplayScreen)
	{ }


	void Level01::LoadContent(ResourceManager *pResourceManager)
	{
		Animation *pAnimation;
		Texture *pTexture = pResourceManager->Load<Texture>("Textures\\BioMech.png");

		BioEnemyShip *pEnemyShip;

		// Enemies
		for (int i = 0; i < 5; i++)
		{
			pEnemyShip = new BioEnemyShip();
			pAnimation = pResourceManager->Load<Animation>("Animations\\BioMechSmall.anim");
			pAnimation->SetTexture(pTexture);
			pEnemyShip->SetAnimation(pAnimation);
			AddGameObject(pEnemyShip);
			pEnemyShip->Initialize(Vector2(600, -50), 4.0 + 0.45 * i);
		}

		for (int i = 0; i < 5; i++)
		{
			pEnemyShip = new BioEnemyShip();
			pAnimation = pResourceManager->Load<Animation>("Animations\\BioMechSmall.anim");
			pAnimation->SetTexture(pTexture);
			pEnemyShip->SetAnimation(pAnimation);
			AddGameObject(pEnemyShip);
			pEnemyShip->Initialize(Vector2(1000, -50), 10.0 + 0.45 * i);
		}

		for (int i = 0; i < 7; i++)
		{
			pEnemyShip = new BioEnemyShip();
			pAnimation = pResourceManager->Load<Animation>("Animations\\BioMechSmall.anim");
			pAnimation->SetTexture(pTexture);
			pEnemyShip->SetAnimation(pAnimation);
			AddGameObject(pEnemyShip);
			pEnemyShip->Initialize(Vector2(400, -50), 16.0 + 0.65 * i);
		}

		for (int i = 0; i < 7; i++)
		{
			pEnemyShip = new BioEnemyShip();
			pAnimation = pResourceManager->Load<Animation>("Animations\\BioMechSmall.anim");
			pAnimation->SetTexture(pTexture);
			pEnemyShip->SetAnimation(pAnimation);
			AddGameObject(pEnemyShip);
			pEnemyShip->Initialize(Vector2(1200, -50), 22.0 + 0.65 * i);
		}

		for (int i = 0; i < 3; i++)
		{
			pEnemyShip = new BioEnemyShip();
			pAnimation = pResourceManager->Load<Animation>("Animations\\BioMechMedium.anim");
			pAnimation->SetTexture(pTexture);
			pEnemyShip->SetAnimation(pAnimation);
			pEnemyShip->SetSpeed(140);
			pEnemyShip->SetMaxHitPoints(6);
			AddGameObject(pEnemyShip);
			pEnemyShip->Initialize(Vector2(800, -50), 28.0 + 0.54 * i);
		}

		pEnemyShip->SetDeactivateCallback(Level01Completed);

		PowerUp::SetTexture(pResourceManager->Load<Texture>("Textures\\PowerUp.png"));
		PowerUp::SetGlowTexture(pResourceManager->Load<Texture>("Textures\\PowerUpGlow.png"));
		PowerUp::SetColorTexture(pResourceManager->Load<Texture>("Textures\\PowerUpColor.png"));
		
		Level::LoadContent(pResourceManager);
	}
}