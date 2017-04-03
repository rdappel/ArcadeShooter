
#include "Sample.h"

namespace Sample
{
	Game::Game()
	{
		SetResourceDirectory("..\\SampleLibrary\\Content\\");

		Font::SetLoadSize(18, true);
		SetFrameCounterFont("Fonts\\Arialbd.ttf");
	}

	void Game::LoadContent()
	{
		GetScreenManager()->AddScreen(new MainMenuScreen());

		Projectile::SetTexture(GetResourceManager()->Load<Texture>("Textures\\Bullet.png"));

	}
}