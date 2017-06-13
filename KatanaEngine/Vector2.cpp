
/*	 ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗ 
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
        Katana Engine \/ © 2012 - Shuriken Studios LLC              */

#include "KatanaEngine.h"

namespace KatanaEngine
{
	const Vector2 Vector2::ZERO = Vector2(0, 0);
	const Vector2 Vector2::ONE = Vector2(1, 1);
	const Vector2 Vector2::UNIT_X = Vector2(1, 0);
	const Vector2 Vector2::UNIT_Y = Vector2(0, 1);
	
	Vector2::Vector2(const float x, const float y)
	{
		X = x;
		Y = y;
	}

	float Vector2::LengthSquared() const
	{
		return ((X * X) + (Y * Y));
	}

	float Vector2::Length() const
	{
		return sqrtf(X * X + Y * Y);
	}

	void Vector2::Normalize()
	{
		if (!IsZero())
		{
			float len = Length();
			X /= len;
			Y /= len;
		}
	}
	
	float Vector2::DotProduct(const Vector2 &vector) const
	{
		return (X * vector.X) + (Y * vector.Y);
	}

	float Vector2::CrossProduct(const Vector2 &vector) const
	{
		return (X * vector.Y) - (Y * vector.X);
	}

	float Vector2::Distance(const Vector2 &vector1, const Vector2 &vector2)
	{
		return sqrtf(pow((vector2.X - vector1.X), 2) + pow((vector2.Y - vector1.Y), 2));
	}

	float Vector2::DistanceSquared(const Vector2 &vector1, const Vector2 &vector2)
	{
		return pow((vector2.X - vector1.X), 2) + pow((vector2.Y - vector1.Y), 2);
	}

	Vector2 Vector2::Lerp(const Vector2 &start, const Vector2 &end, const float value)
	{
		if (value < 0) return start;
		if (value > 1) return end;

		return start + (end - start) * value;
	}

	Vector2 Vector2::GetRandom(bool normalize)
	{
		float x = Math::GetRandomFloat() * 2 - 1;
		float y = Math::GetRandomFloat() * 2 - 1;

		Vector2 result(x, y);
		if (normalize) result.Normalize();

		return result;
	}

	std::string Vector2::ToString() const
	{
		std::ostringstream ss;
		ss << "{ " << X << ", " << Y << " }";
		return ss.str();
	}

	Vector2 &Vector2::operator=(const Vector2 &vector)
	{
		if (this != &vector)
		{
			X = vector.X;
			Y = vector.Y;
		}

		return *this;
	}

	Vector2 &Vector2::operator+=(const Vector2 &vector)
	{
		X += vector.X;
		Y += vector.Y;

		return *this;
	}

	Vector2 &Vector2::operator-=(const Vector2 &vector)
	{
		X -= vector.X;
		Y -= vector.Y;

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

	const Vector2 Vector2::operator+(const Vector2 &vector) const
	{
		return Vector2(*this) += vector;
	}

	const Vector2 Vector2::operator-(const Vector2 &vector) const
	{
		return Vector2(*this) -= vector;
	}

	const Vector2 Vector2::operator*(const float scalar) const
	{
		return Vector2(*this) *= scalar;
	}

	const Vector2 Vector2::operator/(const float scalar) const
	{
		return Vector2(*this) /= scalar;
	}

	bool Vector2::operator==(const Vector2 &vector) const
	{
		return ((X == vector.X) && (Y == vector.Y));
	}

	bool Vector2::operator!=(const Vector2 &vector) const
	{
		return !((X == vector.X) && (Y == vector.Y));
	}

	const Point Vector2::ToPoint() const
	{
		return Point((int)X, (int)Y);
	}
}