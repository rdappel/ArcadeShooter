
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

	/** @brief Base class for enemy ships that have components. */
	class ComponentEnemyShip : public EnemyShip
	{

	public:

		ComponentEnemyShip() { }
		virtual ~ComponentEnemyShip() { }

		/** @brief Called when the game has determined that game logic needs
			to be processed.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime* pGameTime) = 0;

		/** @brief Fires the ships weapons. */
		virtual void Fire() { }

		/** @brief Hits the ship, dealing damage to it.
			@param damage The amount of damage to inflict. */
		virtual void Hit(const float damage) = 0;

		/** @brief Gets a string representation of the enemy ship.
			@return Returns a string displaying the type of object. */
		virtual std::string ToString() const { return "Component Enemy Ship"; }

	};
}