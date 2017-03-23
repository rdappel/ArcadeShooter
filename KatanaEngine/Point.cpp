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

   File: Point.cpp
   Description: Source file for two-dimensional points.

/  --------------------------------------------------------------- */

#include "KatanaEngine.h"


const Point Point::Zero = Point(0, 0);
const Point Point::One = Point(1, 1);
const Point Point::UnitX = Point(1, 0);
const Point Point::UnitY = Point(0, 1);


Point::Point(const int x, const int y)
{
	X = x;
	Y = y;
}

void Point::Set(const int x, const int y)
{
	X = x;
	Y = y;
}

void Point::Set(const Point point)
{
	X = point.X;
	Y = point.Y;
}

Point &Point::operator=(const Point &p2)
{
	if (this == &p2)
		return *this;

	X = p2.X;
	Y = p2.Y;

	return *this;
}

Point &Point::operator+=(const Point &p2)
{
	X += p2.X;
	Y += p2.Y;

	return *this;
}

Point &Point::operator-=(const Point &p2)
{
	X -= p2.X;
	Y -= p2.Y;

	return *this;
}

const Point Point::operator+(const Point &p2) const
{
	return Point(*this) += p2;
}

const Point Point::operator-(const Point &p2) const
{
	return Point(*this) -= p2;
}

bool Point::operator== (const Point &p2) const
{
	return ((X == p2.X) && (Y == p2.Y));
}

bool Point::operator!= (const Point &p2) const
{
	return !((X == p2.X) && (Y == p2.Y));
}

const Vector2 Point::ToVector2() const
{
	return Vector2(X, Y);
}
