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

   File: Point.h
   Description: Header file for two-dimensional points.

/  --------------------------------------------------------------- */

#pragma once


class Vector2;

class Point
{

public:

	int X;
	int Y;

	Point(const int x = 0, const int y = 0);
	~Point() { };


	static const Point Zero;
	static const Point One;
	static const Point UnitX;
	static const Point UnitY;


	void Set(const int x, const int y);
	void Set(const Point point);


	Point &operator= (const Point &p2);

	Point &operator+=(const Point &p2);
	Point &operator-=(const Point &p2);

	const Point operator+(const Point &p2) const;
	const Point operator-(const Point &p2) const;

	bool operator==(const Point &p2) const;
	bool operator!=(const Point &p2) const;

	const Vector2 ToVector2() const;

	void Display() const { std::cout << "{" << X << ", " << Y << "}" << std::endl; }
};

