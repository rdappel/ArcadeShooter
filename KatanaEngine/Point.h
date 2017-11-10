
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

#pragma once

namespace KatanaEngine
{
	class Vector2;

	/** @brief 	Defines a point in 2D space. */
	class Point
	{

	public:

		/** @brief Instantiates a new point object.
			@param x The X component
			@param y The Y component */
		Point(const int x = 0, const int y = 0);
		~Point() { };


		static const Point Origin;	/**< @brief A point located at the origin. */


		/** @brief Sets the components of the point.
			@param x The X component.
			@param y The Y component. */
		void Set(const int x, const int y);

		/** @brief Sets the components of the vecpointtor.
			@param point The point whose components to copy.
			
			@overload */
		void Set(const Point point);

		/** @brief Determines if the point is located at the origin.
			@return Returns true if both components are zero, false otherwise. */
		bool IsOrigin() const { return (X == 0 && Y == 0); }

		/** @brief Converts the point into a vector.
			@return Returns a displacement vector to the point. */
		const Vector2 ToVector2() const;

		/** @brief Gets a string representation of the point.
			@return Returns a string displaying the components of the point. */
		std::string ToString() const;

		/** @brief Prints the point to the console. */
		void Display() const { std::cout << ToString() << std::endl; }


		/** @brief Assigns the reference of a point.
			@param point The reference point.
			@return Returns the resulting point. */
		Point &operator= (const Point &point);

		/** @brief Adds a point.
			@param point The point to add.
			@return Returns the resulting point. */
		Point &operator+=(const Point &point);

		/** @brief Subtracts a point.
			@param point The point to subtract.
			@return Returns the resulting point. */
		Point &operator-=(const Point &point);

		/** @brief Adds two points.
			@param point The point to add.
			@return Returns the resulting point. */
		const Point operator+(const Point &point) const;

		/** @brief Subtracts a point from another.
			@param point The point to subtract.
			@return Returns the resulting point. */
		const Point operator-(const Point &point) const;

		/** @brief Determines if two points are equal.
			@param point The point to compare.
			@return Returns true if the points are equal, false otherwise. */
		bool operator==(const Point &point) const;

		/** @brief Determines if two points are not equal.
			@param point The point to compare.
			@return Returns true if the points are not equal, false otherwise. */
		bool operator!=(const Point &point) const;


		int X;	/**< @brief The x-coordinate of the point. */
		int Y;	/**< @brief The y-coordinate of the point. */

	};
}