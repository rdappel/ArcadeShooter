
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
	
	#pragma region Callback Functions
	
	/** @brief Callback function for when a level is selected.
		@param pMenuScreen The menu screen that contains the menu item. */
	void LevelSelect(MenuScreen *pMenuScreen)
	{
		LevelSelectMenu *pLevelSelectMenu = (LevelSelectMenu *)pMenuScreen;
		int levelIndex = pLevelSelectMenu->GetLevelIndex();
		pMenuScreen->GetScreenManager()->AddScreen(new GameplayScreen(levelIndex));
		pMenuScreen->Exit();
	}

	#pragma endregion


	LevelSelectMenu::LevelSelectMenu()
	{
		Show();
	}

	void LevelSelectMenu::LoadContent(ResourceManager *pResourceManager)
	{
		MenuScreen::LoadContent(pResourceManager);
		Vector2 position = Game::GetScreenCenter() - Vector2::UnitY * 160;
		SetMenuPosition(position);

		const int MENU_ITEM_COUNT = 3;
		SetDisplayCount(MENU_ITEM_COUNT);

		int i = 0;
		for (i = 0; i < MENU_ITEM_COUNT - 1; i++)
		{
			std::stringstream ss;
			ss << "Level " << (i + 1);
			AddMenuItem(new MenuItem(ss.str()));
			GetMenuItem(i)->SetSelectCallback((KatanaEngine::OnSelect)LevelSelect);
		}

		AddMenuItem(new MenuItem("Main Menu"));
		GetMenuItem(i)->SetSelectCallback((KatanaEngine::OnSelect)LevelSelect);
	}

	int LevelSelectMenu::GetLevelIndex() const
	{
		int index = GetSelectedItem()->GetIndex();
		if (index < GetCount() - 1) return index + 1;
		
		return -1;
	}
}
