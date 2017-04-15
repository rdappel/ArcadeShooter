
/*      .                         ,'`.       .                         
   .                  .."    _.-;' ⁄‚ `.              .			`      
              _.-"`.##%"_.--" ,' ⁄`     `.           "#"     ___,,od000
           ,'"-_ _.-.--"\   ,'            `-_       '%#%',,/00000000000
         ,'     |_.'     )`/-     __..--""`-_`-._    J L/00000000000000
 . +   ,'   _.-"        / /   _-""           `-._`-_/___\///0000   000M
     .'_.-""      '    :_/_.-'                 _,`-/__V__\0000    00MMM
 . _-""                         .        '   _,/000\  |  /000    0MMMMM
_-"   .       '     .              .        ,/   000\ | /000000000MMMMM
       `       Shooter Library       '     ,/     000\|/000000000MMMMMM
.       © 2017 - Shuriken Studios LLC     ,/0    00000|0000000000MMMMMM */

#pragma once

namespace ShooterLibrary
{
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

		TriggerType(uint32_t value) { m_value = value; }


	private:

		uint32_t m_value;

	};

}
