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
   Date: 5/6/2015

   File: Game.h
   Description: Header file for the game base class.

/  --------------------------------------------------------------- */

#pragma once


class Game
{

public:

	Game();
	virtual ~Game();


	int Run();


	static int GetScreenWidth() { return s_screenWidth; }

	static int GetScreenHeight() { return s_screenHeight; }

	static Vector2 GetScreenCenter() { return (Vector2(s_screenWidth, s_screenHeight) / 2); }


	ResourceManager *GetResourceManager() const { return m_pResourceManager; }

	ScreenManager *GetScreenManager() const { return m_pScreenManager; }

	//ParticleManager *GetParticleManager() const { return m_pParticleManager; }

	SpriteBatch *GetSpriteBatch() const { return m_pSpriteBatch; }


	virtual void LoadContent() { }

	virtual void UnloadContent() { }

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(const GameTime *pGameTime);

	virtual void Quit() { m_isRunning = false; }


protected:

	static void SetScreenResolution(int width, int height) { s_screenWidth = width; s_screenHeight = height; }

	static void SetWindowTitle(std::string title) { s_windowTitle = title; }

	void SetResourceDirectory(const std::string &path) { m_pResourceManager->SetContentPath(path); }

	bool IsRunning() { return m_isRunning; }

	void SetTargetFramesPerSecond(int const frames);

	void SetFrameCounterFont(const std::string &path);

	void InitializeScreenManager() { m_pScreenManager = new ScreenManager(this); }

	//void InitializeParticleManager() { m_pParticleManager = new ParticleManager(this); }

	void DisplayFrameRate();

	void SetFullScreen(bool isFullScreen) { m_isFullScreen = isFullScreen; }

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
	//ParticleManager *m_pParticleManager;
	ResourceManager *m_pResourceManager;

	Font *m_pFrameCounterFont;
};