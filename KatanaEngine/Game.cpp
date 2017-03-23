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

   File: Game.cpp
   Description: Source file for the game base class.

/  --------------------------------------------------------------- */

#include "KatanaEngine.h"


// Static Members
int Game::s_screenWidth = 800;
int Game::s_screenHeight = 600;

std::string Game::s_contentDirectory = "..\\Content\\";
std::string Game::s_windowTitle = "Game";


Game::Game()
{
	m_isInitialized = al_init();

	al_install_audio();
	al_init_acodec_addon();

	m_requireOpenGL = false;

	m_pInput = nullptr;
	m_pFrameCounterFont = nullptr;

	m_currentTime = 0;
	m_previousTime = al_get_time();
	m_frameCounter = 0;
	m_actualFramesPerSec = 0;
	SetTargetFramesPerSecond(60);

	m_pResourceManager = new ResourceManager;
	m_pScreenManager = nullptr;
	//m_pParticleManager = nullptr;

	m_pSpriteBatch = new SpriteBatch;

	srand(time(nullptr));
}


Game::~Game()
{
	m_pResourceManager->UnloadAllResources();

	delete m_pResourceManager;
	//delete m_pSpriteBatch;
	delete m_pInput;
	delete m_pGameTime;
}


void Game::Update(const GameTime *pGameTime)
{
	if (GetScreenManager())
	{
		GetScreenManager()->HandleInput(m_pInput);
		GetScreenManager()->Update(m_pGameTime);
	}

	/*if (GetParticleManager())
	{
		GetParticleManager()->Update(m_pGameTime);
	}*/
}

void Game::Draw(const GameTime *pGameTime)
{
	if (GetScreenManager())
	{
		GetScreenManager()->Draw(m_pGameTime);
	}

	/*if (GetParticleManager())
	{
		GetParticleManager()->Draw(m_pGameTime);
	}*/
}


int Game::Run()
{
	m_isRunning = true;

	if (!m_isInitialized)
	{
		const char message[] = "Failed to initialize the game.";
		al_show_native_message_box(nullptr, nullptr, nullptr, message, nullptr, 0);
		return -1;
	}

	al_set_new_display_option(ALLEGRO_VSYNC, 1, ALLEGRO_REQUIRE);
	if (m_isFullScreen) al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	if (m_requireOpenGL) al_set_new_display_flags(ALLEGRO_OPENGL);

	ALLEGRO_DISPLAY *pDisplay = al_create_display(GetScreenWidth(), GetScreenHeight());
	if (!pDisplay)
	{
		const char message[] = "Failed to initialize display.";
		al_show_native_message_box(nullptr, nullptr, nullptr, message, nullptr, 0);
		return -1;
	}

	al_set_window_title(pDisplay, s_windowTitle.c_str());
	al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);
	al_inhibit_screensaver(true);

	RenderTarget::SetDisplay(pDisplay);

	// Create and register events
	bool redraw = true;

	ALLEGRO_EVENT_QUEUE *pEventQueue = al_create_event_queue();
	ALLEGRO_TIMER *pTimer = al_create_timer(m_inverseTargetFrames);

	al_register_event_source(pEventQueue, al_get_timer_event_source(pTimer));
	al_register_event_source(pEventQueue, al_get_display_event_source(pDisplay));

	ALLEGRO_EVENT_SOURCE *joystickEventSource = al_get_joystick_event_source();
	if (joystickEventSource)
	{
		al_register_event_source(pEventQueue, joystickEventSource);
	}

	m_pInput = new InputState;
	m_pGameTime = new GameTime;

	LoadContent();

	al_start_timer(pTimer);
	ALLEGRO_EVENT alEvent;

	while (IsRunning())
	{
		al_wait_for_event(pEventQueue, &alEvent);

		switch (alEvent.type)
		{
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			al_stop_timer(pTimer);
			Quit();
			break;

		case ALLEGRO_EVENT_TIMER:
			m_pGameTime->Update();
			m_pInput->Update();
			Update(m_pGameTime);
			redraw = true;
			break;

		case ALLEGRO_EVENT_JOYSTICK_CONFIGURATION:
			m_pInput->UpdateConfigurationEvent();
			break;

		case ALLEGRO_EVENT_JOYSTICK_AXIS:
			m_pInput->UpdateAxisEvent(alEvent);
			break;
		case ALLEGRO_EVENT_JOYSTICK_BUTTON_UP:
			m_pInput->UpdateButtonEvent(alEvent, BUTTONSTATE_RELEASED);
			break;
		case ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN:
			m_pInput->UpdateButtonEvent(alEvent, BUTTONSTATE_PRESSED);
			break;
		}

		if (redraw && al_event_queue_is_empty(pEventQueue))
		{
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			Draw(m_pGameTime);

			m_frameCounter++;

			al_flip_display();
		}
	}

	UnloadContent();

	al_destroy_display(pDisplay);
	
	return 0;
}

void Game::DisplayFrameRate()
{
	m_currentTime = al_get_time();

	if (m_currentTime - m_previousTime >= 1.0)
	{
		m_actualFramesPerSec = m_frameCounter / (m_currentTime - m_previousTime);
		m_frameCounter = 0;
		m_previousTime = m_currentTime;
	}
	
	if (m_pFrameCounterFont)
	{
		Color color(0, 1, 0);

		float percent = (float)(m_actualFramesPerSec * m_inverseTargetFrames);

		if (percent >= 1)
		{
			color = Color::Lerp(color, Color(0, 0.5, 0), 0.1f);
		}
		if (percent < 1 && percent >= 0.8f)
		{
			color = Color::Lerp(color, Color(1, 1, 0), 0.1f);
		}
		else if (percent < 0.8f && percent >= 0.6f)
		{
			color = Color::Lerp(color, Color(1, 0.5, 0), 0.1f);
		}
		else if (percent < 0.6f)
		{
			color = Color::Lerp(color, Color(1, 0, 0), 0.1f);
		}

		char buffer[16];
		sprintf_s(buffer, "FPS: %.2f", (float)m_actualFramesPerSec);
		std::string text = buffer;

		m_pSpriteBatch->Begin();
		m_pSpriteBatch->DrawString(m_pFrameCounterFont, &text, Vector2(10, 10), color);
		m_pSpriteBatch->End();
	}
	else
	{
		std::cout << "FPS: " << m_actualFramesPerSec << std::endl;
	}
}

void Game::SetTargetFramesPerSecond(int const frames)
{
	m_targetFramesPerSecond = frames;
	m_inverseTargetFrames = 1.0 / frames;
}

void Game::SetFrameCounterFont(const std::string &path)
{
	m_pFrameCounterFont = GetResourceManager()->Load<Font>(path, false);
}