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

namespace KatanaEngine
{
	enum class Button
	{
		A,
		B,
		X,
		Y,
		START,
		BACK,
		LEFT_STICK,
		LEFT_SHOULDER,
		RIGHT_STICK,
		RIGHT_SHOULDER,
		DPAD_UP,
		DPAD_DOWN,
		DPAD_LEFT,
		DPAD_RIGHT,
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

		bool IsButtonDown(Button button)
		{
			switch (button)
			{
			case Button::A: return (Buttons.A == ButtonState::PRESSED);
			case Button::B: return (Buttons.B == ButtonState::PRESSED);
			case Button::X: return (Buttons.X == ButtonState::PRESSED);
			case Button::Y: return (Buttons.Y == ButtonState::PRESSED);

			case Button::START: return (Buttons.Start == ButtonState::PRESSED);
			case Button::BACK: return (Buttons.Back == ButtonState::PRESSED);

			case Button::LEFT_STICK: return (Buttons.LeftStick == ButtonState::PRESSED);
			case Button::LEFT_SHOULDER: return (Buttons.LeftShoulder == ButtonState::PRESSED);
			case Button::RIGHT_STICK: return (Buttons.RightStick == ButtonState::PRESSED);
			case Button::RIGHT_SHOULDER: return (Buttons.RightShoulder == ButtonState::PRESSED);
			}

			return false;
		}

		bool IsButtonUp(Button button)
		{
			return !IsButtonDown(button);
		}
	};
}