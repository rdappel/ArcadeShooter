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

#pragma once

namespace KatanaEngine
{
	/** @brief Defines the states for text alignment. */
	enum class TextAlign
	{
		LEFT,			/**< Align the text to the left. */
		CENTER,			/**< Align the text to the center. */
		RIGHT			/**< Align the text to the right. */
	};

	/** @brief Defines the methods for sorting sprites before rendering.
		@see SpriteBatch::Begin()
		@see SpriteBatch::Draw() */
	enum class SpriteSortMode
	{
		BACK_TO_FRONT,	/**< Sprites rendered with a lower draw order will render behind those with a higher draw order. */
		DEFERRED,		/**< Sprites rendered first will appear behind those rendered later. */
		FRONT_TO_BACK,	/**< Sprites rendered with a higher draw order will render behind those with a lower draw order. */
		IMMEDIATE,		/**< Sprites will not be batched, and will draw immediately. */
		TEXTURE			/**< Sprites that share a texture will all be rendered together. */
	};

	/** @brief Defines the way in which textures blending will be calculated. */
	enum class BlendState
	{
		ALPHA,			/**< Textures will be blended using premultiplied alpha blending. */
		ADDITIVE		/**< Textures will be blended using additive blending. */
	};

	/** @brief Enables a group of sprites to be drawn using the same settings. */
	class SpriteBatch
	{

	public:

		SpriteBatch() { m_isStarted = false; }
		~SpriteBatch() { }

		/** @brief Begins a sprite batch operation.
			@param sortMode Defines how to sort the sprites for rendering.
			@param blendState Defines how to blend overlaping sprites.
			@param transformation Defines a screen space transformation to use. */
		void Begin(const SpriteSortMode sortMode = SpriteSortMode::DEFERRED,
			const BlendState blendState = BlendState::ALPHA,
			ALLEGRO_TRANSFORM *transformation = NULL);

		/** @brief Flushes the sprite batch and restores the device state to how
		it was before Begin was called. */
		void End(/*bool test = false*/);

		/** @brief Adds a string to a batch of sprites to be rendered.
			@param pFont The font used to draw the text.
			@param text The text to display.
			@param position The screen position of the text.
			@param color The color to tint the text. The default is Color::White (no tint).
			@param alignment The prefered method of aligning the text. The default is
			TextAlign::LEFT.
			@param drawDepth The depth at which to render the sprite. This is determined
			by the SpriteSortMode arguement that is passed to SpriteBatch::Begin(). The
			default is zero.*/
		void DrawString(const Font *pFont, std::string *text, const Vector2 position,
			const Color color = Color::White, const TextAlign alignment = TextAlign::LEFT,
			const float drawDepth = 0);

		/** @brief Adds a sprite to a batch of sprites to be rendered. 
			@param pTexture A pointer to the texture to render.
			@param position The screen position of the sprite.
			@param region The region of the texture to render.
			@param color The color to tint the sprite. The default is Color::White (no tint).
			@param origin The sprite's origin. The default is Vector2::Zero, which is the
			upper left corner of the sprite.
			@param scale The scale factor of the sprite. The default is Vector2::One.
			@param rotation The rotation angle in radians. The default is zero.
			@param drawDepth The depth at which to render the sprite. This is determined
			by the SpriteSortMode arguement that is passed to SpriteBatch::Begin(). The
			default is zero.*/
		void Draw(const Texture *pTexture, const Vector2 position, const Region region,
			const Color color = Color::White, const Vector2 origin = Vector2::Zero, 
			const Vector2 scale = Vector2::One, const float rotation = 0, 
			const float drawDepth = 0);

		/** @brief Adds a sprite to a batch of sprites to be rendered.
			@param pTexture A pointer to the texture to render.
			@param position The screen position of the sprite.
			@param color The color to tint the sprite. The default is Color::White (no tint).
			@param origin The sprite's origin. The default is Vector2::Zero, which is the
			upper left corner of the sprite.
			@param scale The scale factor of the sprite. The default is Vector2::One.
			@param rotation The rotation angle in radians. The default is zero.
			@param drawDepth The depth at which to render the sprite. This is determined
			by the SpriteSortMode arguement that is passed to SpriteBatch::Begin(). The
			default is zero.

			@overload */
		void Draw(const Texture *pTexture, const Vector2 position,
			const Color color = Color::White, const Vector2 origin = Vector2::Zero,
			const Vector2 scale = Vector2::One, const float rotation = 0,
			const float drawDepth = 0);

		/** @brief Adds a sprite to a batch of sprites to be rendered.
			@param pAnimation A pointer to the animation to render.
			@param position The screen position of the sprite.
			@param color The color to tint the sprite. The default is Color::White (no tint).
			@param origin The sprite's origin. The default is Vector2::Zero, which is the
			upper left corner of the sprite.
			@param scale The scale factor of the sprite. The default is Vector2::One.
			@param rotation The rotation angle in radians. The default is zero.
			@param drawDepth The depth at which to render the sprite. This is determined
			by the SpriteSortMode arguement that is passed to SpriteBatch::Begin(). The
			default is zero.

			@overload */
		void Draw(Animation *pAnimation, const Vector2 position,
			const Color color = Color::White, const Vector2 origin = Vector2::Zero,
			const Vector2 scale = Vector2::One, const float rotation = 0,
			float drawDepth = 0);


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
			bool operator()(const Drawable* l, const Drawable* r) { return (*l < *r); }
		};

		struct CompareFrontToBack
		{
			bool operator()(const Drawable* l, const Drawable* r) { return (*r < *l); }
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
}