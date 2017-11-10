
/*
     ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗ 
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
        Katana Engine \/ © 2012 - Shuriken Studios LLC
			    http://www.shurikenstudios.com
*/

#include "KatanaEngine.h"

namespace KatanaEngine
{
	void SpriteBatch::Begin(const SpriteSortMode sortMode, 
		const BlendState blendState, ALLEGRO_TRANSFORM *pTransformation)
	{
		m_isStarted = true;
		m_it = m_inactiveDrawables.begin();

		m_sortMode = sortMode;

		if (sortMode == SpriteSortMode::IMMEDIATE)
		{
			if (pTransformation != NULL) al_use_transform(pTransformation);
		}
		else
		{
			m_pTransformation = pTransformation;
		}

		m_blendState = blendState;

		switch (blendState)
		{
		case BlendState::ALPHA:
			al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);
			break;
		case BlendState::ADDITIVE:
			al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_ONE);
			break;
		}
	}

	void SpriteBatch::End(/*bool test*/)
	{
		//double time = al_get_time();


		if (m_sortMode != SpriteSortMode::IMMEDIATE)
		{
			if (m_pTransformation != NULL) al_use_transform(m_pTransformation);

			switch (m_sortMode)
			{
			case SpriteSortMode::BACK_TO_FRONT:
				std::sort(m_drawables.begin(), m_drawables.end(), CompareBackToFront());
				break;

			case SpriteSortMode::FRONT_TO_BACK:
				std::sort(m_drawables.begin(), m_drawables.end(), CompareFrontToBack());
				break;

			case SpriteSortMode::TEXTURE:
				al_hold_bitmap_drawing(true);
				break;
			};
			//if (test) std::cout << "Sort time: " << (float)(al_get_time() - time) * 1000 << ", ";
			//time = al_get_time();

			for (std::vector<Drawable *>::iterator it = m_drawables.begin(); it != m_drawables.end(); ++it)
			{
				if ((*it)->isBitmap) DrawBitmap(*it);
				else DrawFont(*it);
			}

			//if (test) std::cout << "Draw time: " << (float)(al_get_time() - time) * 1000 << ", ";
			//time = al_get_time();
		}

		if (m_drawables.size() > 0) m_drawables.clear();

		//if (test) std::cout << "Clear time: " << (float)(al_get_time() - time) * 1000 << std::endl;

		if (m_sortMode == SpriteSortMode::TEXTURE) al_hold_bitmap_drawing(false);

		ALLEGRO_TRANSFORM identity;
		al_identity_transform(&identity);
		al_use_transform(&identity);

		m_isStarted = false;
	}

	void SpriteBatch::DrawBitmap(Drawable *pDrawable)
	{
		al_draw_tinted_scaled_rotated_bitmap_region(
			pDrawable->Union.pBitmap,
			pDrawable->Union.sx, pDrawable->Union.sy,
			pDrawable->Union.sw, pDrawable->Union.sh,
			pDrawable->color,
			pDrawable->Union.cx, pDrawable->Union.cy,
			pDrawable->x, pDrawable->y,
			pDrawable->Union.scx, pDrawable->Union.scy,
			pDrawable->Union.rotation, 0);
	}

	void SpriteBatch::DrawFont(Drawable *pDrawable)
	{
		al_draw_multiline_text(
			pDrawable->Union.pFont,
			pDrawable->color,
			pDrawable->x, pDrawable->y,
			Game::GetScreenWidth(), 0,
			(int)pDrawable->Union.align,
			pDrawable->Union.text->c_str());
	}



	void SpriteBatch::DrawString(const Font *pFont, std::string *text, const Vector2 position,
		const Color color, const TextAlign alignment, const float drawDepth)
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
		pDrawable->Union.pFont = pFont->GetAllegroFont();
		pDrawable->Union.text = text;
		pDrawable->Union.align = alignment;
		pDrawable->color = color.GetAllegroColor();
		pDrawable->x = position.X;
		pDrawable->y = position.Y;
		pDrawable->depth = drawDepth;

		if (m_sortMode == SpriteSortMode::IMMEDIATE)
		{
			DrawFont(pDrawable);
		}
		else
		{
			m_drawables.push_back(pDrawable);
		}
	}



	void SpriteBatch::Draw(const Texture *pTexture, const Vector2 position,
		const Color color, const Vector2 origin, const Vector2 scale,
		const float rotation, const float drawDepth)
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
		pDrawable->Union.pBitmap = pTexture->GetAllegroBitmap();
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
		pDrawable->color = color.GetAllegroColor();
		pDrawable->x = position.X;
		pDrawable->y = position.Y;
		pDrawable->depth = drawDepth;

		if (m_sortMode == SpriteSortMode::IMMEDIATE)
		{
			DrawBitmap(pDrawable);
		}
		else
		{
			m_drawables.push_back(pDrawable);
		}
	}


	void SpriteBatch::Draw(const Texture *pTexture, const Vector2 position,
		const Region region, const Color color, const Vector2 origin, const Vector2 scale,
		const float rotation, const float drawDepth)
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
		pDrawable->Union.pBitmap = pTexture->GetAllegroBitmap();
		pDrawable->Union.cx = origin.X;
		pDrawable->Union.cy = origin.Y;
		pDrawable->Union.scx = scale.X;
		pDrawable->Union.scy = scale.Y;
		pDrawable->Union.rotation = rotation;
		pDrawable->Union.id = pTexture->GetResourceID();
		pDrawable->color = color.GetAllegroColor();
		pDrawable->x = position.X;
		pDrawable->y = position.Y;
		pDrawable->depth = drawDepth;

		pDrawable->Union.sx = (&region)->X;
		pDrawable->Union.sy = (&region)->Y;
		pDrawable->Union.sw = (&region)->Width;
		pDrawable->Union.sh = (&region)->Height;

		if (m_sortMode == SpriteSortMode::IMMEDIATE)
		{
			DrawBitmap(pDrawable);
		}
		else
		{
			m_drawables.push_back(pDrawable);
		}
	}

	void SpriteBatch::Draw(Animation *pAnimation, const Vector2 position,
		const Color color, const Vector2 origin, const Vector2 scale,
		const float rotation, float drawDepth)
	{
		Draw(pAnimation->GetTexture(), position, *pAnimation->GetCurrentFrame(),
			color, origin, scale, rotation, drawDepth);
	}

	void SpriteBatch::GetBatchSettings(SpriteSortMode &sortMode,
		BlendState &blendState, ALLEGRO_TRANSFORM *pTransformation)
	{
		assert(m_isStarted && "Begin must be called before the settings can be retrieved.");

		sortMode = m_sortMode;
		blendState = m_blendState;
		pTransformation = m_pTransformation;
	}
}