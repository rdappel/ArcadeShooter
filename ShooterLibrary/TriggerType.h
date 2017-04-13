
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
	/** @brief Defines the ways that triggering weapons can occur. */
	enum TriggerType : uint32_t
	{
		TRIGGERTYPE_NONE		= 0,				/**< Represents an untriggerable weapon. */

		TRIGGERTYPE_PRIMARY		= 1 << 0,			/**< Represents a primary trigger type. */
		TRIGGERTYPE_SECONDARY	= 1 << 1,			/**< Represents a secondary trigger type. */

		TRIGGERTYPE_SPECIAL		= 1 << 2,			/**< Represents a special trigger type. */

		TRIGGERTYPE_ALL			= ((uint32_t)-1)	/**< Represents all trigger types. */
	};
}
