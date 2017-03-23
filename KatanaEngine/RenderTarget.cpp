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
   Date: 5/9/2015

   File: RenderTarget.h
   Description: Header file for a render target.

/  --------------------------------------------------------------- */

#include "KatanaEngine.h"


ALLEGRO_DISPLAY *RenderTarget::s_pDisplay;


RenderTarget::RenderTarget(const int width, const int height)
{
	ALLEGRO_BITMAP *pBitmap = al_create_bitmap(width, height);

	SetTexture(pBitmap);
}

	
void RenderTarget::Set(RenderTarget *pTarget)
{
	if (pTarget) al_set_target_bitmap(pTarget->GetBitmap());
	else al_set_target_bitmap(al_get_backbuffer(s_pDisplay));
}