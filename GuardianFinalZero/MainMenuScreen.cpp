
#include "GuardianFinalZero.h"

namespace GuardianFinalZero
{

	// Removal Callback Function
	void MainMenuScreenRemove(Screen *pScreen)
	{
		pScreen->GetScreenManager()->AddScreen(new GameplayScreen(1));
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

		m_pLogoTexture = nullptr;

		SetTransitionInTime(3);
		SetTransitionOutTime(0.5f);

		m_menuFadeInTime = 1;
		m_menuFadeValue = 0;
		m_menuAlpha = 0;

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
			pMenuItem->SetPosition(Vector2(x, 560 + (40 * i)));

			AddMenuItem(pMenuItem);
		}

		GetMenuItem(0)->SetSelectCallback(StartSelect);
		GetMenuItem(1)->SetSelectCallback(ExitSelect);

		m_pLogoTexture = GetResourceManager()->Load<Texture>("Textures\\LogoText.png");

		m_targetPosition = Game::GetScreenCenter().ToVector2() - Vector2(0, 150);
		m_position = m_targetPosition - Vector2(0, 400);

		Screen::LoadContent();
	}

	void MainMenuScreen::Update(const GameTime *pGameTime)
	{
		// Calculations to make the selected menu item pulse
		const static float pulseSpeed = 6;
		const static float startOffset = (float)GetTransitionInTime();
		float sinParam = pGameTime->GetTotalTime() * pulseSpeed + startOffset;
		float sinValue = (float)((1.0f + sin(sinParam)) * 0.5);
		m_selectedAlpha = 0.5f + 0.5f * sinValue;


		// Delay the menu items until the logo has faded in
		if (GetAlpha() == 1 && m_menuFadeValue < 1)
		{
			m_menuFadeValue += pGameTime->GetTimeElapsed();
			float value = m_menuFadeValue / m_menuFadeInTime;
			if (value >= 1) m_menuAlpha = 1;
			else m_menuAlpha = Math::Lerp(0, 1, value);
		}

		// Set the menu item colors
		for (int i = 0; i < GetDisplayCount(); i++)
		{
			Color color = m_unselectedColor;

			if (GetMenuItem(i)->IsSelected())
			{
				color = m_selectedColor * m_selectedAlpha;
			}

			GetMenuItem(i)->SetColor(color);
			GetMenuItem(i)->SetAlpha(GetAlpha() * m_menuAlpha);
		}

		if (GetAlpha() > 0.4f)
		{
			m_position = Vector2::Lerp(m_position, m_targetPosition, 0.08f * GetAlpha());
			m_position.X = m_targetPosition.X;
		}

		MenuScreen::Update(pGameTime);
	}

	void MainMenuScreen::Draw(const GameTime *pGameTime)
	{
		Color color = Color::White * GetAlpha();

		GetSpriteBatch()->Begin();
		GetSpriteBatch()->Draw(m_pLogoTexture, m_position, color, m_pLogoTexture->GetCenter());
		GetSpriteBatch()->End();

		MenuScreen::Draw(pGameTime);
	}
}