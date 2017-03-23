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

   File: Texture.cpp
   Description: Source file for texture resources.

/  --------------------------------------------------------------- */

#include "KatanaEngine.h"


// Static Members
bool Texture::s_alAddonInitialized = false;

Texture::Texture()
{
	if (!s_alAddonInitialized)
	{
		al_init_image_addon();
		s_alAddonInitialized = true;
	}

	m_pBitmap = nullptr;
}

Texture::~Texture() 
{
	al_destroy_bitmap(m_pBitmap);
	m_pBitmap = nullptr;
}


bool Texture::Load(const std::string &path, ResourceManager *pManager)
{
	ALLEGRO_BITMAP *pTemp = al_load_bitmap(path.c_str());

	SetTexture(pTemp);

	return m_pBitmap;
}


void Texture::SetTexture(ALLEGRO_BITMAP *pBitmap)
{
	if (pBitmap)
	{
		m_pBitmap = pBitmap;
		m_width = al_get_bitmap_width(m_pBitmap);
		m_height = al_get_bitmap_height(m_pBitmap);
	}
}