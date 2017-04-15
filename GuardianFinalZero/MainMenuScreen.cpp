
/*                '888 88888888888 888888888',8888'
                    88 888888888888 8888888',8888'
                     8 8888             ,8',8888'
          ==̲=̲=̲=̲=̲=̲=== 8 8888 ========== ,8 ,̲8̲88̲8_==============
          /  ____/__ 8_̲88̲8̲8̲8̲88̲88̲8̲8̲8__ ,̲8__/ //_/____ _ ____
	     / /  __ / / / /ˊ __ `// ___/ˊ __  /__ ˊ __ `// __ \
	    / /__/ // /_/ // /_/ // /   / /_/ // // /_/ // / / /
	    \_____/ \__,_/ \__,_//_/    \__,_//_/ \__,_//_/ /_/
      ============== 8 8888 ===== ,8',8888' ===============
                    88 8888      ,8',8888888888888 
                   ,88 8888     ,8',888888888888888,
				   
				           ファイナル ゼロ

               Guardian FZ © 2017 - Shuriken Studios LLC          */

#include "GuardianFinalZero.h"

namespace GuardianFinalZero
{

	/** @brief Callback function for when the main menu is removed from
		the screen manager.
		@param pScreen The screen that is about to be removed. */
	void MainMenuScreenRemove(Screen *pScreen)
	{
		//pScreen->GetScreenManager()->AddScreen(new GameplayScreen(1));
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

		m_pLogoTexture = nullptr;

		SetTransitionInTime(3);
		SetTransitionOutTime(0.5f);

		m_menuFadeInTime = 1;
		m_menuFadeValue = 0;
		m_menuAlpha = 0;

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
			pMenuItem->SetPosition(Vector2(x, 560 + (40 * i)));

			AddMenuItem(pMenuItem);
		}

		GetMenuItem(0)->SetSelectCallback(StartSelect);
		GetMenuItem(1)->SetSelectCallback(ExitSelect);

		m_pLogoTexture = pResourceManager->Load<Texture>("Textures\\LogoText.png");

		m_targetPosition = Game::GetScreenCenter() - Vector2(0, 150);
		m_position = m_targetPosition - Vector2(0, 400);

		Screen::LoadContent(pResourceManager);
	}


	void MainMenuScreen::Update(const GameTime *pGameTime)
	{
		// Calculations to make the selected menu item pulse
		const static float pulseSpeed = 6;
		const static float startOffset = (float)GetTransitionInTime();
		float sineParam = pGameTime->GetTotalTime() * pulseSpeed + startOffset;
		float sineValue = (float)((1.0f + sin(sineParam)) * 0.5);
		m_selectedAlpha = 0.5f + 0.5f * sineValue;


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


	void MainMenuScreen::Draw(SpriteBatch *pSpriteBatch)
	{
		Color color = Color::White * GetAlpha();

		pSpriteBatch->Begin();
		pSpriteBatch->Draw(m_pLogoTexture, m_position, color, m_pLogoTexture->GetCenter());
		pSpriteBatch->End();

		MenuScreen::Draw(pSpriteBatch);
	}
}