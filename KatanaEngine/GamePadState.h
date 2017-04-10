
/*	 ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗ 
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
        Katana Engine \/ © 2012 - Shuriken Studios LLC              */

#pragma once

namespace KatanaEngine
{
	/** @brief Defines the possible states of a Button.
	    @see Button
	    @see GamePadDPad
		@see GamePadTriggers
		@see GamePadThumbSticks
	    @see GamePadButtons
	    @see GamePadState */
	enum class ButtonState
	{
		PRESSED,					/**< Represents the pressed state of a Button. */
		RELEASED					/**< Represents the released state of a Button. */
	};

	/** @brief Defines the buttons for an Xbox Controller.
		@see ButtonState
	    @see GamePadDPad
		@see GamePadTriggers
		@see GamePadThumbSticks
	    @see GamePadButtons
	    @see GamePadState */
	enum class Button
	{
		A,							/**< Represents the A Button on an Xbox Controller. */
		B,							/**< Represents the B Button on an Xbox Controller. */
		X,							/**< Represents the X Button on an Xbox Controller. */
		Y,							/**< Represents the Y Button on an Xbox Controller. */
		START,						/**< Represents the start Button on an Xbox Controller. */
		BACK,						/**< Represents the back Button on an Xbox Controller. */
		LEFT_STICK,					/**< Represents the left GamePadThumbstick on an Xbox Controller. */
		LEFT_SHOULDER,				/**< Represents the left shoulder Button on an Xbox Controller. */
		RIGHT_STICK,				/**< Represents the right GamePadThumbstick on an Xbox Controller. */
		RIGHT_SHOULDER,				/**< Represents the right shoulder Button on an Xbox Controller. */
		DPAD_UP,					/**< Represents the up section of the GamePadDPad on an Xbox Controller. */
		DPAD_DOWN,					/**< Represents the down section of the GamePadDPad on an Xbox Controller. */
		DPAD_LEFT,					/**< Represents the left section of the GamePadDPad on an Xbox Controller. */
		DPAD_RIGHT					/**< Represents the right section of the GamePadDPad on an Xbox Controller. */
	};

	/** @brief Identifies which directions on the directional pad of an Xbox Controller are being pressed.
	    @see Button
		@see ButtonState
		@see GamePadTriggers
		@see GamePadThumbSticks
	    @see GamePadButtons
	    @see GamePadState */
	struct GamePadDPad
	{
		ButtonState Up;				/**< The state of the Up Button on the directional pad. */
		ButtonState Down;			/**< The state of the Down Button on the directional pad. */
		ButtonState Left;			/**< The state of the Left Button on the directional pad. */
		ButtonState Right;			/**< The state of the Right Button on the directional pad. */
	};

	/** @brief Structure that defines the position of the left and right triggers on an Xbox Controller.
	    @see Button
		@see ButtonState
	    @see GamePadDPad
		@see GamePadThumbSticks
	    @see GamePadButtons
	    @see GamePadState */
	struct GamePadTriggers
	{
		float Left;					/**< The value of the Left Trigger. */
		float Right;				/**< The value of the Left Trigger. */
	};

	/** @brief Structure that represents the position of left and right sticks (thumbsticks) on an Xbox Controller.
	    @see Button
		@see ButtonState
	    @see GamePadDPad
		@see GamePadTriggers
	    @see GamePadButtons
	    @see GamePadState */
	struct GamePadThumbSticks
	{
		Vector2 Left;				/**< The position of the Left Thumbstick. */
		Vector2 Right;				/**< The position of the Right Thumbstick. */
	};

	/** @brief Identifies whether buttons on an Xbox Controller are pressed or released.
	    @see Button
		@see ButtonState
	    @see GamePadDPad
		@see GamePadTriggers
		@see GamePadThumbSticks
	    @see GamePadState */
	struct GamePadButtons
	{
		ButtonState A;				/**< The state of the A Button. */
		ButtonState B;				/**< The state of the B Button. */
		ButtonState X;				/**< The state of the X Button. */
		ButtonState Y;				/**< The state of the Y Button. */

		ButtonState Start;			/**< The state of the Start Button. */
		ButtonState Back;			/**< The state of the Back Button. */

		ButtonState LeftStick;		/**< The state of the Left Stick Button. */
		ButtonState LeftShoulder;	/**< The state of the Left Shoulder Button. */
		ButtonState RightStick;		/**< The state of the Right Stick Button. */
		ButtonState RightShoulder;	/**< The state of the Right Shoulder Button. */
	};

	/** @brief Represents specific information about the state of an Xbox Controller, including the current state of buttons and sticks.
	    @see Button
		@see ButtonState 
	    @see GamePadDPad
		@see GamePadTriggers
		@see GamePadThumbSticks
	    @see GamePadButtons */
	struct GamePadState
	{
		bool IsConnected;				/**< @brief True if the GamePad is connected, false otherwise. */
		GamePadButtons Buttons;			/**< @brief The current state of the GamePad's Buttons. */
		GamePadThumbSticks Thumbsticks;	/**< @brief The current state of the GamePad's Thumbsticks. */
		GamePadTriggers Triggers;		/**< @brief The current state of the GamePad's Triggers. */
		GamePadDPad Dpad;				/**< @brief The current state of the GamePad's Dpad. */
		ALLEGRO_JOYSTICK *ID;			/**< @brief The underlaying allegro joystick id. */

		/** @brief Determines if a button is pressed down.
			@param button The button to test.
			@return Returns true if the button is down, false otherwise. */
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

		/** @brief Determines if a button is up.
			@param button The button to test.
			@return Returns true if the button is up, false otherwise. */
		bool IsButtonUp(Button button) { return !IsButtonDown(button); }
	};
}