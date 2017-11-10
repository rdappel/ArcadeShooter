
#include "CollisionType.h"

const CollisionType CollisionType::NONE			= CollisionType(0);
const CollisionType CollisionType::PLAYER		= CollisionType(1 << 0);
const CollisionType CollisionType::ENEMY		= CollisionType(1 << 1);
const CollisionType CollisionType::SHIP			= CollisionType(1 << 2);
const CollisionType CollisionType::PROJECTILE	= CollisionType(1 << 3);