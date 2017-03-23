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

   File: ScreenManager.cpp
   Description: Source file for screen management.

/  --------------------------------------------------------------- */

#include "KatanaEngine.h"


ScreenManager::ScreenManager(Game *pGame)
{
	m_pGame = pGame;
}

ResourceManager *ScreenManager::GetResourceManager() const
{
	return GetGame()->GetResourceManager();
}

void ScreenManager::HandleInput(InputState *pInput)
{
	if (m_screens.size() > 0)
	{
		bool update = true;

		for (m_rit = m_screens.rbegin(); m_rit != m_screens.rend(); ++m_rit)
		{
			Screen *pScreen = *m_rit;

			if (update)
			{
				if (!pScreen->NeedsToBeRemoved())
				{
					pScreen->HandleInput(pInput);
					update = pScreen->HandleInputBelow();
				}
			}
			else break;
		}
	}
}

void ScreenManager::Update(const GameTime *pGameTime)
{		
	Screen *pScreen;

	if (m_screensToAdd.size() > 0)
	{
		m_screens.insert(m_screens.end(), m_screensToAdd.begin(), m_screensToAdd.end());
		m_screensToAdd.clear();
	}

	if (m_screens.size() > 0)
	{
		bool update = true;

		for (m_rit = m_screens.rbegin(); m_rit != m_screens.rend(); ++m_rit)
		{
			pScreen = *m_rit;

			pScreen->UpdateTransition(pGameTime);

			if (pScreen->NeedsToBeRemoved())
			{
				m_screensToRemove.push_back(pScreen);
			}
			else if (update)
			{
				pScreen->Update(pGameTime);
				update = pScreen->UpdateBelow();
			}
		}
	}
		
	if (m_screensToRemove.size() > 0)
	{
		for (m_it = m_screensToRemove.begin(); m_it != m_screensToRemove.end(); ++m_it)
		{
			pScreen = *m_it;

			if (pScreen->OnRemove) pScreen->OnRemove(pScreen);

			pScreen->UnloadContent();

			m_screens.erase(std::remove(m_screens.begin(), m_screens.end(), pScreen), m_screens.end());

			delete pScreen;
		}
		
		m_screensToRemove.clear();
	}
}

void ScreenManager::Draw(const GameTime *pGameTime)
{
	Screen *pScreen;

	if (m_screens.size() > 0)
	{
		for (m_rit = m_screens.rbegin(); m_rit != m_screens.rend(); ++m_rit)
		{
			pScreen = *m_rit;

			if (!pScreen->NeedsToBeRemoved())
			{
				m_screensToDraw.push_back(pScreen);
				
				if (!pScreen->DrawBelow()) break;
			}
		}
	}

	if (m_screensToDraw.size() > 0)
	{
		for (m_rit = m_screensToDraw.rbegin(); m_rit != m_screensToDraw.rend(); ++m_rit)
		{
			(*m_rit)->Draw(pGameTime);
		}

		m_screensToDraw.clear();
	}
}

void ScreenManager::AddScreen(Screen *pScreen)
{
	pScreen->SetScreenManager(this);
	pScreen->LoadContent();

	m_screensToAdd.push_back(pScreen);
}
