
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

	/** @brief Callback function for when the main menu is removed from
		the screen manager.
		@param pScreen The screen that is about to be removed. */
	void MainMenuScreenRemove(Screen *pScreen)
	{
		pScreen->GetScreenManager()->AddScreen(new GameplayScreen());
	}

	/** @brief Callback function for start item is selected.
		@param pMenuScreen The menu screen that contains the menu item. */
	void StartSelect(MenuScreen *pMenuScreen)
	{
		pMenuScreen->SetRemoveCallback(MainMenuScreenRemove);
		pMenuScreen->Exit();
	}

	/** @brief Callback function for exit item is selected.
		@param pMenuScreen The menu screen that contains the menu item. */
	void ExitSelect(MenuScreen *pMenuScreen)
	{
		pMenuScreen->Exit();
		pMenuScreen->GetScreenManager()->GetGame()->Quit();
	}

	MainMenuScreen::MainMenuScreen()
	{
		// Setup the menu items
		m_selectedColor = Color(0, 0.5f, 1);
		m_unselectedColor = Color(1, 1, 1);
		SetItemListWrapping(false);

		m_pTexture = nullptr;

		SetTransitionInTime(1.0);
		SetTransitionOutTime(0.5);

		//SetUseRenderTarget();
		Show();
	}

	void MainMenuScreen::LoadContent(ResourceManager *pResourceManager)
	{
		const int MENU_ITEM_COUNT = 2;
		std::string items[MENU_ITEM_COUNT] = { "Start", /*"Options", */"Quit" };
		SetDisplayCount(MENU_ITEM_COUNT);

		int x = Game::GetScreenWidth() / 2;

		Font::SetLoadSize(24, true);
		Font *pFont = pResourceManager->Load<Font>("Fonts\\Ethnocentric.ttf");

		for (int i = 0; i < MENU_ITEM_COUNT; i++)
		{
			MenuItem *pMenuItem = new MenuItem;

			pMenuItem->SetFont(pFont);
			pMenuItem->SetText(items[i]);
			pMenuItem->SetTextAlign(TextAlign::CENTER);
			pMenuItem->SetPosition(Vector2(x, 600 + (40 * i)));

			AddMenuItem(pMenuItem);
		}

		GetMenuItem(0)->SetSelectCallback(StartSelect);
		GetMenuItem(1)->SetSelectCallback(ExitSelect);
		
		m_pTexture = pResourceManager->Load<Texture>("Textures\\Logo.png", false);
		m_position = Game::GetScreenCenter().ToVector2() - Vector2(0, 150);

		Screen::LoadContent(pResourceManager);
	}

	void MainMenuScreen::Update(const GameTime *pGameTime)
	{
		// Calculations to make the selected menu item pulse
		float sinValue = (float)((1.0f + sin(pGameTime->GetTotalTime() * 6)) * 0.5);
		m_selectedAlpha = 0.5f + 0.5f * sinValue;

		// Set the menu item colors
		for (int i = 0; i < GetDisplayCount(); i++)
		{
			Color color = m_unselectedColor;

			if (GetMenuItem(i)->IsSelected())
			{
				color = m_selectedColor * m_selectedAlpha;
			}

			GetMenuItem(i)->SetColor(color * GetAlpha());
		}

		MenuScreen::Update(pGameTime);
	}

	void MainMenuScreen::Draw(SpriteBatch *pSpriteBatch)
	{
		if (m_pTexture)
		{
			pSpriteBatch->Begin();
			pSpriteBatch->Draw(m_pTexture, m_position, Color::White * GetAlpha(), m_pTexture->GetCenter());
			pSpriteBatch->End();
		}

		MenuScreen::Draw(pSpriteBatch);
	}
}