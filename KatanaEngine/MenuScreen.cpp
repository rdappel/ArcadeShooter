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

/  --------------------------------------------------------------- */

#include "KatanaEngine.h"

namespace KatanaEngine
{
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
			const int LAST_INDEX = (int)(m_menuItems.size() - 1);

			if (pInput->IsNewKeyPress(Key::ENTER))
			{
				m_menuItems[m_selectedItemIndex]->Select(this);
			}

			if (pInput->IsNewKeyPress(Key::UP) ||
				pInput->IsNewButtonPress(Button::DPAD_UP, playerIndexOut)) // TODO?: Make "IsMenuUp" in InputState ?
			{
				m_selectedItemIndex--;

				if (m_selectedItemIndex >= m_menuItems.size())
				{
					m_selectedItemIndex = (m_itemListWraps) ? LAST_INDEX : FIRST_INDEX;
				}
			}
			else if (pInput->IsNewKeyPress(Key::DOWN) ||
				pInput->IsNewButtonPress(Button::DPAD_DOWN, playerIndexOut)) // TODO?: Make "IsMenuDown" in InputState ?
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
}