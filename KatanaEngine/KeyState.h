
/*
     ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗ 
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
        Katana Engine \/ © 2012 - Shuriken Studios LLC
			    http://www.shurikenstudios.com
*/

#pragma once

namespace KatanaEngine
{

	/** @brief Defines the keys on a keyboard */
	enum class Key
	{
		A = 1,				/**< Represents the A Key on the keyboard. */
		B,					/**< Represents the B Key on the keyboard. */
		C,					/**< Represents the C Key on the keyboard. */
		D,					/**< Represents the D Key on the keyboard. */
		E,					/**< Represents the E Key on the keyboard. */
		F,					/**< Represents the F Key on the keyboard. */
		G,					/**< Represents the G Key on the keyboard. */
		H,					/**< Represents the H Key on the keyboard. */
		I,					/**< Represents the I Key on the keyboard. */
		J,					/**< Represents the J Key on the keyboard. */
		K,					/**< Represents the K Key on the keyboard. */
		L,					/**< Represents the L Key on the keyboard. */
		M,					/**< Represents the M Key on the keyboard. */
		N,					/**< Represents the N Key on the keyboard. */
		O,					/**< Represents the O Key on the keyboard. */
		P,					/**< Represents the P Key on the keyboard. */
		Q,					/**< Represents the Q Key on the keyboard. */
		R,					/**< Represents the R Key on the keyboard. */
		S,					/**< Represents the S Key on the keyboard. */
		T,					/**< Represents the T Key on the keyboard. */
		U,					/**< Represents the U Key on the keyboard. */
		V,					/**< Represents the V Key on the keyboard. */
		W,					/**< Represents the W Key on the keyboard. */
		X,					/**< Represents the X Key on the keyboard. */
		Y,					/**< Represents the Y Key on the keyboard. */
		Z,					/**< Represents the Z Key on the keyboard. */

		NUM_0,				/**< Represents the 0 Key on the keyboard. */
		NUM_1,				/**< Represents the 1 Key on the keyboard. */
		NUM_2,				/**< Represents the 2 Key on the keyboard. */
		NUM_3,				/**< Represents the 3 Key on the keyboard. */
		NUM_4,				/**< Represents the 4 Key on the keyboard. */
		NUM_5,				/**< Represents the 5 Key on the keyboard. */
		NUM_6,				/**< Represents the 6 Key on the keyboard. */
		NUM_7,				/**< Represents the 7 Key on the keyboard. */
		NUM_8,				/**< Represents the 8 Key on the keyboard. */
		NUM_9,				/**< Represents the 9 Key on the keyboard. */

		PAD_0,				/**< Represents the 0 Key on the keyboard number pad. */
		PAD_1,				/**< Represents the 1 Key on the keyboard number pad. */
		PAD_2,				/**< Represents the 2 Key on the keyboard number pad. */
		PAD_3,				/**< Represents the 3 Key on the keyboard number pad. */
		PAD_4,				/**< Represents the 4 Key on the keyboard number pad. */
		PAD_5,				/**< Represents the 5 Key on the keyboard number pad. */
		PAD_6,				/**< Represents the 6 Key on the keyboard number pad. */
		PAD_7,				/**< Represents the 7 Key on the keyboard number pad. */
		PAD_8,				/**< Represents the 8 Key on the keyboard number pad. */
		PAD_9,				/**< Represents the 9 Key on the keyboard number pad. */

		F1 = 47,			/**< Represents the F1 Key on the keyboard. */
		F2,					/**< Represents the F2 Key on the keyboard. */
		F3,					/**< Represents the F3 Key on the keyboard. */
		F4,					/**< Represents the F4 Key on the keyboard. */
		F5,					/**< Represents the F5 Key on the keyboard. */
		F6,					/**< Represents the F6 Key on the keyboard. */
		F7,					/**< Represents the F7 Key on the keyboard. */
		F8,					/**< Represents the F8 Key on the keyboard. */
		F9,					/**< Represents the F9 Key on the keyboard. */
		F10,				/**< Represents the F10 Key on the keyboard. */
		F11,				/**< Represents the F11 Key on the keyboard. */
		F12,				/**< Represents the F12 Key on the keyboard. */

		ESCAPE = 59,		/**< Represents the Escape Key on the keyboard. */
		TILDE,				/**< Represents the Tilde Key on the keyboard. */
		MINUS,				/**< Represents the Minus Key on the keyboard. */
		EQUALS,				/**< Represents the Equals Key on the keyboard. */
		BACKSPACE,			/**< Represents the Backspace Key on the keyboard. */
		TAB,				/**< Represents the Tab Key on the keyboard. */
		OPENBRACE,			/**< Represents the Open Brace Key on the keyboard. */
		CLOSEBRACE,			/**< Represents the Close Brace Key on the keyboard. */
		ENTER,				/**< Represents the Enter Key on the keyboard. */
		SEMICOLON,			/**< Represents the Semicolon Key on the keyboard. */
		QUOTE,				/**< Represents the Quote Key on the keyboard. */
		BACKSLASH,			/**< Represents the Backslash Key on the keyboard. */
		BACKSLASH2,			/**< Represents the Backslash2 Key on the keyboard. */
		COMMA,				/**< Represents the Comma Key on the keyboard. */
		FULLSTOP,			/**< Represents the Full Stop Key on the keyboard. */
		SLASH,				/**< Represents the Slash Key on the keyboard. */
		SPACE,				/**< Represents the Space Key on the keyboard. */

		INSERT = 76,		/**< Represents the Space Key on the keyboard. */
		DELETE,				/**< Represents the Delete Key on the keyboard. */
		HOME,				/**< Represents the Home Key on the keyboard. */
		END,				/**< Represents the End Key on the keyboard. */
		PGUP,				/**< Represents the Page Up Key on the keyboard. */
		PGDN,				/**< Represents the Page Down Key on the keyboard. */
		LEFT,				/**< Represents the Left Key on the keyboard. */
		RIGHT,				/**< Represents the Right Key on the keyboard. */
		UP,					/**< Represents the Up Key on the keyboard. */
		DOWN,				/**< Represents the Down Key on the keyboard. */

		PAD_SLASH = 86,		/**< Represents the Slash Key on the keyboard number pad. */
		PAD_ASTERISK,		/**< Represents the Asterisk Key on the keyboard number pad. */
		PAD_MINUS,			/**< Represents the Minus Key on the keyboard number pad. */
		PAD_PLUS,			/**< Represents the Plus Key on the keyboard number pad. */
		PAD_DELETE,			/**< Represents the Delete Key on the keyboard number pad. */
		PAD_ENTER,			/**< Represents the Enter Key on the keyboard number pad. */

		PRINTSCREEN = 92,	/**< Represents the Print %Screen Key on the keyboard. */
		PAUSE,				/**< Represents the Pause Key on the keyboard. */

		LSHIFT = 215,		/**< Represents the Left Shift Key on the keyboard. */
		RSHIFT,				/**< Represents the Right Shift Key on the keyboard. */
		LCTRL,				/**< Represents the Left Control Key on the keyboard. */
		RCTRL,				/**< Represents the Right Control Key on the keyboard. */
		ALT,				/**< Represents the Alt Key on the keyboard. */
		ALTGR,				/**< Represents the Alt Graph Key on the keyboard. */
		LWIN,				/**< Represents the Left Windows Key on the keyboard. */
		RWIN,				/**< Represents the Right Windows Key on the keyboard. */
		MENU,				/**< Represents the Menu Key on the keyboard. */
		SCROLLLOCK,			/**< Represents the Scroll Lock Key on the keyboard. */
		NUMLOCK,			/**< Represents the Num Lock Key on the keyboard. */
		CAPSLOCK,			/**< Represents the Caps Lock Key on the keyboard. */

		MAX				/**< Represents the Max value for all keys. */
	};
}