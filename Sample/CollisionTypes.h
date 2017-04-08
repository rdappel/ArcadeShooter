#pragma once

namespace Sample
{
	/** @brief Defines the types of game objects that can collide with each other. */
	enum CollisionTypes : uint32_t
	{
		/* Same as Shooter Library */
		NONE = 0,
		PLAYER = 1,
		ENEMY = 2,
		SHIP = 4,
		PROJECTILE = 8,
		/* ----------------------- */

		POWER_UP = 16
	};
}
