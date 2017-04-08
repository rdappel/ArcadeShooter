
#include "Sample.h"

namespace Sample
{

	// Removal Callback Function
	void MainMenuScreenRemove(Screen *pScreen)
	{
		pScreen->GetScreenManager()->AddScreen(new GameplayScreen());
	}

	// MenuItem Callback Functions
	void StartSelect(MenuScreen *pMenuScreen)
	{
		pMenuScreen->SetRemoveCallback(MainMenuScreenRemove);
		pMenuScreen->Exit();
	}

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

	void MainMenuScreen::LoadContent()
	{
		const int MENU_ITEM_COUNT = 2;
		std::string items[MENU_ITEM_COUNT] = { "Start", /*"Options", */"Quit" };
		SetDisplayCount(MENU_ITEM_COUNT);

		int x = Game::GetScreenWidth() / 2;

		Font::SetLoadSize(24, true);
		Font *pFont = GetResourceManager()->Load<Font>("Fonts\\Ethnocentric.ttf");

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
		
		m_pTexture = GetResourceManager()->Load<Texture>("Textures\\Logo.png", false);
		m_position = Game::GetScreenCenter().ToVector2() - Vector2(0, 150);

		Screen::LoadContent();
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

	void MainMenuScreen::Draw(const GameTime *pGameTime)
	{
		if (m_pTexture)
		{
			GetSpriteBatch()->Begin();
			GetSpriteBatch()->Draw(m_pTexture, m_position, Color::White * GetAlpha(), m_pTexture->GetCenter());
			GetSpriteBatch()->End();
		}

		MenuScreen::Draw(pGameTime);
	}
}