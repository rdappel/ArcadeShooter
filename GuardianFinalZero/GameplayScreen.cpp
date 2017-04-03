
#include "GuardianFinalZero.h"

namespace GuardianFinalZero
{
	// Removal Function
	void GameplayScreenRemove(Screen *pScreen)
	{
		pScreen->GetScreenManager()->AddScreen(new MainMenuScreen());
	}


	GameplayScreen::GameplayScreen(Level *pLevel)
	{
		SetLevel(pLevel);

		OnRemove = GameplayScreenRemove;
	}
}