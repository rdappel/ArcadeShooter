
/*   .oooooo..o       .o.       ooo        ooooo ooooooooo.   ooooo        oooooooooooo
	d8P'    `Y8      .888.      `88.       .888' `888   `Y88. `888'        `888'     `8
	Y88bo.          .8"888.      888b     d'888   888   .d88'  888          888
	 `"Y8888o.     .8' `888.     8 Y88. .P  888   888ooo88P'   888          888oooo8
		 `"Y88b   .88ooo8888.    8  `888'   888   888          888          888    "
	oo     .d8P  .8'     `888.   8    Y     888   888          888       o  888       o
	8""88888P'  o88o     o8888o o8o        o888o o888o        o888ooooood8 o888ooooood8

							Sample © 2017 - Shuriken Studios LLC                          */

#pragma once

namespace Sample
{
	/** @brief Defines the types of game objects that can collide with each other. */
	enum CollisionType : uint32_t
	{
		/* ------------------------------ Same as Shooter Library ------------------------------ */

		COLLISIONTYPE_NONE			= 0,		/**< Represents an object that has no collision. */

		COLLISIONTYPE_PLAYER		= 1 << 0,	/**< Represents a player object. */
		COLLISIONTYPE_ENEMY			= 1 << 1,	/**< Represents an enemy object. */

		COLLISIONTYPE_SHIP			= 1 << 2,	/**< Represents a ship object. */
		COLLISIONTYPE_PROJECTILE	= 1 << 3,	/**< Represents a projectile object. */

		/* ------------------------------------------------------------------------------------- */

		/* ---------------------------------- Additional Types --------------------------------- */

		COLLISIONTYPE_MISSILE		= 1 << 4,	/**< Represents a missile object. */

		COLLISIONTYPE_POWERUP		= 1 << 5,	/**< Represents a powerup object. */
		COLLISIONTYPE_EXPLOSION		= 1 << 6	/**< Represents an explosion object. */

		/* ------------------------------------------------------------------------------------- */
	};
}
