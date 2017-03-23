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


class Vector2
{

public:

	float X;
	float Y;

	Vector2(const float x = 0, const float y = 0);
	~Vector2() { };


	static const Vector2 Zero;
	static const Vector2 One;
	static const Vector2 UnitX;
	static const Vector2 UnitY;


	float DistanceSquared() const;
	float Distance() const;

	void Set(const float x, const float y);
	void Set(const Vector2 vector);
	void Normalize();

	float DotProduct(const Vector2 &v2) const;
	float CrossProduct(const Vector2 &v2) const;

	static float Distance(const Vector2 &v1, const Vector2 &v2);
	static Vector2 Lerp(const Vector2 &v1, const Vector2 &v2, const float value);

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

