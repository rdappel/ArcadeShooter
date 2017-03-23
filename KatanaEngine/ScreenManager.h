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

   File: ScreenManager.h
   Description: Header file for screen management.

/  --------------------------------------------------------------- */

#pragma once


class Game;

class ScreenManager
{
	friend class Game;

public:

	ScreenManager(Game *pGame);
	virtual ~ScreenManager() { }

	bool InTransition() const { return false; }

	Game *GetGame() const { return m_pGame; }

	ResourceManager *GetResourceManager() const;

	virtual void AddScreen(Screen *pScreen);

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(const GameTime *pGameTime);


private:

	Game *m_pGame;

	std::vector<Screen *> m_screens;
	std::vector<Screen *> m_screensToAdd;
	std::vector<Screen *> m_screensToRemove;
	std::vector<Screen *> m_screensToDraw;
	
	std::vector<Screen *>::iterator m_it;
	std::vector<Screen *>::reverse_iterator m_rit;

	virtual void HandleInput(InputState *pInput);
};
