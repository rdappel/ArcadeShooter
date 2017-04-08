
#pragma once

namespace ShooterLibrary
{

	/** @brief Base class for enemy ships. */
	class EnemyShip : public Ship
	{

	public:

		EnemyShip();
		virtual ~EnemyShip() { }

		/** @brief Resolves which game object is an enemy ship.
			@param pGameObject1 A pointer to the first game object to test. 
			@param pGameObject2 A pointer to the second game object to test.
			@return Returns a pointer to an enemy ship, or a null pointer. */
		static EnemyShip *Resolve(GameObject *pGameObject1, GameObject *pGameObject2);

		/** @brief Called when the game has determined that game logic needs
			to be processed.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime);

		/** @brief Called when the game determines it is time to draw a frame.
			@param pGameTime Timing values including time since last update. */
		virtual void Draw(const GameTime *pGameTime) = 0;

		/** @brief Initializes the enemy at the beginning of the level.
			@param position The starting position of the enemy.
			@param delaySeconds The number of seconds before the enemy activates. */
		virtual void Initialize(const Vector2 position, const double delaySeconds);

		/** @brief Fires the ships weapons. */
		virtual void Fire() { }

		/** @brief Gets a string representation of the enemy ship.
			@return Returns a string displaying the type of object. */
		virtual std::string ToString() const { return "EnemyShip"; }

		/** @brief Gets the collision type mask.
			@return Returns bit-mask value for the collision type.
			@see CollisionTypes
			@see CollisionManager */
		virtual uint32_t GetCollisionType() const { return ENEMY | SHIP; }


	protected:

		/** @brief Gets the number of seconds before the enemy activates.
			@return Returns the delay before activation in seconds. */
		virtual double GetDelaySeconds() const { return m_delaySeconds; }


	private:

		double m_delaySeconds;

	};
}