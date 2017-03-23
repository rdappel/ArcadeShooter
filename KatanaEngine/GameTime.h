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

	File: GameTime.h
	Description: Header file for the game's timing values.

/  --------------------------------------------------------------- */

#pragma once


class GameTime
{
	friend class Game;

public:

	GameTime();
	virtual ~GameTime() { }

	// Gets the time in seconds since last frame.
	double GetTimeElapsed() const { return m_elapsedTime; }

	// Gets the time in seconds since the game started.
	double GetTotalTime() const { return m_currentTotalTime; }


private:

	void Update();

	double m_currentTotalTime;
	double m_previousTotalTime;
	double m_elapsedTime;
};
