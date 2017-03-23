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

   File: Vector2.cpp
   Description: Source file for two-dimensional vectors.

/  --------------------------------------------------------------- */

#include "KatanaEngine.h"


const Vector2 Vector2::Zero = Vector2(0, 0);
const Vector2 Vector2::One = Vector2(1, 1);
const Vector2 Vector2::UnitX = Vector2(1, 0);
const Vector2 Vector2::UnitY = Vector2(0, 1);


Vector2::Vector2(const float x, const float y)
{
	X = x;
	Y = y;
}

float Vector2::DistanceSquared() const
{
	return ((X * X) + (Y * Y));
}

float Vector2::Distance() const
{
	return sqrtf(X * X + Y * Y);
}

void Vector2::Normalize()
{
	float dist = Distance();

	if (dist != 0)
	{
		X /= dist;
		Y /= dist;
	}
}

void Vector2::Set(const float x, const float y)
{
	X = x;
	Y = y;
}

void Vector2::Set(const Vector2 vector)
{
	X = vector.X;
	Y = vector.Y;
}

float Vector2::DotProduct(const Vector2 &v2) const
{
	return (X * v2.X) + (Y * v2.Y);
}

float Vector2::CrossProduct(const Vector2 &v2) const
{
	return (X * v2.Y) - (Y * v2.X);
}

float Vector2::Distance(const Vector2 &v1, const Vector2 &v2)
{
	return sqrtf(pow((v2.X - v1.X), 2) + pow((v2.Y - v1.Y), 2));
}

Vector2 Vector2::Lerp(const Vector2 &v1, const Vector2 &v2, const float value)
{
	float v = value;

	if (v > 1) v = 1.0f;
	if (v < 0) v = 0.0f;

	return (v1 * (1 - v) + v2 * v);
}

Vector2 &Vector2::operator=(const Vector2 &v2)
{
	if (this == &v2)
		return *this;

	X = v2.X;
	Y = v2.Y;

	return *this;
}

Vector2 &Vector2::operator+=(const Vector2 &v2)
{
	X += v2.X;
	Y += v2.Y;

	return *this;
}

Vector2 &Vector2::operator-=(const Vector2 &v2)
{
	X -= v2.X;
	Y -= v2.Y;

	return *this;
}

Vector2 &Vector2::operator*=(const float scalar)
{
	X *= scalar;
	Y *= scalar;

	return *this;
}

Vector2 &Vector2::operator/=(const float scalar)
{
	X /= scalar;
	Y /= scalar;

	return *this;
}

const Vector2 Vector2::operator+(const Vector2 &v2) const
{
	return Vector2(*this) += v2;
}

const Vector2 Vector2::operator-(const Vector2 &v2) const
{
	return Vector2(*this) -= v2;
}

const Vector2 Vector2::operator*(const float scalar) const
{
	return Vector2(*this) *= scalar;
}

const Vector2 Vector2::operator/(const float scalar) const
{
	return Vector2(*this) /= scalar;
}

bool Vector2::operator== (const Vector2 &v2) const
{
	return ((X == v2.X) && (Y == v2.Y));
}

bool Vector2::operator!= (const Vector2 &v2) const
{
	return !((X == v2.X) && (Y == v2.Y));
}

const Point Vector2::ToPoint() const
{
	return Point((int)X, (int)Y);
}
