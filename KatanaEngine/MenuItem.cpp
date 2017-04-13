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
	MenuItem::MenuItem() : MenuItem("")	{ }

	MenuItem::MenuItem(std::string text)
	{
		m_onSelect = nullptr;
		m_pFont = nullptr;

		m_text = text;

		m_color = Color::White;
		m_alpha = 1.0f;

		m_position = Vector2::Zero;
		m_textOffset = Vector2::Zero;

		m_textAlign = TextAlign::LEFT;
		m_isDisplayed = true;
	}

	void MenuItem::Draw(SpriteBatch *pSpriteBatch)
	{
		if (m_pFont && m_text.compare("") != 0)
		{
			pSpriteBatch->DrawString(m_pFont, &m_text, m_position + m_textOffset, m_color * m_alpha, m_textAlign);
		}
	}

	void MenuItem::Select(MenuScreen *pMenuScreen)
	{
		if (m_onSelect) ((OnSelect)m_onSelect)(pMenuScreen);
	}
}