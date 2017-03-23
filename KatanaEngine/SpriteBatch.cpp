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

   File: SpriteBatch.cpp
   Description: Source file for rendering resources.

/  --------------------------------------------------------------- */

#include "KatanaEngine.h"

void SpriteBatch::Begin(SpriteSortMode sortMode, BlendState blendState, ALLEGRO_TRANSFORM *transformation)
{
	m_isStarted = true;
	m_it = m_inactiveDrawables.begin();

	m_sortMode = sortMode;

	if (sortMode == SORTMODE_IMMEDIATE)
	{
		if (transformation != NULL) al_use_transform(transformation);
	}
	else
	{
		m_transformation = transformation;
	}

	switch (blendState)
	{
	case BLEND_ALPHA: 
		al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);
		break;
	case BLEND_ADDITIVE: 
		al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_ONE);
		break;
	}
}

void SpriteBatch::End(bool test)
{
	//double time = al_get_time();
	

	if (m_sortMode != SORTMODE_IMMEDIATE)
	{
		if (m_transformation != NULL) al_use_transform(m_transformation);
		
		switch (m_sortMode)
		{
		case SORTMODE_BACKTOFRONT:
			std::sort(m_drawables.begin(), m_drawables.end(), CompareBackToFront());
			break;

		case SORTMODE_FRONTTOBACK:
			std::sort(m_drawables.begin(), m_drawables.end(), CompareFrontToBack());
			break;

		case SORTMODE_TEXTURE:
			al_hold_bitmap_drawing(true);
			break;
		};
			//if (test) std::cout << "Sort time: " << (float)(al_get_time() - time) * 1000 << ", ";
			//time = al_get_time();
		
		for (std::vector<Drawable *>::iterator it = m_drawables.begin() ; it != m_drawables.end(); ++it)
		{
			if ((*it)->isBitmap) DrawBitmap(*it);
			else DrawFont(*it);
		}
		
			//if (test) std::cout << "Draw time: " << (float)(al_get_time() - time) * 1000 << ", ";
			//time = al_get_time();
	}

	if (m_drawables.size() > 0) m_drawables.clear();
		
			//if (test) std::cout << "Clear time: " << (float)(al_get_time() - time) * 1000 << std::endl;

	if (m_sortMode == SORTMODE_TEXTURE) al_hold_bitmap_drawing(false);

	ALLEGRO_TRANSFORM identity;
	al_identity_transform(&identity);
	al_use_transform(&identity);

	m_isStarted = false;
}

void SpriteBatch::DrawBitmap(Drawable *pDrawable)
{
	al_draw_tinted_scaled_rotated_bitmap_region(pDrawable->Union.pBitmap, pDrawable->Union.sx, pDrawable->Union.sy,
		pDrawable->Union.sw, pDrawable->Union.sh, pDrawable->color, pDrawable->Union.cx, pDrawable->Union.cy,
		pDrawable->x, pDrawable->y, pDrawable->Union.scx, pDrawable->Union.scy, pDrawable->Union.rotation, 0);
}

void SpriteBatch::DrawFont(Drawable *pDrawable)
{
	al_draw_text(pDrawable->Union.pFont, pDrawable->color, pDrawable->x, pDrawable->y, pDrawable->Union.align, pDrawable->Union.text->c_str());
}



void SpriteBatch::DrawString(Font *pFont, std::string *text, Vector2 position, Color color, TextAlign alignment, float drawDepth)
{
	assert(m_isStarted && "Begin must be called before a Draw function can be run!");

	Drawable *pDrawable;

	if (m_it != m_inactiveDrawables.end())
	{
		pDrawable = *m_it;
		m_it++;
	}
	else
	{
		pDrawable = new Drawable();
		m_inactiveDrawables.push_back(pDrawable);
		m_it = m_inactiveDrawables.end();
	}

	pDrawable->isBitmap = false;
	pDrawable->Union.pFont = pFont->Get();
	pDrawable->Union.text = text;
	pDrawable->Union.align = alignment;
	pDrawable->color = color.Get();
	pDrawable->x = position.X;
	pDrawable->y = position.Y;
	pDrawable->depth = drawDepth;

	if (m_sortMode == SORTMODE_IMMEDIATE)
	{
		DrawFont(pDrawable);
	}
	else
	{
		m_drawables.push_back(pDrawable);
	}
}


void SpriteBatch::Draw(Texture *pTexture, Vector2 position, Color color, Vector2 origin, Vector2 scale, float rotation, float drawDepth)
{
	assert(m_isStarted && "Begin must be called before a Draw function can be run!");

	Drawable *pDrawable;

	if (m_it != m_inactiveDrawables.end())
	{
		pDrawable = *m_it;
		m_it++;
	}
	else
	{
		pDrawable = new Drawable();
		m_inactiveDrawables.push_back(pDrawable);
		m_it = m_inactiveDrawables.end();
	}
	
	pDrawable->isBitmap = true;
	pDrawable->Union.pBitmap = pTexture->GetBitmap();
	pDrawable->Union.sx = 0;
	pDrawable->Union.sy = 0;
	pDrawable->Union.sw = pTexture->GetWidth();
	pDrawable->Union.sh = pTexture->GetHeight();
	pDrawable->Union.cx = origin.X;
	pDrawable->Union.cy = origin.Y;
	pDrawable->Union.scx = scale.X;
	pDrawable->Union.scy = scale.Y;
	pDrawable->Union.rotation = rotation;
	pDrawable->Union.id = pTexture->GetResourceID();
	pDrawable->color = color.Get();
	pDrawable->x = position.X;
	pDrawable->y = position.Y;
	pDrawable->depth = drawDepth;

	if (m_sortMode == SORTMODE_IMMEDIATE)
	{
		DrawBitmap(pDrawable);
	}
	else
	{
		m_drawables.push_back(pDrawable);
	}
}


void SpriteBatch::Draw(Texture *pTexture, Vector2 position, Region region, Color color, Vector2 origin, Vector2 scale, float rotation, float drawDepth)
{
	assert(m_isStarted && "Begin must be called before a Draw function can be run!");

	Drawable *pDrawable;

	if (m_it != m_inactiveDrawables.end())
	{
		pDrawable = *m_it;
		m_it++;
	}
	else
	{
		pDrawable = new Drawable();
		m_inactiveDrawables.push_back(pDrawable);
		m_it = m_inactiveDrawables.end();
	}
	
	pDrawable->isBitmap = true;
	pDrawable->Union.pBitmap = pTexture->GetBitmap();
	pDrawable->Union.cx = origin.X;
	pDrawable->Union.cy = origin.Y;
	pDrawable->Union.scx = scale.X;
	pDrawable->Union.scy = scale.Y;
	pDrawable->Union.rotation = rotation;
	pDrawable->Union.id = pTexture->GetResourceID();
	pDrawable->color = color.Get();
	pDrawable->x = position.X;
	pDrawable->y = position.Y;
	pDrawable->depth = drawDepth;

	pDrawable->Union.sx = (&region)->X;
	pDrawable->Union.sy = (&region)->Y;
	pDrawable->Union.sw = (&region)->Width;
	pDrawable->Union.sh = (&region)->Height;

	if (m_sortMode == SORTMODE_IMMEDIATE)
	{
		DrawBitmap(pDrawable);
	}
	else
	{
		m_drawables.push_back(pDrawable);
	}
}

void SpriteBatch::Draw(Animation *pAnimation, Vector2 position, Color color, Vector2 origin, Vector2 scale, float rotation, float drawDepth)
{
	Draw(pAnimation->GetTexture(), position, *pAnimation->GetCurrentFrame(), color, origin, scale, rotation, drawDepth);
}