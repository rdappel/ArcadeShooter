
#include "SampleGameplayScreen.h"
#include "MainMenuScreen.h"

// Removal Function
void GameplayScreenRemove(Screen *pScreen)
{
	pScreen->GetScreenManager()->AddScreen(new MainMenuScreen);
}


SampleGameplayScreen::SampleGameplayScreen()
{
	OnRemove = GameplayScreenRemove;
}
