
#include "Sample.h"

namespace Sample
{
	// Removal Function
	void GameplayScreenRemove(Screen *pScreen)
	{
		pScreen->GetScreenManager()->AddScreen(new MainMenuScreen());
	}


	GameplayScreen::GameplayScreen()
	{
		OnRemove = GameplayScreenRemove;

		SetLevel(new Level01());
	}
}