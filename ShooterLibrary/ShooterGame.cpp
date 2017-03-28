#include "ShooterLibrary.h"
#include "ShooterGame.h"


ShooterGame::ShooterGame()
{
	SetScreenResolution(1600, 900);
	SetFullScreen(false);
	InitializeScreenManager();
}


void ShooterGame::Draw(const GameTime *pGameTime)
{
	DisplayFrameRate();

	Game::Draw(pGameTime);
}