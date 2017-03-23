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

   File: Math.h
   Description: Header file for math utility functions and
   constants.

/  --------------------------------------------------------------- */

#pragma once


class Math
{

public:

	static const float PI;
	static const float PI_OVER2;
	static const float PI_OVER4;
	static const float INVERSE_PI;
	static const float NORMALIZE_45;

	static float Lerp(float start, float end, float value)
	{
		return (1 - value) * start + value * end;
	}

	static int GetRandomInt(const int min = 0, const int max = RAND_MAX)
	{
		int range = max - min;

		return (rand() % range) + min;
	}

	static double GetRandomDouble()
	{
		return ((rand() % RAND_MAX) / RAND_MAX);
	}

};

//const float Math::PI = 3.14159265359f;
//const float Math::PI_OVER2 = Math::PI / 2;
//const float Math::PI_OVER4 = Math::PI / 4;
//const float Math::INVERSE_PI = 1.0f / Math::PI;
//const float Math::NORMALIZE_45 = 0.70710678119f;
