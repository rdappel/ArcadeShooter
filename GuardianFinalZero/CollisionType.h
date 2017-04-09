
#pragma once

namespace GuardianFinalZero
{
	/** @brief Defines the types of game objects that can collide with each other. */
	enum CollisionType : uint32_t
	{
		/* Same as Shooter Library */
		NONE = 0,
		PLAYER = 1,
		ENEMY = 2,
		SHIP = 4,
		PROJECTILE = 8,
		/* ----------------------- */

		MISSILE = 16,

		POWER_UP = 32,
		EXPLOSION = 64
	};
}
