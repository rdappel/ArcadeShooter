
#pragma once

namespace GuardianFinalZero
{
	enum CollisionTypes
	{
		/* Same as Shooter Library */
		NONE = 0,

		PLAYER = 1,
		ENEMY = 2,

		SHIP = 4,
		PROJECTILE = 8,
		/* ======================= */

		MISSILE = 16,

		POWER_UP = 32,
		EXPLOSION = 64
	};
}
