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

#include "KatanaEngine.h"

namespace KatanaEngine
{
	Screen::Screen()
	{
		m_isExiting = false;
		m_needsToBeRemoved = false;

		m_transitionInTime = 0.0;
		m_transitionOutTime = 0.0;

		m_pScreenManager = nullptr;

		m_transition = ScreenTransition::NONE;

		m_transitionValue = 0.0f;

		m_onExit = nullptr;
		m_onRemove = nullptr;

		SetPassThroughFlags();
	}

	void Screen::UpdateTransition(const GameTime *pGameTime)
	{
		if (m_transition != ScreenTransition::NONE)
		{
			m_transitionTime -= pGameTime->GetTimeElapsed();

			if (m_transition == ScreenTransition::IN)
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

			if (m_transition == ScreenTransition::OUT)
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
				m_transition = ScreenTransition::NONE;

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

		if (m_onExit) ((OnExit)m_onExit)(this);
	}

	void Screen::TransitionIn()
	{
		if (m_transition == ScreenTransition::NONE)
		{
			m_transitionTime = m_transitionInTime;
			m_transition = ScreenTransition::IN;
		}
	}

	void Screen::TransitionOut()
	{
		if (m_transition == ScreenTransition::NONE)
		{
			m_transitionTime = m_transitionOutTime;
			m_transition = ScreenTransition::OUT;
		}
	}

	Game *Screen::GetGame() const
	{
		return m_pScreenManager->GetGame();
	}
	
	ParticleManager *Screen::GetParticleManager() const
	{
		return GetGame()->GetParticleManager();
	}

	void Screen::SetPassThroughFlags(const bool draw, const bool update, const bool handleInput)
	{
		m_drawBelow = draw;
		m_updateBelow = update;
		m_handleInputBelow = handleInput;
	}
}