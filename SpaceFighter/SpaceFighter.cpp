
#include "KatanaEngine.h"
#include "SpaceFighter.h"
#include "MainMenuScreen.h"
#include "Projectile.h"

using namespace KatanaEngine;


SpaceFighter::SpaceFighter()
{
	SetScreenResolution(1600, 900);
	SetFullScreen(false);

	InitializeScreenManager();

	SetResourceDirectory("..\\SpaceFighter\\Content\\");

	// Font for displaying the frame rate
	Font::SetLoadSize(18, true);
	Font *pFont = GetResourceManager()->Load<Font>("Fonts\\Arialbd.ttf", false);
	SetFrameCounterFont(pFont);
}


void SpaceFighter::Draw(SpriteBatch *pSpriteBatch)
{
	Game::Draw(pSpriteBatch);

	DisplayFrameRate();
}

void SpaceFighter::LoadContent(ResourceManager *pResourceManager) 
{
	// Load static resources
	Projectile::SetTexture(pResourceManager->Load<Texture>("Textures\\Bullet.png"));


	GetScreenManager()->AddScreen(new MainMenuScreen());

	ResetGameTime();
}