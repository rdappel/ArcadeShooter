
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
	/** @brief Contains a 2D texture that can be used as a render target. */
	class RenderTarget : public Texture
	{

	public:

		/** @brief Instantiate a render target object.
			@param width The width of the render target.
			@param height The height of the render target. */
		RenderTarget(const int width, const int height);
		virtual ~RenderTarget() { }


		/** @brief Set the desired target to render to when drawing.
			@param pTarget A pointer to the desired render target. */
		static void Set(RenderTarget *pTarget);

		/** @brief Set the display of the target.
			@param pDisplay A pointer to the display. */
		static void SetDisplay(ALLEGRO_DISPLAY *pDisplay) { s_pDisplay = pDisplay; }

		/** @brief Render targets don't need to be loaded so this simply returns true.
			@param path The path to the desired resource.
			@param pManager A pointer to the ResourceManager that will manage the resource.
			@return Returns true. */
		virtual bool Load(const std::string &path, ResourceManager *pManager) { return true; }

	private:

		static ALLEGRO_DISPLAY *s_pDisplay;

	};
}