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
	MenuItem::MenuItem()
	{
		m_onSelect = nullptr;
		m_pFont = nullptr;

		m_color = Color::White;
		m_alpha = 1.0f;
		m_text = "";

		m_position = Vector2::Zero;
		m_textOffset = Vector2::Zero;

		m_textAlign = TextAlign::LEFT;
		m_isDisplayed = true;
	}

	void MenuItem::Draw(const GameTime *pGameTime)
	{
		if (m_pFont && m_text.compare("") != 0)
		{
			SpriteBatch *pSpriteBatch = m_pMenuScreen->GetSpriteBatch();

			pSpriteBatch->DrawString(m_pFont, &m_text, m_position + m_textOffset, m_color * m_alpha, m_textAlign);
		}
	}

	void MenuItem::Select(MenuScreen *pMenuScreen)
	{
		if (m_onSelect) ((OnSelect)m_onSelect)(pMenuScreen);
	}
}