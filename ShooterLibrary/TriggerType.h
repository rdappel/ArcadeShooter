
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

	/** @brief Defines how different types of weapons should be triggered. */
	class TriggerType
	{

	public:

		TriggerType() { m_value = 0; }
		virtual ~TriggerType() { }

		static const TriggerType NONE;		/**< @brief Represents an object that has no trigger. */

		static const TriggerType PRIMARY;	/**< @brief Represents a primary weapon trigger. */
		static const TriggerType SECONDARY;	/**< @brief Represents a secondary weapon trigger. */
		static const TriggerType SPECIAL;	/**< @brief Represents a special weapon trigger. */

		static const TriggerType ALL;		/**< @brief Represents a combination of all weapon triggers. */


		virtual uint32_t GetValue() { return m_value; }

		
		/** @brief Assigns the reference of a trigger type.
			@param type The reference trigger type.
			@return Returns the resulting trigger type. */
		TriggerType &TriggerType::operator=(const TriggerType &type)
		{
			m_value = type.m_value;

			return *this;
		}
		
		/** @brief Assigns the reference of a trigger type.
			@param type The reference trigger type.
			@return Returns the resulting trigger type. */
		bool TriggerType::operator==(const TriggerType &type) const
		{
			return m_value == type.m_value;
		}
		
		/** @brief Assigns the reference of a trigger type.
			@param type The reference trigger type.
			@return Returns the resulting trigger type. */
		bool TriggerType::operator!=(const TriggerType &type) const
		{
			return m_value != type.m_value;
		}

		/** @brief Determines if a trigger type has a lower value than another.
			@param type The trigger type to compare.
			@return Returns true if the trigger type is less than another, false otherwise. */
		bool TriggerType::operator<(const TriggerType &type) const
		{
			return m_value < type.m_value;
		}

		/** @brief Determines if a trigger type has a greater value than another.
			@param type The trigger type to compare.
			@return Returns true if the trigger type is greater than another, false otherwise. */
		bool TriggerType::operator>(const TriggerType &type) const
		{
			return m_value > type.m_value;
		}

		/** @brief Combines the trigger types into a single type.
			@param type The trigger type to combine.
			@return Returns the combined type. */
		const TriggerType operator|(const TriggerType &type) const
		{
			return (TriggerType)(m_value | type.m_value);
		}
		
		/** @brief Combines the trigger types into a single type.
			@param type The trigger type to combine.
			@return Returns the combined type. */
		TriggerType &TriggerType::operator|=(const TriggerType &type)
		{
			m_value |= type.m_value;

			return *this;
		}

		/** @brief Intersects the trigger types.
			@param type The trigger type to intersect.
			@return Returns the intersecting type. */
		const TriggerType operator&(const TriggerType &type) const
		{
			return (TriggerType)(m_value & type.m_value);
		}

		/** @brief Intersects the trigger types.
			@param type The trigger type to intersect.
			@return Returns the intersecting type. */
		TriggerType &TriggerType::operator&=(const TriggerType &type)
		{
			m_value &= type.m_value;

			return *this;
		}

		/** @brief Differentiates the trigger types.
			@param type The trigger type to differentiate.
			@return Returns the differentiated type. */
		const TriggerType operator^(const TriggerType &type) const
		{
			return (TriggerType)(m_value ^ type.m_value);
		}

		/** @brief Differentiates the trigger types.
		@param type The trigger type to differentiate.
		@return Returns the differentiated type. */
		TriggerType &TriggerType::operator^=(const TriggerType &type)
		{
			m_value ^= type.m_value;

			return *this;
		}

		/** @brief Determines if the trigger type contains another trigger type.
			@param type The trigger type to check for.
			@return Returns true if the type is contained, false otherwise. */
		bool Contains(const TriggerType &type)
		{
			return (m_value & type.m_value) > 0;
		}


	protected:

		/** @brief Instantiates a new trigger type object.
			@param value The underlaying value of the type. */
		TriggerType(uint32_t value);


	private:

		uint32_t m_value;

	};

}
