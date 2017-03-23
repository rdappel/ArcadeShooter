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

   File: MenuItem.cpp
   Description: Source file for a menu item.

/  --------------------------------------------------------------- */

#include "KatanaEngine.h"


MenuItem::MenuItem()
{
	OnSelect = nullptr;
	m_pFont = nullptr;

	m_color = Color::White;
	m_alpha = 1.0f;
	m_text = "";
	
	m_position = Vector2::Zero;
	m_textOffset = Vector2::Zero;

	m_textAlign = ALIGN_LEFT;
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
	if (OnSelect) OnSelect(pMenuScreen);
}
