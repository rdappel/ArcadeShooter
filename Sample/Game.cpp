
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
	Game::Game()
	{
		SetResourceDirectory("..\\Sample\\Content\\");

		Font::SetLoadSize(18, true);

		Font *pFont = GetResourceManager()->Load<Font>("Fonts\\Arialbd.ttf", false);
		SetFrameCounterFont(pFont);
	}

	void Game::LoadContent(ResourceManager *pResourceManager)
	{
		LoadStaticResources(pResourceManager);

		GetScreenManager()->AddScreen(new MainMenuScreen());

		ResetGameTime();
	}

	void Game::LoadStaticResources(ResourceManager *pResourceManager)
	{
		Texture *pTexture;
		Animation *pAnimation;

		pTexture = pResourceManager->Load<Texture>("Textures\\Bullet02.png");
		Projectile::SetTexture(pTexture);

		pAnimation = pResourceManager->Load<Animation>("Animations\\Missile.anim");
		pAnimation->SetTexture(pResourceManager->Load<Texture>("Textures\\Missile01.png"));


		pTexture = pResourceManager->Load<Texture>("Textures\\GameOver.png");
		LevelOverScreen::SetGameOverTexture(pTexture);
		pTexture = pResourceManager->Load<Texture>("Textures\\MissionComplete.png");
		LevelOverScreen::SetLevelCompleteTexture(pTexture);

		pAnimation = pResourceManager->Load<Animation>("Animations\\Explosion.anim");
		pAnimation->SetTexture(pResourceManager->Load<Texture>("Textures\\Explosion01.png"));
		pAnimation->Stop();
	}
}