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

   File: SpriteBatch.h
   Description: Header file for rendering resources.

/  --------------------------------------------------------------- */

#pragma once


enum class TextAlign { LEFT, CENTER, RIGHT };

enum class SpriteSortMode { BACK_TO_FRONT, DEFERRED, FRONT_TO_BACK, IMMEDIATE, TEXTURE };

enum class BlendState { ALPHA, ADDITIVE };

class SpriteBatch
{

public:

	SpriteBatch() { m_isStarted = false; }
	~SpriteBatch() { }

	void Begin(SpriteSortMode sortMode = SpriteSortMode::DEFERRED, BlendState blendState = BlendState::ALPHA, ALLEGRO_TRANSFORM *transformation = NULL);
	void End(bool test = false);
	
	void DrawString(Font *pFont, std::string *text, Vector2 position, Color color = Color::White,
		TextAlign alignment = TextAlign::LEFT, float drawDepth = 0);
	
	void Draw(Texture *pTexture, Vector2 position, Region region, Color color = Color::White,
		Vector2 origin = Vector2::Zero, Vector2 scale = Vector2::One, float rotation = 0, float drawDepth = 0);
	
	void Draw(Texture *pTexture, Vector2 position, Color color = Color::White,
		Vector2 origin = Vector2::Zero, Vector2 scale = Vector2::One, float rotation = 0, float drawDepth = 0);

	void Draw(Animation *pAnimation, Vector2 position, Color color = Color::White,
		Vector2 origin = Vector2::Zero, Vector2 scale = Vector2::One, float rotation = 0, float drawDepth = 0);


private:

	

	struct Drawable
	{
		bool isBitmap;
		ALLEGRO_COLOR color;
		int x, y;
		float depth;

		union
		{
			struct
			{
				ALLEGRO_FONT *pFont;
				std::string *text;
				TextAlign align;
			};

			struct
			{
				ALLEGRO_BITMAP *pBitmap;
				float rotation;
				int cx, cy;
				int sx, sy, sw, sh;
				float scx, scy;
				unsigned short id;
			};

		} Union;
		
		bool operator<(const Drawable& other) const
		{
			return (depth < other.depth);
		}
	};

	struct CompareBackToFront
	{
		bool operator()(const Drawable* l, const Drawable* r)
		{
			if (*l < *r)
			{
				return true;
			}

			return false;
		}
	};

	struct CompareFrontToBack
	{
		bool operator()(const Drawable* l, const Drawable* r)
		{
			if (*r < *l)
			{

				return true;
			}

			return false;
		}
	};
	
	std::vector<Drawable *> m_drawables;
	std::vector<Drawable *> m_inactiveDrawables;
	std::vector<Drawable *>::iterator m_it;

	unsigned short m_lastID;

	SpriteSortMode m_sortMode;

	ALLEGRO_TRANSFORM *m_transformation;

	bool m_isStarted;
	
	void DrawBitmap(Drawable *drawable);
	void DrawFont(Drawable *drawable);

};