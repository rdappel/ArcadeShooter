
#include "GuardianFinalZero.h"

namespace GuardianFinalZero
{
	Game::Game()
	{
		SetResourceDirectory("..\\GuardianFinalZero\\Content\\");

		Font::SetLoadSize(18, true);

		Font *pFont = GetResourceManager()->Load<Font>("Fonts\\Arialbd.ttf", false);
		SetFrameCounterFont(pFont);
	}

	void Game::LoadContent()
	{
		GetScreenManager()->AddScreen(new MainMenuScreen());

		Texture *pTexture = nullptr;
		pTexture = GetResourceManager()->Load<Texture>("Textures\\Projectile.png");
		ShooterLibrary::Projectile::SetTexture(pTexture);
	}
}