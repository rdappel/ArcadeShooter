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

   File: Screen.h
   Description: Header file for a game screen.

/  --------------------------------------------------------------- */

#pragma once


class ScreenManager;

class Screen
{
	friend class ScreenManager;

public:	

	Screen();
	virtual ~Screen() { }


	void (*OnExit)(Screen *pScreen);

	void (*OnRemove)(Screen *pScreen);


	virtual void LoadContent() { }

	virtual void UnloadContent() {  }

	virtual void HandleInput(InputState *pInput) { }

	virtual void Update(const GameTime *pGameTime) = 0;

	virtual void Draw(const GameTime *pGameTime) = 0;

	virtual bool UpdateBelow() const { return m_updateBelow; }

	virtual bool DrawBelow() const { return m_drawBelow; }

	virtual bool HandleInputBelow() const { return m_handleInputBelow; }

	virtual bool IsExiting() const { return m_isExiting; }

	virtual bool NeedsToBeRemoved() const { return m_needsToBeRemoved; }

	float GetAlpha() const { return m_transitionValue; }

	virtual ScreenManager *GetScreenManager() { return m_pScreenManager; }

	virtual Game *GetGame() const;

	virtual ResourceManager *GetResourceManager() const;

	virtual void SetScreenManager(ScreenManager *pScreenManager);

	virtual void Show();
	
	virtual void Exit();


protected:

	enum ScreenTransition { SCREENTRANS_NONE, SCREENTRANS_IN, SCREENTRANS_OUT };

	void SetPassThroughFlags(const bool handleInput = false, const bool update = false, const bool draw = false);

	void SetTransitionInTime(double seconds) { m_transitionInTime = seconds; }
	void SetTransitionOutTime(double seconds) { m_transitionOutTime = seconds; }
	
	ScreenTransition GetTransition() const { return m_transition; }

	float GetTransitionValue() const { return m_transitionValue; }


private:

	bool m_handleInputBelow;
	bool m_updateBelow;
	bool m_drawBelow;
	bool m_isExiting;
	
	bool m_needsToBeRemoved;

	double m_transitionInTime;
	double m_transitionOutTime;

	ScreenTransition m_transition;
	float m_transitionValue;
	double m_transitionTime;

	ScreenManager *m_pScreenManager;

	void TransitionIn();
	void TransitionOut();

	void UpdateTransition(const GameTime *pGameTime);

};
