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

   File: Screen.cpp
   Description: Source file for a game screen.

/  --------------------------------------------------------------- */

#include "KatanaEngine.h"


Screen::Screen()
{
	m_isExiting = false;
	m_needsToBeRemoved = false;

	m_transitionInTime = 0.0;
	m_transitionOutTime = 0.0;

	m_pScreenManager = nullptr;

	m_transition = SCREENTRANS_NONE;

	m_transitionValue = 0.0f;

	OnExit = nullptr;
	OnRemove = nullptr;

	SetPassThroughFlags();
}

void Screen::UpdateTransition(const GameTime *pGameTime)
{
	if (m_transition != SCREENTRANS_NONE)
	{
		m_transitionTime -= pGameTime->GetTimeElapsed();

		if (m_transition == SCREENTRANS_IN)
		{
			if (m_transitionInTime > 0)
			{
				m_transitionValue = 1 - (float)m_transitionTime / (float)m_transitionInTime;
			}
			else
			{
				m_transitionValue = 0;
			}
		}
		
		if (m_transition == SCREENTRANS_OUT)
		{
			if (m_transitionOutTime > 0)
			{
				m_transitionValue = (float)m_transitionTime / (float)m_transitionOutTime;
			}
			else
			{
				m_transitionValue = 0;
			}
		}

		if (m_transitionValue < 0) m_transitionValue = 0;
		if (m_transitionValue > 1) m_transitionValue = 1;
		
		if (m_transitionTime <= 0)
		{
			m_transitionTime = 0;
			m_transition = SCREENTRANS_NONE;

			if (m_isExiting)
			{
				m_needsToBeRemoved = true;
			}
		}
	}
}

void Screen::SetScreenManager(ScreenManager *pScreenManager)
{
	m_pScreenManager = pScreenManager;
}

void Screen::Show()
{
	TransitionIn();
}

void Screen::Exit()
{
	m_isExiting = true;

	TransitionOut();
	
	if (OnExit)	OnExit(this);
}

void Screen::TransitionIn()
{
	if (m_transition == SCREENTRANS_NONE)
	{
		m_transitionTime = m_transitionInTime;
		m_transition = SCREENTRANS_IN;
	}
}

void Screen::TransitionOut()
{
	if (m_transition == SCREENTRANS_NONE)
	{
		m_transitionTime = m_transitionOutTime;
		m_transition = SCREENTRANS_OUT;
	}
}

Game *Screen::GetGame() const
{
	return m_pScreenManager->GetGame();
}

ResourceManager *Screen::GetResourceManager() const
{
	if (m_pScreenManager == nullptr) return nullptr;

	return m_pScreenManager->GetResourceManager();
}

void Screen::SetPassThroughFlags(const bool handleInput, const bool update, const bool draw)
{
	m_handleInputBelow = handleInput;
	m_updateBelow = update;
	m_drawBelow = draw;
}