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
Date: 5/8/2015

File: Font.cpp
Description: Source file for font resources.

/  --------------------------------------------------------------- */

#include "KatanaEngine.h"


// Static Members
int Font::s_fontSize = 16;
int Font::s_restoreSize = 0;
bool Font::s_alAddonInitialized = false;
int Font::s_rangeCount = 0;
int *Font::s_ranges = nullptr;


void Font::SetLoadSize(const int size, const bool restore)
{
	if (restore) s_restoreSize = s_fontSize;

	s_fontSize = size;
}

void Font::SetCharacterRange(const int rangeCount, int ranges[])
{
	s_rangeCount = rangeCount;
	s_ranges = ranges;
}

bool Font::Load(const std::string &path, ResourceManager *pManager)
{
	if (!s_alAddonInitialized)
	{
		al_init_font_addon();
		al_init_ttf_addon();

		s_alAddonInitialized = true;
	}

	bool isTTF = (path.find(".ttf") != std::string::npos);
	bool isPNG = (path.find(".png") != std::string::npos);
	if (isTTF)
	{
		m_pFont = al_load_ttf_font(path.c_str(), s_fontSize, 0);
	}
	else if (isPNG)
	{
		int ranges[] = {
			32, 126 };  // ASCII
						//0x00A1, 0x00FF,  // Latin 1
						//0x0100, 0x017F};  // Extended-A

		if (s_ranges == nullptr)
		{
			s_ranges = ranges;
			s_rangeCount = 1;
		}

		Texture *pTexture = pManager->Load<Texture>(path, true, false);
		if (pTexture)
		{
			m_pFont = al_grab_font_from_bitmap(pTexture->GetBitmap(), s_rangeCount, s_ranges);
		}
			
		s_ranges = nullptr;
	}
	else
	{
		m_pFont = al_load_font(path.c_str(), s_fontSize, 0);
	}

	if (s_restoreSize > 0) s_fontSize = s_restoreSize;

	return (m_pFont != nullptr);
}
