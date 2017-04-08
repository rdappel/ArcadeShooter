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

#pragma once

namespace KatanaEngine
{

	/** @brief Handles the state of multiple player input devices. */
	class InputState
	{
		friend class Game;

	public:

		/** @brief The maximum number of Xbox controllers that the system can manage. */
		static const int MAX_NUM_GAMEPADSTATES = 4;

		InputState();
		virtual ~InputState() { }

		/** @brief Determines if a keyboard key is currently being pressed down.
			@param key The key to test.
			@return Returns true if the key is down, false otherwise. */
		bool IsKeyDown(Key key) const;

		/** @brief Determines if a keyboard key is currently not being pressed down.
			@param key The key to test.
			@return Returns true if the key is up, false otherwise. */
		bool IsKeyUp(Key key) const;

		/** @brief Determines if a keyboard key was just pressed this frame.
			@param key The key to test.
			@return Returns true if the key was just pressed, false otherwise. */
		bool IsNewKeyPress(Key key) const;

		/** @brief Determines if a keyboard key was just released this frame.
			@param key The key to test.
			@return Returns true if the key was just released, false otherwise. */
		bool IsNewKeyRelease(Key key) const;


		/** @brief Gets the current screen position of the mouse cursor.
			@return Returns the mouse position coordinates. */
		Point GetMousePosition() const { return Point(m_currentMouseState.x, m_currentMouseState.y); }

		/** @brief Determines if a mouse button is currently being pressed down.
			@param button The button to test.
			@return Returns true if the button is down, false otherwise. */
		bool IsMouseButtonDown(MouseButton button) { return (m_currentMouseState.buttons & (int)button); }

		/** @brief Determines if a mouse button is currently not being pressed down.
			@param button The button to test.
			@return Returns true if the button is up, false otherwise. */
		bool IsMouseButtonUp(MouseButton button) { return !IsMouseButtonDown(button); }

		/** @brief Determines if a mouse button was being pressed down during the previous frame.
			@param button The button to test.
			@return Returns true if the button was down during the last frame, false otherwise. */
		bool WasMouseButtonDown(MouseButton button) { return (m_previousMouseState.buttons & (int)button); }

		/** @brief Determines if a mouse button was not being pressed down during the previous frame.
			@param button The button to test.
			@return Returns true if the button was up during the last frame, false otherwise. */
		bool WasMouseButtonUp(MouseButton button) { return !WasMouseButtonDown(button); }

		/** @brief Determines if a mouse button was just pressed this frame.
			@param button The button to test.
			@return Returns true if the button was just pressed, false otherwise. */
		bool IsNewMouseButtonPress(MouseButton button) { return (IsMouseButtonDown(button) && WasMouseButtonUp(button)); }
		
		/** @brief Determines if a mouse button was just released this frame.
			@param button The button to test.
			@return Returns true if the button was just released, false otherwise. */
		bool IsNewMouseButtonRelease(MouseButton button) { return (WasMouseButtonDown(button) && IsMouseButtonUp(button)); }


		/** @brief Determines if a the button on an Xbox controller is up.
			@param button The button to test.
			@param indexOut The index of the controller with the released button.
			@param controllingIndex The index of the controller to test. If the controllingIndex
			is not valid, all controllers will be tested indexOut will be set to the first detected
			index matching the condition.
			@return Returns true if the button is up, false otherwise. */
		bool IsButtonUp(Button button, int &indexOut, int controllingIndex = -1);

		/** @brief Determines if a the button on an Xbox controller is down.
			@param button The button to test.
			@param indexOut The index of the controller with the pressed button.
			@param controllingIndex The index of the controller to test. If the controllingIndex
			is not valid, all controllers will be tested indexOut will be set to the first detected
			index matching the condition.
			@return Returns true if the button is down, false otherwise. */
		bool IsButtonDown(Button button, int &indexOut, int controllingIndex = -1);

		/** @brief Determines if a the button on an Xbox controller was just pressed this frame.
			@param button The button to test.
			@param indexOut The index of the controller with the pressed button.
			@param controllingIndex The index of the controller to test. If the controllingIndex
			is not valid, all controllers will be tested indexOut will be set to the first detected
			index matching the condition.
			@return Returns true if the button was just pressed, false otherwise. */
		bool IsNewButtonPress(Button button, int &indexOut, int controllingIndex = -1);

		/** @brief Determines if a the button on an Xbox controller just released this frame.
			@param button The button to test.
			@param indexOut The index of the controller with the released button.
			@param controllingIndex The index of the controller to test. If the controllingIndex
			is not valid, all controllers will be tested indexOut will be set to the first detected
			index matching the condition.
			@return Returns true if the button was just released, false otherwise. */
		bool IsNewButtonRelease(Button button, int &indexOut, int controllingIndex = -1);

		/** @brief Get the current state of an Xbox controller.
			@param gamePadIndex The index of the desired game pad state.
			@return The game pad's current state. */
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

		int GetGamePadIndex(ALLEGRO_JOYSTICK *pId);

		void InitializeGamePads();

		void UpdateConfigurationEvent();
		void UpdateAxisEvent(ALLEGRO_EVENT alEvent);
		void UpdateButtonEvent(ALLEGRO_EVENT alEvent, ButtonState state);

	};
}