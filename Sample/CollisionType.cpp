
/*   .oooooo..o       .o.       ooo        ooooo ooooooooo.   ooooo        oooooooooooo
	d8P'    `Y8      .888.      `88.       .888' `888   `Y88. `888'        `888'     `8
	Y88bo.          .8"888.      888b     d'888   888   .d88'  888          888
	 `"Y8888o.     .8' `888.     8 Y88. .P  888   888ooo88P'   888          888oooo8
		 `"Y88b   .88ooo8888.    8  `888'   888   888          888          888    "
	oo     .d8P  .8'     `888.   8    Y     888   888          888       o  888       o
	8""88888P'  o88o     o8888o o8o        o888o o888o        o888ooooood8 o888ooooood8

							Sample © 2017 - Shuriken Studios LLC                          */

#include "Sample.h"

namespace Sample
{
	//// These are the Shooter Library Collision Types that we inherit.

	//const CollisionType CollisionType::NONE		= CollisionType(0);
	//const CollisionType CollisionType::PLAYER		= CollisionType(1 << 0);
	//const CollisionType CollisionType::ENEMY		= CollisionType(1 << 1);
	//const CollisionType CollisionType::SHIP		= CollisionType(1 << 2);
	//const CollisionType CollisionType::PROJECTILE	= CollisionType(1 << 3);

	const CollisionType CollisionType::MISSILE		= CollisionType(1 << 4);
	const CollisionType CollisionType::POWERUP		= CollisionType(1 << 5);
	const CollisionType CollisionType::EXPLOSION	= CollisionType(1 << 6);

}