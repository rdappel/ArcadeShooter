#pragma once

namespace ShooterLibrary
{

	/** @brief Defines the types of game objects that can collide with each other. */
	enum CollisionTypes : uint32_t
	{
		NONE = 0,			/**< Represents an object that has no collision. */

		PLAYER = 1,			/**< Represents a player object. */
		ENEMY = 2,			/**< Represents an enemy object. */

		SHIP = 4,			/**< Represents a ship object. */
		PROJECTILE = 8		/**< Represents a projectile object. */
	};
}
