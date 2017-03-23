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

   File: InputState.h
   Description: Header file for handling player input.

/  --------------------------------------------------------------- */

#pragma once


class InputState
{
	friend class Game;

public:

	static const int MAX_NUM_GAMEPADSTATES = 4;

	InputState();
	virtual ~InputState() { }

	bool IsKeyDown(const int key) const;
	bool IsKeyUp(const int key) const;
	bool IsNewKeyPress(const int key) const;

	Vector2 GetMousePosition() const { return Vector2(m_currentMouseState.x, m_currentMouseState.y); }
	bool IsMouseButtonDown(MouseButtons button) { return (m_currentMouseState.buttons & button); }
	bool IsMouseButtonUp(MouseButtons button) { return !IsMouseButtonDown(button); }
	bool WasMouseButtonDown(MouseButtons button) { return (m_previousMouseState.buttons & button); }
	bool WasMouseButtonUp(MouseButtons button) { return !WasMouseButtonDown(button); }
	bool IsNewMouseButtonPress(MouseButtons button) { return (IsMouseButtonDown(button) && WasMouseButtonUp(button)); }
	bool IsNewMouseButtonRelease(MouseButtons button) { return (WasMouseButtonDown(button) && IsMouseButtonUp(button)); }

	bool IsButtonUp(Buttons button, int &indexOut, int controllingIndex = -1);
	bool IsButtonDown(Buttons button, int &indexOut, int controllingIndex = -1);
	bool IsNewButtonPress(Buttons button, int &indexOut, int controllingIndex = -1);
	
	void UpdateConfigurationEvent();
	void UpdateAxisEvent(ALLEGRO_EVENT alEvent);
	void UpdateButtonEvent(ALLEGRO_EVENT alEvent, ButtonState state);

	int GetGamePadIndex(ALLEGRO_JOYSTICK *pId);

	GamePadState &GetGamePadState(const int gamePadIndex);


private:

	ALLEGRO_KEYBOARD_STATE m_currentKeyboardState;
	ALLEGRO_KEYBOARD_STATE m_previousKeyboardState;
		
	ALLEGRO_MOUSE_STATE m_currentMouseState;
	ALLEGRO_MOUSE_STATE m_previousMouseState;

	GamePadState m_currentGamePadStates[MAX_NUM_GAMEPADSTATES];
	GamePadState m_previousGamePadStates[MAX_NUM_GAMEPADSTATES];

	std::map<ALLEGRO_JOYSTICK *, int> m_map;

	void Update();

	void InitializeGamePads();

};
