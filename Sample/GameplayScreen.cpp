
#include "Sample.h"

namespace Sample
{
	// Removal Callback Function
	void GameplayScreenRemove(Screen *pScreen)
	{
		pScreen->GetScreenManager()->AddScreen(new MainMenuScreen());
	}


	GameplayScreen::GameplayScreen()
	{
		SetRemoveCallback(GameplayScreenRemove);
		SetLevel(new Level01());
	}
}