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

   File: GamePadState.h
   Description: Header file for game pad structures and
   enumerations.

/  --------------------------------------------------------------- */

#pragma once


enum Buttons
{
	BUTTON_A,
	BUTTON_B,
	BUTTON_X,
	BUTTON_Y,
	BUTTON_START,
	BUTTON_BACK,
	BUTTON_LEFTSTICK,
	BUTTON_LEFTSHOULDER,
	BUTTON_RIGHTSTICK,
	BUTTON_RIGHTSHOULDER,
	BUTTON_DPADUP,
	BUTTON_DPADDOWN,
	BUTTON_DPADLEFT,
	BUTTON_DPADRIGHT,
};

struct DPad
{
	ButtonState Up;
	ButtonState Down;
	ButtonState Left;
	ButtonState Right;
};

struct GamePadTriggers
{
	float Left;
	float Right;
};

struct GamePadThumbSticks
{
	Vector2 Left;
	Vector2 Right;
};

struct GamePadButtons
{
	ButtonState A;
	ButtonState B;
	ButtonState X;
	ButtonState Y;

	ButtonState Start;
	ButtonState Back;

	ButtonState LeftStick;
	ButtonState LeftShoulder;
	ButtonState RightStick;
	ButtonState RightShoulder;
};

struct GamePadState
{
	ALLEGRO_JOYSTICK *ID;
	bool IsConnected;
	GamePadButtons Buttons;
	GamePadThumbSticks Thumbsticks;
	GamePadTriggers Triggers;
	DPad Dpad;

	bool IsButtonDown(int button)
	{
		switch (button)
		{
		case BUTTON_A: return (Buttons.A == BUTTONSTATE_PRESSED);
		case BUTTON_B: return (Buttons.B == BUTTONSTATE_PRESSED);
		case BUTTON_X: return (Buttons.X == BUTTONSTATE_PRESSED);
		case BUTTON_Y: return (Buttons.Y == BUTTONSTATE_PRESSED);

		case BUTTON_START: return (Buttons.Start == BUTTONSTATE_PRESSED);
		case BUTTON_BACK: return (Buttons.Back == BUTTONSTATE_PRESSED);

		case BUTTON_LEFTSTICK: return (Buttons.LeftStick == BUTTONSTATE_PRESSED);
		case BUTTON_LEFTSHOULDER: return (Buttons.LeftShoulder == BUTTONSTATE_PRESSED);
		case BUTTON_RIGHTSTICK: return (Buttons.RightStick == BUTTONSTATE_PRESSED);
		case BUTTON_RIGHTSHOULDER: return (Buttons.RightShoulder == BUTTONSTATE_PRESSED);
		}

		return false;
	}

	bool IsButtonUp(int button)
	{
		return !IsButtonDown(button);
	}
};
