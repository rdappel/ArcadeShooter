
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

	void Game::LoadContent()
	{
		GetScreenManager()->AddScreen(new MainMenuScreen());

		Projectile::SetTexture(GetResourceManager()->Load<Texture>("Textures\\Bullet.png"));

	}
}