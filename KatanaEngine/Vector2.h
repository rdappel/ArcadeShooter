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

   File: Vector2.h
   Description: Header file for two-dimensional vectors.

/  --------------------------------------------------------------- */

#pragma once

namespace KatanaEngine
{
	/** @brief Defines a vector with 2 components (x and y). */
	class Vector2
	{

	public:

		/** The x-coordinate of the vector. */
		float X;
		/** The y-coordinate of the vector. */
		float Y;

		/** Creates and initializes an new instance of Vector2. */
		Vector2(const float x = 0, const float y = 0);

		/** Returns a Vector2 with all of its components set to zero. */
		static const Vector2 Zero;
		/** Returns a Vector2 with both of its components set to one. */
		static const Vector2 One;
		/** Returns the unit vector for the x-axis. */
		static const Vector2 UnitX;
		/** Returns the unit vector for the y-axis. */
		static const Vector2 UnitY;
		
		/** Calculates the length of the vector squared.
		 @return float The length of the vector squared. */
		float LengthSquared() const;
		/** Calculates the length of the vector.
		 @return The length of the vector. */
		float Length() const;

		void Set(const float x, const float y);
		void Set(const Vector2 vector);
		void Normalize();

		/** Calculates the dot product of two vectors. If the two vectors are unit vectors, the dot product returns a floating point value between -1 and 1 that can be used to determine some properties of the angle between two vectors. For example, it can show whether the vectors are orthogonal, parallel, or have an acute or obtuse angle between them.
		  @param v2 The other vector.
		  @return The calculated dot product. */
		float DotProduct(const Vector2 &v2) const;

		/** Calculates the cross product between two vectors.
		@param v2 The other vector.
		@return The calculated cross product */
		float CrossProduct(const Vector2 &v2) const;

		static float Distance(const Vector2 &v1, const Vector2 &v2);
		static float DistanceSquared(const Vector2 &v1, const Vector2 &v2);

		/** Performs a linear interpolation between two vectors.
		 */
		static Vector2 Lerp(const Vector2 &v1, const Vector2 &v2, const float value);
		static Vector2 GetRandom(bool normalize = false);

		Vector2 Left() { return Vector2(-Y, X); }
		Vector2 Right() { return Vector2(Y, -X); }

		Vector2 &operator= (const Vector2 &v2);

		Vector2 &operator+=(const Vector2 &v2);
		Vector2 &operator-=(const Vector2 &v2);
		Vector2 &operator*=(const float scalar);
		Vector2 &operator/=(const float scalar);

		const Vector2 operator+(const Vector2 &v2) const;
		const Vector2 operator-(const Vector2 &v2) const;
		const Vector2 operator*(const float scalar) const;
		const Vector2 operator/(const float scalar) const;


		bool operator==(const Vector2 &v2) const;
		bool operator!=(const Vector2 &v2) const;

		const Point ToPoint() const;

		void Display() const { std::cout << "{" << X << ", " << Y << "}" << std::endl; }
	};
}