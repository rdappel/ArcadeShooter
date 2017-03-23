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

   File: Texture.h
   Description: Header file for texture resources.

/  --------------------------------------------------------------- */

#pragma once


class Texture : public Resource
{

public:

	Texture();
	virtual ~Texture();
		
	virtual ALLEGRO_BITMAP *GetBitmap()	{ return m_pBitmap; }

	virtual bool Load(const std::string &path, ResourceManager *pManager);

	int GetWidth() const { return m_width; }

	int GetHeight() const { return m_height; }


protected:

	virtual void SetTexture(ALLEGRO_BITMAP *pBitmap);


private:

	static bool s_alAddonInitialized;

	ALLEGRO_BITMAP *m_pBitmap;

	int m_width;
	int m_height;

};