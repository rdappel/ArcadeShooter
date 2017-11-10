#pragma once


class TriggerType
{

public:

	TriggerType() { m_value = 0; }
	virtual ~TriggerType() { }

	static const TriggerType NONE;
	static const TriggerType PRIMARY;
	static const TriggerType SECONDARY;
	static const TriggerType SPECIAL;
	static const TriggerType ALL;


	TriggerType &TriggerType::operator=(const TriggerType &type)
	{
		m_value = type.m_value;

		return *this;
	}

	bool TriggerType::operator==(const TriggerType &type) const
	{
		return m_value == type.m_value;
	}

	bool TriggerType::operator!=(const TriggerType &type) const
	{
		return m_value != type.m_value;
	}

	bool TriggerType::operator<(const TriggerType &type) const
	{
		return m_value < type.m_value;
	}

	bool TriggerType::operator>(const TriggerType &type) const
	{
		return m_value > type.m_value;
	}

	const TriggerType operator|(const TriggerType &type) const
	{
		return (TriggerType)(m_value | type.m_value);
	}

	TriggerType &TriggerType::operator|=(const TriggerType &type)
	{
		m_value |= type.m_value;

		return *this;
	}

	const TriggerType operator&(const TriggerType &type) const
	{
		return (TriggerType)(m_value & type.m_value);
	}

	TriggerType &TriggerType::operator&=(const TriggerType &type)
	{
		m_value &= type.m_value;

		return *this;
	}

	const TriggerType operator^(const TriggerType &type) const
	{
		return (TriggerType)(m_value ^ type.m_value);
	}

	TriggerType &TriggerType::operator^=(const TriggerType &type)
	{
		m_value ^= type.m_value;

		return *this;
	}

	bool Contains(const TriggerType &type)
	{
		return (m_value & type.m_value) > 0;
	}


protected:

	TriggerType(const unsigned short value) { m_value = value; }


private:

	unsigned short m_value;

};
