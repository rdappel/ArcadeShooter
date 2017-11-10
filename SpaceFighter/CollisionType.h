
#pragma once

class CollisionType
{

public:

	CollisionType() { m_value = 0; }
	virtual ~CollisionType() { }

	static const CollisionType NONE;

	static const CollisionType PLAYER;
	static const CollisionType ENEMY;

	static const CollisionType SHIP;
	static const CollisionType PROJECTILE;


	CollisionType &CollisionType::operator=(const CollisionType &type)
	{
		m_value = type.m_value;
		return *this;
	}

	bool CollisionType::operator==(const CollisionType &type) const
	{
		return m_value == type.m_value;
	}

	bool CollisionType::operator!=(const CollisionType &type) const
	{
		return m_value != type.m_value;
	}

	bool CollisionType::operator<(const CollisionType &type) const
	{
		return m_value < type.m_value;
	}

	bool CollisionType::operator>(const CollisionType &type) const
	{
		return m_value > type.m_value;
	}

	const CollisionType operator|(const CollisionType &type) const
	{
		return (CollisionType)(m_value | type.m_value);
	}

	CollisionType &CollisionType::operator|=(const CollisionType &type)
	{
		m_value |= type.m_value;

		return *this;
	}

	const CollisionType operator&(const CollisionType &type) const
	{
		return (CollisionType)(m_value & type.m_value);
	}

	CollisionType &CollisionType::operator&=(const CollisionType &type)
	{
		m_value &= type.m_value;

		return *this;
	}

	const CollisionType operator^(const CollisionType &type) const
	{
		return (CollisionType)(m_value ^ type.m_value);
	}

	CollisionType &CollisionType::operator^=(const CollisionType &type)
	{
		m_value ^= type.m_value;

		return *this;
	}

	bool Contains(const CollisionType &type)
	{
		return (m_value & type.m_value) > 0;
	}


protected:

	CollisionType(const unsigned short value) { m_value = value; }


private:

	unsigned short m_value;

};