
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
	MenuScreen::MenuScreen()
	{
		m_selectedColor = Color(0, 0.5f, 1);
		m_unselectedColor = Color(1, 1, 1);

		m_selectedAlpha = 1;
		m_unselectedAlpha = 1;

		SetItemListWrapping(false);
		
		SetTransitionInTime(1.0);
		SetTransitionOutTime(0.5);

		SetMenuPosition(Game::GetScreenCenter());
	}

	void MenuScreen::LoadContent(ResourceManager *pResourceManager)
	{
		Font::SetLoadSize(24, true);
		m_pFont = pResourceManager->Load<Font>("Fonts\\Ethnocentric.ttf");
	}


	void MenuScreen::Update(const GameTime *pGameTime)
	{
		// Calculations to make the selected menu item pulse
		float sineValue = (float)((1.0f + sin(pGameTime->GetTotalTime() * 6)) * 0.5);
		m_selectedAlpha =  (0.5f + 0.5f * sineValue);

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

		KatanaEngine::MenuScreen::Update(pGameTime);
	}

	void MenuScreen::AddMenuItem(MenuItem *pItem)
	{
		KatanaEngine::MenuScreen::AddMenuItem(pItem);

		pItem->SetFont(m_pFont);
		pItem->SetTextAlign(TextAlign::CENTER);
		pItem->SetPosition(m_position + (Vector2::UnitY * 40 * pItem->GetIndex()));
	}

}