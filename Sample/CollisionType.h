#pragma once

namespace Sample
{
	/** @brief Defines the types of game objects that can collide with each other. */
	enum CollisionType : uint32_t
	{
		/* --------------------------- Same as Shooter Library ----------------------------- */

		COLLISIONTYPE_NONE			= 0,	/**< Represents an object that has no collision. */

		COLLISIONTYPE_PLAYER		= 1,	/**< Represents a player object. */
		COLLISIONTYPE_ENEMY			= 2,	/**< Represents an enemy object. */

		COLLISIONTYPE_SHIP			= 4,	/**< Represents a ship object. */
		COLLISIONTYPE_PROJECTILE	= 8,	/**< Represents a projectile object. */

		/* --------------------------------------------------------------------------------- */


		/* ------------------------------ Additional Types --------------------------------- */

		COLLISIONTYPE_POWERUP		= 16

		/* --------------------------------------------------------------------------------- */
	};
}
