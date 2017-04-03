
#include "GuardianFinalZero.h"

namespace GuardianFinalZero
{
	Game::Game()
	{
		SetResourceDirectory("..\\GuardianFinalZero\\Content\\");

		Font::SetLoadSize(18, true);
		SetFrameCounterFont("Fonts\\Arialbd.ttf");
	}

	void Game::LoadContent()
	{
		GetScreenManager()->AddScreen(new MainMenuScreen());

		Texture *pTexture = nullptr;
		pTexture = GetResourceManager()->Load<Texture>("Textures\\Projectile.png");
		ShooterLibrary::Projectile::SetTexture(pTexture);
	}
}