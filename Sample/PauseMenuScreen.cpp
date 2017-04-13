
/*   .oooooo..o       .o.       ooo        ooooo ooooooooo.   ooooo        oooooooooooo
	d8P'    `Y8      .888.      `88.       .888' `888   `Y88. `888'        `888'     `8
	Y88bo.          .8"888.      888b     d'888   888   .d88'  888          888
	 `"Y8888o.     .8' `888.     8 Y88. .P  888   888ooo88P'   888          888oooo8
		 `"Y88b   .88ooo8888.    8  `888'   888   888          888          888    "
	oo     .d8P  .8'     `888.   8    Y     888   888          888       o  888       o
	8""88888P'  o88o     o8888o o8o        o888o o888o        o888ooooood8 o888ooooood8

					        Sample © 2017 - Shuriken Studios LLC                          */

#include "Sample.h"

namespace Sample
{

	/** @brief Callback function for when the pause menu is removed from
		the screen manager.
		@param pScreen The screen that is about to be removed. */
	void PauseMenuScreenRemove(Screen *pScreen)
	{
		PauseMenuScreen *pPauseMenuScreen = static_cast<PauseMenuScreen *>(pScreen);
		pPauseMenuScreen->GetGameplayScreen()->Exit();
	}

	/** @brief Callback function for when the resume item is selected.
		@param pMenuScreen The menu screen that contains the menu item. */
	void ResumeSelect(MenuScreen *pMenuScreen)
	{
		pMenuScreen->Exit();
	}

	/** @brief Callback function for when the quit item is selected.
		@param pMenuScreen The menu screen that contains the menu item. */
	void QuitSelect(MenuScreen *pMenuScreen)
	{
		PauseMenuScreen *pPauseMenuScreen = static_cast<PauseMenuScreen *>(pMenuScreen);
		//pPauseMenuScreen->SetRemoveCallback((KatanaEngine::OnRemove)PauseMenuScreenRemove);
		pPauseMenuScreen->GetGameplayScreen()->Exit();
		pPauseMenuScreen->Exit();
	}
	

	PauseMenuScreen::PauseMenuScreen(GameplayScreen *pGameplayScreen)
	{
		m_pGameplayScreen = pGameplayScreen;

		SetTransitionOutTime(pGameplayScreen->GetTransitionOutTime());
		SetPassthroughFlags(true);

		Show();
	}


	void PauseMenuScreen::LoadContent(ResourceManager *pResourceManager)
	{
		MenuScreen::LoadContent(pResourceManager);

		const int MENU_ITEM_COUNT = 2;
		std::string items[MENU_ITEM_COUNT] = { "Resume", "Quit" };
		SetDisplayCount(MENU_ITEM_COUNT);

		AddMenuItem(new MenuItem(items[0]));
		AddMenuItem(new MenuItem(items[1]));

		GetMenuItem(0)->SetSelectCallback((KatanaEngine::OnSelect)ResumeSelect);
		GetMenuItem(1)->SetSelectCallback((KatanaEngine::OnSelect)QuitSelect);
	}
}
