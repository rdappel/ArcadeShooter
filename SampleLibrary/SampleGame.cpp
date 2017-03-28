
#include "SampleGame.h"
#include "MainMenuScreen.h"
#include "Projectile.h"


SampleGame::SampleGame()
{
	SetResourceDirectory("..\\SampleLibrary\\Content\\");

	Font::SetLoadSize(18, true);
	SetFrameCounterFont("Fonts\\Arialbd.ttf");
}

void SampleGame::LoadContent()
{
	GetScreenManager()->AddScreen(new MainMenuScreen());

	Projectile::SetTexture(GetResourceManager()->Load<Texture>("Textures\\Bullet.png"));

}