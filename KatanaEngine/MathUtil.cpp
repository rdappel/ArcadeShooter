
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

#include "KatanaEngine.h"

namespace KatanaEngine
{
	const float Math::PI = 3.14159265359f;
	const float Math::PI_OVER2 = Math::PI / 2;
	const float Math::PI_OVER4 = Math::PI / 4;
	const float Math::INVERSE_PI = 1.0f / Math::PI;
	const float Math::NORMALIZE_PI_OVER4 = 0.70710678119f;
	const float Math::INVERSE_180 = 1.0f / 180;

	float Math::Lerp(float start, float end, float value)
	{
		if (value < 0) return start;
		if (value > 1) return end;

		return start + (end - start) * value;
	}

	int Math::GetRandomInt(const int min, const int max)
	{
		return (rand() % (max - min + 1)) + min;
	}
	
	float Math::Min(const float value1, const float value2)
	{
		if (value1 < value2) return value1;
		return value2;
	}

	float Math::Max(const float value1, const float value2)
	{
		if (value1 > value2) return value1;
		return value2;
	}

	float Math::Abs(const float value)
	{
		if (value < 0) return -value;
		else return value;
	}

	float Math::Clamp(const float min, const float max, const float value)
	{
		if (value < min) return min;
		if (value > max) return max;

		return value;
	}
}