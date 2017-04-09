
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
	enum CollisionTypes : uint32_t
	{
		COLLISIONTYPE_NONE			= 0,	/**< Represents an object that has no collision. */

		COLLISIONTYPE_PLAYER		= 1,	/**< Represents a player object. */
		COLLISIONTYPE_ENEMY			= 2,	/**< Represents an enemy object. */

		COLLISIONTYPE_SHIP			= 4,	/**< Represents a ship object. */
		COLLISIONTYPE_PROJECTILE	= 8		/**< Represents a projectile object. */
	};
}
