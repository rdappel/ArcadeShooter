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

   File: Font.h
   Description: Header file for font resources.

/  --------------------------------------------------------------- */

#pragma once


class Font : public Resource
{

public:

	Font() { }
	virtual ~Font() { al_destroy_font(m_pFont); }


	static void SetLoadSize(const int size, const bool restore = false);

	static void SetCharacterRange(const int rangeCount, int ranges[]);


	virtual ALLEGRO_FONT *Get() { return m_pFont; }

	virtual bool Load(const std::string &path, ResourceManager *pManager);

	virtual int GetHeight() const { return al_get_font_line_height(m_pFont); }

	virtual int GetTextWidth(const char *text) const { return al_get_text_width(m_pFont, text); }


private:

	static int s_fontSize;
	static int s_restoreSize;

	static bool s_alAddonInitialized;

	static int s_rangeCount;
	static int *s_ranges;

	ALLEGRO_FONT *m_pFont;

};