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
	/** @brief Provides commonly used floating point functions and constants. */
	class Math
	{

	public:

		static const float PI;					/**< @brief Represents the value of pi. */
		static const float PI_OVER2;			/**< @brief Represents the value of pi divided by two. */
		static const float PI_OVER4;			/**< @brief Represents the value of pi divided by four. */
		static const float INVERSE_PI;			/**< @brief Represents the value of one divided by pi. */
		static const float NORMALIZE_PI_OVER4;	/**< @brief Represents the value of each component in a pi/4 unit vector. */
		static const float INVERSE_180;			/**< @brief Represents the value of one divided by 180. */


		/** @brief Linearly interpolate between two values.
			@param start The result when the value is zero.
			@param end The result when the value is one.
			@param value A value between 0 and 1 that will indicate the resulting weight between start and end.
			@return Returns the interpolated value between start and end. */
		static float Lerp(float start, float end, float value);

		/** @brief Get a random integer.
			@param min The inclusive minimum number.
			@param max The inclusive maximum number.
			@return Returns a random integer between min and max. */
		static int GetRandomInt(const int min = 0, const int max = RAND_MAX);

		/** @brief Get a random number between zero and one.
			@return Returns a random floating point number between zero and one. */
		static float GetRandomFloat() { return ((float)rand() / RAND_MAX); }

		/** @brief Get the lessor of two numbers.
			@param value1 The first value.
			@param value2 The second value.
			@return Returns the lessor number between two values. */
		static float Min(const float value1, const float value2);

		/** @brief Get the greator of two numbers.
			@param value1 The first value.
			@param value2 The second value.
			@return Returns the greator number between two values. */
		static float Max(const float value1, const float value2);

		/** @brief Restricts a value to be within a specified range.
			@param min The minimum value. If value is less than min, min will be returned.
			@param max The maximum value. If value is greater than max, max will be returned.
			@param value The value to clamp.
			@return Returns the clamped value between min and max. */
		static float Clamp(const float min, const float max, const float value);

		/** @brief Converts degrees to radians.
			@param degrees The angle in degrees.
			@return Returns the angle in radians. */
		static float ToRadians(const float degrees) { return degrees * PI * INVERSE_180; }

		/** @brief Converts radians to degrees.
			@param radians The angle in radians.
			@return Returns the angle in degrees. */
		static float ToDegrees(const float radians) { return radians * 180 * INVERSE_PI; }
	};
}