
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

	/** @brief Base class for enemy ship components. */
	class EnemyShipComponent : public GameObject
	{

	public:

		EnemyShipComponent();
		virtual ~EnemyShipComponent() { }

		/** @brief Called when the game has determined that game logic needs
			to be processed.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime* pGameTime);

		/** @brief Called when the game determines it is time to draw a frame.
			@param pSpriteBatch The game's sprite batch, used for rendering. */
		virtual void Draw(SpriteBatch* pSpriteBatch) = 0;

		/** @brief Initializes the enemy at the beginning of the level.
			@param position The starting position of the enemy.
			@param delaySeconds The number of seconds before the enemy activates. */
		virtual void Initialize(const Vector2 position, const double delaySeconds);

		/** @brief Fires the ships weapons. */
		virtual void Fire() { }

		/** @brief Hits the ship, dealing damage to it.
			@param damage The amount of damage to inflict. */
		virtual void Hit(const float damage);

		/** @brief Gets a string representation of the enemy ship.
			@return Returns a string displaying the type of object. */
		virtual std::string ToString() const { return "Enemy Ship"; }

		/** @brief Gets the collision type mask.
			@return Returns bit-mask value for the collision type.
			@see CollisionTypes
			@see CollisionManager */
		virtual CollisionType GetCollisionType() const { return CollisionType::ENEMY | CollisionType::SHIP; }


	protected:

		/** @brief Gets the number of seconds before the enemy activates.
			@return Returns the delay before activation in seconds. */
		virtual double GetDelaySeconds() const { return m_delaySeconds; }


	private:

		double m_delaySeconds = 0;

		double m_activationSeconds = 0;

	};
}