
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

	/** @brief Defines the types of game objects that can collide with each other. */
	class CollisionType
	{

	public:

		CollisionType() { m_value = 0; }
		virtual ~CollisionType() { }

		static const CollisionType NONE;		/**< @brief Represents an object that has no collision. */

		static const CollisionType PLAYER;		/**< @brief Represents a player. */
		static const CollisionType ENEMY;		/**< @brief Represents a enemy. */

		static const CollisionType SHIP;		/**< @brief Represents a ship. */
		static const CollisionType PROJECTILE;	/**< @brief Represents a projectile. */


		/** @brief Assigns the reference of a collision type.
			@param type The reference collision type.
			@return Returns the resulting collision type. */
		CollisionType &CollisionType::operator=(const CollisionType &type)
		{
			m_value = type.m_value;

			return *this;
		}

		/** @brief Determines if two collision types are equal.
			@param type The collision type to compare.
			@return Returns true if the collision types are equal, false otherwise. */
		bool CollisionType::operator==(const CollisionType &type) const
		{
			return m_value == type.m_value;
		}

		/** @brief Determines if two collision types are not equal.
			@param type The collision type to compare.
			@return Returns true if the collision types are not equal, false otherwise. */
		bool CollisionType::operator!=(const CollisionType &type) const
		{
			return m_value != type.m_value;
		}

		/** @brief Determines if a collision type has a lower value than another.
			@param type The collision type to compare.
			@return Returns true if the collision type is less than another, false otherwise. */
		bool CollisionType::operator<(const CollisionType &type) const
		{
			return m_value < type.m_value;
		}

		/** @brief Determines if a collision type has a greater value than another.
			@param type The collision type to compare.
			@return Returns true if the collision type is greater than another, false otherwise. */
		bool CollisionType::operator>(const CollisionType &type) const
		{
			return m_value > type.m_value;
		}

		/** @brief Combines the collision types into a single type.
			@param type The collision type to combine.
			@return Returns the combined type. */
		const CollisionType operator|(const CollisionType &type) const
		{
			return (CollisionType)(m_value | type.m_value);
		}

		/** @brief Combines the collision types into a single type.
			@param type The collision type to combine.
			@return Returns the combined type. */
		CollisionType &CollisionType::operator|=(const CollisionType &type)
		{
			m_value |= type.m_value;

			return *this;
		}

		/** @brief Intersects the collision types.
			@param type The collision type to intersect.
			@return Returns the intersecting type. */
		const CollisionType operator&(const CollisionType &type) const
		{
			return (CollisionType)(m_value & type.m_value);
		}

		/** @brief Intersects the collision types.
			@param type The collision type to intersect.
			@return Returns the intersecting type. */
		CollisionType &CollisionType::operator&=(const CollisionType &type)
		{
			m_value &= type.m_value;

			return *this;
		}

		/** @brief Differentiates the collision types.
			@param type The collision type to differentiate.
			@return Returns the differentiated type. */
		const CollisionType operator^(const CollisionType &type) const
		{
			return (CollisionType)(m_value ^ type.m_value);
		}

		/** @brief Differentiates the collision types.
			@param type The collision type to differentiate.
			@return Returns the differentiated type. */
		CollisionType &CollisionType::operator^=(const CollisionType &type)
		{
			m_value ^= type.m_value;

			return *this;
		}

		/** @brief Determines if the collision type contains another collision type.
			@param type The collision type to check for.
			@return Returns true if the type is contained, false otherwise. */
		bool Contains(const CollisionType &type)
		{
			return (m_value & type.m_value) > 0;
		}


	protected:

		/** @brief Instantiates a new collision type object.
			@param value The underlaying value of the type. */
		CollisionType(uint32_t value) { m_value = value; }


	private:

		uint32_t m_value;

	};

}
