
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

#pragma once

namespace KatanaEngine
{
	/** @brief Represents a 2D grid of texels. */
	class Texture : public Resource
	{

	public:

		Texture();
		virtual ~Texture();

		/** @brief Load the desired font into memory.
			@param path The path to the desired font.
			@param pManager A pointer to the ResourceManager that will manage the font.
			@return Returns true if the font was loaded, false otherwise. */
		virtual bool Load(const std::string &path, ResourceManager *pManager);

		/** @brief Gets the width of the texture in pixels.
			@return Returns the width in pixels. */
		int GetWidth() const { return m_width; }

		/** @brief Gets the height of the texture in pixels.
			@return Returns the height in pixels. */
		int GetHeight() const { return m_height; }

		/** @brief Gets the dimensions of the texture.
			@return Returns the dimensions. */
		Vector2 GetSize() const { return m_size; }

		/** @brief Gets the center position of the texture.
			@return Returns the center position. */
		Vector2 GetCenter() const { return m_center; }

		/** @brief Used to determine if the texture is cloneable.
			@return Returns true if the texture is clonable, false otherwise.
			@remark Textures should usually not be cloneable. */
		virtual bool IsCloneable() const { return false; }

		/** @brief Get the allegro bitmap representation of the texture.
			@return Returns the underlaying allegro bitmap. */
		virtual ALLEGRO_BITMAP *GetAllegroBitmap() const { return m_pBitmap; }


	protected:

		/** @brief Used to set the underlaying allegro bitmap.
			@param pBitmap The bitmap to set. */
		virtual void SetTexture(ALLEGRO_BITMAP *pBitmap);


	private:

		static bool s_alAddonInitialized;

		ALLEGRO_BITMAP *m_pBitmap;

		int m_width;
		int m_height;

		Vector2 m_size;
		Vector2 m_center;

	};
}