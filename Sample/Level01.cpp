
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
	Level01::Level01()
	{
	}


	void Level01::LoadContent(ResourceManager *pResourceManager)
	{
		Texture *pTexture = pResourceManager->Load<Texture>("Textures\\BioEnemySmall.png");
		BioEnemyShip::SetTexture(pTexture);

		for (int i = 0; i < 10; i++)
		{
			EnemyShip *pEnemyShip = new BioEnemyShip();
			pEnemyShip->Initialize(Vector2(100 * i + 200, -50), 5 * (i + 1));
			AddGameObject(pEnemyShip);
		}

		PowerUp::SetTexture(pResourceManager->Load<Texture>("Textures\\PowerUp.png"));
		PowerUp::SetGlowTexture(pResourceManager->Load<Texture>("Textures\\PowerUpGlow.png"));
		
		Level::LoadContent(pResourceManager);
	}
}