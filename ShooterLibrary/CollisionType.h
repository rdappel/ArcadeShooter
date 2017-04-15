
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

		CollisionType(uint32_t value) { m_value = value; }


	private:

		uint32_t m_value;

	};

}
