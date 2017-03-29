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

	static float GetRandomFloat()
	{
		return ((float)rand() / RAND_MAX);
	}

	static float Clamp(const float min, const float max, const float value)
	{
		if (value < min) return min;
		if (value > max) return max;

		return value;
	}
};
