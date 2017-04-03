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

   File: KeyState.h
   Description: Header file for keyboard structures and
   enumerations.

/  --------------------------------------------------------------- */

#pragma once

namespace KatanaEngine
{
	enum class Key
	{
		A = 1, B, C, D, E, F, G, H, I, J, K, L, M,
		N, O, P, Q, R, S, T, U, V, W, X, Y, Z,

		NUM_0, NUM_1, NUM_2, NUM_3, NUM_4,
		NUM_5, NUM_6, NUM_7, NUM_8, NUM_9,

		PAD_0, PAD_1, PAD_2, PAD_3, PAD_4,
		PAD_5, PAD_6, PAD_7, PAD_8, PAD_9,

		F1 = 47, F2 = 48, F3 = 49, F4 = 50,
		F5 = 51, F6 = 52, F7 = 53, F8 = 54,
		F9 = 55, F10 = 56, F11 = 57, F12 = 58,

		ESCAPE = 59,
		TILDE = 60,
		MINUS = 61,
		EQUALS = 62,
		BACKSPACE = 63,
		TAB = 64,
		OPENBRACE = 65,
		CLOSEBRACE = 66,
		ENTER = 67,
		SEMICOLON = 68,
		QUOTE = 69,
		BACKSLASH = 70,
		BACKSLASH2 = 71, /* DirectInput calls this DIK_OEM_102: "< > | on UK/Germany keyboards" */
		COMMA = 72,
		FULLSTOP = 73,
		SLASH = 74,
		SPACE = 75,

		INSERT = 76,
		DELETE = 77,
		HOME = 78,
		END = 79,
		PGUP = 80,
		PGDN = 81,
		LEFT = 82,
		RIGHT = 83,
		UP = 84,
		DOWN = 85,

		PAD_SLASH = 86,
		PAD_ASTERISK = 87,
		PAD_MINUS = 88,
		PAD_PLUS = 89,
		PAD_DELETE = 90,
		PAD_ENTER = 91,

		PRINTSCREEN = 92,
		PAUSE = 93,

		ABNT_C1 = 94,
		YEN = 95,
		KANA = 96,
		CONVERT = 97,
		NOCONVERT = 98,
		AT = 99,
		CIRCUMFLEX = 100,
		COLON2 = 101,
		KANJI = 102,

		PAD_EQUALS = 103,	/* MacOS X */
		BACKQUOTE = 104,	/* MacOS X */
		SEMICOLON2 = 105,	/* MacOS X */
		COMMAND = 106,		/* MacOS X */

		BACK = 107,        /* Android back key */
		VOLUME_UP = 108,
		VOLUME_DOWN = 109,

		/* Android game keys */
		SEARCH = 110,
		DPAD_CENTER = 111,
		BUTTON_X = 112,
		BUTTON_Y = 113,
		DPAD_UP = 114,
		DPAD_DOWN = 115,
		DPAD_LEFT = 116,
		DPAD_RIGHT = 117,
		SELECT = 118,
		START = 119,
		BUTTON_L1 = 120,
		BUTTON_R1 = 121,
		BUTTON_L2 = 122,
		BUTTON_R2 = 123,
		BUTTON_A = 124,
		BUTTON_B = 125,
		THUMBL = 126,
		THUMBR = 127,

		UNKNOWN = 128,

		/* All codes up to before MODIFIERS can be freely
		* assignedas additional unknown keys, like various multimedia
		* and application keys keyboards may have.
		*/

		MODIFIERS = 215,

		LSHIFT = 215,
		RSHIFT = 216,
		LCTRL = 217,
		RCTRL = 218,
		ALT = 219,
		ALTGR = 220,
		LWIN = 221,
		RWIN = 222,
		MENU = 223,
		SCROLLLOCK = 224,
		NUMLOCK = 225,
		CAPSLOCK = 226,

		MAX
	};
}