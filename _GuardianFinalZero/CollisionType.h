
/*                '888 88888888888 888888888',8888'
                    88 888888888888 8888888',8888'
                     8 8888             ,8',8888'
          ==̲=̲=̲=̲=̲=̲=== 8 8888 ========== ,8 ,̲8̲88̲8_==============
          /  ____/__ 8_̲88̲8̲8̲8̲88̲88̲8̲8̲8__ ,̲8__/ //_/____ _ ____
	     / /  __ / / / /ˊ __ `// ___/ˊ __  /__ ˊ __ `// __ \
	    / /__/ // /_/ // /_/ // /   / /_/ // // /_/ // / / /
	    \_____/ \__,_/ \__,_//_/    \__,_//_/ \__,_//_/ /_/
      ============== 8 8888 ===== ,8',8888' ===============
                    88 8888      ,8',8888888888888 
                   ,88 8888     ,8',888888888888888,
				   
				           ファイナル ゼロ

               Guardian FZ © 2017 - Shuriken Studios LLC          */

#pragma once

namespace GuardianFinalZero
{

	class CollisionType : public ShooterLibrary::CollisionType
	{

	public:

		static const CollisionType MISSILE;
		static const CollisionType COLLECTABLE;
		static const CollisionType EXPLOSION;


	protected:

		CollisionType(uint32_t value) : ShooterLibrary::CollisionType(value) { }

	};

	//// These are the Shooter Library Collision Types that we inherit.

	//const CollisionType CollisionType::NONE		= CollisionType(0);
	//const CollisionType CollisionType::PLAYER		= CollisionType(1 << 0);
	//const CollisionType CollisionType::ENEMY		= CollisionType(1 << 1);
	//const CollisionType CollisionType::SHIP		= CollisionType(1 << 2);
	//const CollisionType CollisionType::PROJECTILE	= CollisionType(1 << 3);

	const CollisionType CollisionType::MISSILE		= CollisionType(1 << 4);
	const CollisionType CollisionType::COLLECTABLE	= CollisionType(1 << 5);
	const CollisionType CollisionType::EXPLOSION	= CollisionType(1 << 6);

}
