
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

	/** @brief Callback function for when the main menu is removed from
		the screen manager.
		@param pScreen The screen that is about to be removed. */
	void MainMenuScreenRemove(Screen *pScreen)
	{
		pScreen->GetScreenManager()->AddScreen(new LevelSelectMenu());
	}

	/** @brief Callback function for when the start item is selected.
		@param pMenuScreen The menu screen that contains the menu item. */
	void StartSelect(MenuScreen *pMenuScreen)
	{
		pMenuScreen->SetRemoveCallback(MainMenuScreenRemove);
		pMenuScreen->Exit();
	}

	/** @brief Callback function for when the exit item is selected.
		@param pMenuScreen The menu screen that contains the menu item. */
	void ExitSelect(MenuScreen *pMenuScreen)
	{
		pMenuScreen->Exit();
		pMenuScreen->GetScreenManager()->GetGame()->Quit();
	}

	#pragma endregion


	MainMenuScreen::MainMenuScreen()
	{
		m_pTexture = nullptr;

		Show();
	}


	void MainMenuScreen::LoadContent(ResourceManager *pResourceManager)
	{
		MenuScreen::LoadContent(pResourceManager);
		Vector2 position = Game::GetScreenCenter() + Vector2::UnitY * 160;
		SetMenuPosition(position);

		const int MENU_ITEM_COUNT = 2;
		std::string items[MENU_ITEM_COUNT] = { "Start", "Quit" };
		SetDisplayCount(MENU_ITEM_COUNT);

		AddMenuItem(new MenuItem(items[0]));
		AddMenuItem(new MenuItem(items[1]));

		GetMenuItem(0)->SetSelectCallback((KatanaEngine::OnSelect)StartSelect);
		GetMenuItem(1)->SetSelectCallback((KatanaEngine::OnSelect)ExitSelect);
		
		m_pTexture = pResourceManager->Load<Texture>("Textures\\Logo.png", false);
		m_texturePosition = Game::GetScreenCenter() - Vector2::UnitY * 200;
	}



	void MainMenuScreen::Draw(SpriteBatch *pSpriteBatch)
	{
		if (m_pTexture)
		{
			pSpriteBatch->Begin();
			pSpriteBatch->Draw(m_pTexture, m_texturePosition, Color::White * GetAlpha(), m_pTexture->GetCenter());
			pSpriteBatch->End();
		}

		MenuScreen::Draw(pSpriteBatch);
	}
}