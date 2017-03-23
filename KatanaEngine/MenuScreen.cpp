/* ---------------------------------------------------------------  /

	 ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗ 
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
        Katana Engine \/ © 2012 - Shuriken Studios LLC


   Author: Ryan Appel
   Date: 5/6/2015

   File: MenuScreen.cpp
   Description: Source file for a menu screen.

/  --------------------------------------------------------------- */

#include "KatanaEngine.h"


MenuScreen::MenuScreen()
{
	m_selectedItemIndex = 0;
	m_displayStartIndex = 0;
	m_displayCount = 0;
	m_itemListWraps = true;
}


MenuScreen::~MenuScreen()
{
	std::vector<MenuItem *>::iterator it;
	for (it = m_menuItems.begin(); it != m_menuItems.end(); ++it)
	{
		delete *it;
	}
}

	
void MenuScreen::HandleInput(InputState *pInput)
{
	if (m_displayCount > 0) m_itemListWraps = false;

	if (m_menuItems.size() > 0)
	{
		int playerIndexOut;

		const int FIRST_INDEX = 0;
		const int LAST_INDEX = m_menuItems.size() - 1;

		if (pInput->IsNewKeyPress(ALLEGRO_KEY_ENTER))
		{
			m_menuItems[m_selectedItemIndex]->Select(this);
		}

		if (pInput->IsNewKeyPress(ALLEGRO_KEY_UP) ||
			pInput->IsNewButtonPress(BUTTON_DPADUP, playerIndexOut)) // TODO?: Make "IsMenuUp" in InputState ?
		{
			m_selectedItemIndex--;

			if (m_selectedItemIndex >= m_menuItems.size())
			{
				m_selectedItemIndex = (m_itemListWraps) ? LAST_INDEX : FIRST_INDEX;
			}
		}
		else if (pInput->IsNewKeyPress(ALLEGRO_KEY_DOWN) ||
			pInput->IsNewButtonPress(BUTTON_DPADDOWN, playerIndexOut)) // TODO?: Make "IsMenuDown" in InputState ?
		{
			m_selectedItemIndex++;

			if (m_selectedItemIndex >= m_menuItems.size())
			{
				m_selectedItemIndex = (m_itemListWraps) ? FIRST_INDEX : LAST_INDEX;
			}
		}

		if (m_displayCount > 0)
		{
			if (m_selectedItemIndex < m_displayStartIndex)
			{
				m_displayStartIndex--;
			}
			else if (m_selectedItemIndex >= m_displayStartIndex + m_displayCount)
			{
				m_displayStartIndex++; 
			}
		}
	}
}

void MenuScreen::Update(const GameTime *pGameTime)
{
	unsigned int index = 0;

	std::vector<MenuItem *>::iterator it;
	for (it = m_menuItems.begin(); it != m_menuItems.end(); ++it)
	{
		MenuItem *pMenuItem = *it;

		bool displayed = (m_displayCount == 0
			|| (index >= m_displayStartIndex
			&& index < m_displayStartIndex + m_displayCount));

		pMenuItem->SetDisplayed(displayed);
		pMenuItem->SetSelected(index == m_selectedItemIndex);
		pMenuItem->Update(pGameTime);

		UpdateItem(pMenuItem, index);

		index++;
	}
}

void MenuScreen::Draw(const GameTime *pGameTime)
{
	GetSpriteBatch()->Begin();
	
	std::vector<MenuItem *>::iterator it;
	for (it = m_menuItems.begin(); it != m_menuItems.end(); ++it)
	{
		MenuItem *pMenuItem = *it;

		if (pMenuItem->IsDisplayed()) pMenuItem->Draw(pGameTime);
	}

	GetSpriteBatch()->End();
}

SpriteBatch *MenuScreen::GetSpriteBatch() const
{
	return GetGame()->GetSpriteBatch();
}
