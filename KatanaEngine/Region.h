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
   Date: 5/8/2015

   File: Region.h
   Description: Header file for rectangle regions.

/  --------------------------------------------------------------- */

#pragma once

class Region
{

public:

	Region() { X = Y = Width = Height = 0; }

	Region(const int x, const int y, const int width, const int height)
	{
		Set(x, y, width, height);
	}

	void Set(const int x, const int y, const int width, const int height)
	{
		X = x;
		Y = y;
		Width = width;
		Height = height;
	}

	virtual ~Region() { }

	int X;
	int Y;
	int Width;
	int Height;

	void Display() { std::cout << "{ X: " << X << ", Y: " << Y << "}" << std::endl; }

	int GetRight() { return X + Width; }
	int GetBottom() { return Y + Height; }

};