
/*	 ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗ 
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
        Katana Engine \/ © 2012 - Shuriken Studios LLC              */

#pragma once

namespace KatanaEngine
{
	/** @brief Represents a font or true-type font. */
	class Font : public Resource
	{

	public:

		Font() { }
		virtual ~Font() { al_destroy_font(m_pFont); }

		/** @brief Specifies the size of the font when loaded.
		@param size The desired size of the font.
		@param restore To determine if the load size should revert back to previous after the next font
		is loaded. */
		static void SetLoadSize(const int size, const bool restore = false);

		/** @brief Sets which characters to use when using a bitmap as a font.
			@param rangeCount The length of the ranges array.
			@param ranges The character ranges.
			@remark See https://www.allegro.cc/manual/5/al_grab_font_from_bitmap for more information. */
		static void SetCharacterRange(const int rangeCount, int ranges[]);

		/** @brief Load the desired font into memory.
			@param path The path to the desired font.
			@param pManager A pointer to the ResourceManager that will manage the font.
			@return Returns true if the font was loaded, false otherwise. */
		virtual bool Load(const std::string &path, ResourceManager *pManager);

		/** @brief Gets the line height of the font in pixels.
			@return Returns the line height in pixels. */
		virtual int GetLineHeight() const { return al_get_font_line_height(m_pFont); }

		/** @brief Gets the width in pixels of the specified string.
			@param text The string to measure.
			@return Returns the width in pixels. */
		virtual int GetTextWidth(const char *text) const { return al_get_text_width(m_pFont, text); }

		/** @brief Used to determine if the font is cloneable.
			@return Returns true if the font is clonable, false otherwise.
			@remark Fonts should usually not be cloneable. */
		virtual bool IsCloneable() const { return false; }

		/** @brief Get the allegro font representation of the texture.
			@return Returns the underlaying allegro font. */
		virtual ALLEGRO_FONT *GetAllegroFont() const { return m_pFont; }


	private:

		static int s_fontSize;
		static int s_restoreSize;

		static bool s_alAddonInitialized;

		static int s_rangeCount;
		static int *s_ranges;

		ALLEGRO_FONT *m_pFont;

	};
}