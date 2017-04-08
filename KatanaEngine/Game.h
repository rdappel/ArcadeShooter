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
	/** @brief Base class for all games. Provides graphics initialization, game loop, and rendering code. */
	class Game
	{

	public:

		Game();
		virtual ~Game();

		/** @brief Runs the game instance.
			@return Error code for exit status. */
		virtual int Run();


		/** @brief Gets the screen width in pixels.
			@return The width in pixels. */
		static int GetScreenWidth() { return s_screenWidth; }

		/** @brief Gets the screen width in pixels.
			@return The width in pixels. */
		static int GetScreenHeight() { return s_screenHeight; }

		/** @brief Gets the screen size in pixels.
			@return A Point representing the width and height of the screen. */
		static Point GetScreenCenter() { return (Point(s_screenWidth / 2, s_screenHeight / 2)); }

		/** @brief Gets the name of the game.
			@return The name of the game. */
		virtual std::string GetName() const = 0;

		/** @brief Gets a pointer to the ResourceManager, for loading and managing resources.
			@return A pointer to the game's ResourceManager instance. */
		virtual ResourceManager *GetResourceManager() const { return m_pResourceManager; }

		/** @brief Gets a pointer to the ScreenManager, for managing game screens.
			@return A pointer to the game's ScreenManager instance. */
		virtual ScreenManager *GetScreenManager() const { return m_pScreenManager; }

		/** @brief Gets a pointer to the ParticleManager, for managing particle effects.
			@return A pointer to the game's ParticleManager instance. */
		virtual ParticleManager *GetParticleManager() const { return m_pParticleManager; }

		/** @brief Gets a pointer to the SpriteBatch, for rendering.
			@return A pointer to the game's SpriteBatch instance. */
		virtual SpriteBatch *GetSpriteBatch() const { return m_pSpriteBatch; }

		/** @brief Called when resources need to be loaded. */
		virtual void LoadContent() { }

		/** @brief Called when resources need to be unloaded. Override this method to unload
			any game-specific resources. */
		virtual void UnloadContent() { }

		/** @brief Called when the game has determined that game logic needs to be processed.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime);

		/** @brief Called when the game determines it is time to draw a frame.
			@param pGameTime Timing values including time since last update. */
		virtual void Draw(const GameTime *pGameTime);

		/** @brief Quits the game. */
		virtual void Quit() { m_isRunning = false; }


	protected:

		/** @brief Sets the screen resolution.
			@param width The width of the screen in pixels.
			@param height The height of the screen in pixels. */
		static void SetScreenResolution(int width, int height) { s_screenWidth = width; s_screenHeight = height; }

		/** @brief Sets the title of the game window.
			@param title The window title.
			@remark If the window title is not set, the game's name will be displayed in the title. */
		static void SetWindowTitle(std::string title) { s_windowTitle = title; }

		/** @brief Sets the location of the directory where the game's resources are stored.
			@param path The relative path to the resource directory. */
		void SetResourceDirectory(const std::string &path) { m_pResourceManager->SetContentPath(path); }

		/** @brief Sets the target frame rate for the game.
			@param frames The target number of frames per second. */
		void SetTargetFramesPerSecond(int const frames);

		/** @brief Sets the font for the frame counter.
			@param pFont A pointer to the font. */
		void SetFrameCounterFont(Font *pFont) { m_pFrameCounterFont = pFont; }

		/** @brief Initializes the game's ScreenManager. */
		void InitializeScreenManager() { m_pScreenManager = new ScreenManager(this); }

		/** @brief Initializes the game's ParticleManager. */
		void InitializeParticleManager() { m_pParticleManager = new ParticleManager(this); }

		/** @brief Displays the game's current frame rate. */
		void DisplayFrameRate();

		/** @brief Sets the game to display in fullscreen mode. */
		void SetFullScreen(bool isFullScreen) { m_isFullScreen = isFullScreen; }

		/** @brief Sets the OpenGL flag, which forces OpenGL rendering. */
		void SetOpenGLFlag() { m_requireOpenGL = true; }


	private:

		static int s_screenWidth;
		static int s_screenHeight;

		static std::string s_windowTitle;
		static std::string s_contentDirectory;

		bool m_isInitialized;
		bool m_isRunning;
		bool m_isFullScreen;
		bool m_requireOpenGL;

		double m_targetFramesPerSecond;
		double m_inverseTargetFrames;
		double m_actualFramesPerSec;
		double m_currentTime;
		double m_previousTime;
		float m_frameCounter;

		GameTime *m_pGameTime;
		InputState *m_pInput;

		SpriteBatch *m_pSpriteBatch;

		ScreenManager *m_pScreenManager;
		ParticleManager *m_pParticleManager;
		ResourceManager *m_pResourceManager;

		Font *m_pFrameCounterFont;

		bool IsRunning() { return m_isRunning; }
	};
}