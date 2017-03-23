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

	File: GameTime.cpp
	Description: Source file for the game's timing values.

/  --------------------------------------------------------------- */

#include "KatanaEngine.h"


GameTime::GameTime()
{
	m_previousTotalTime = al_get_time();
	m_currentTotalTime = al_get_time();
	m_elapsedTime = 0.0;
}

// Updates the timing values
void GameTime::Update()
{
	m_previousTotalTime = m_currentTotalTime;
	m_currentTotalTime = al_get_time();
	m_elapsedTime = (m_currentTotalTime - m_previousTotalTime);
}
