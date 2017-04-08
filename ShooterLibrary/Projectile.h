
#pragma once

namespace ShooterLibrary
{

	/** @brief Base class for all projectile types. */
	class Projectile : public GameObject
	{

	public:

		Projectile();
		virtual ~Projectile() { }

		/** @brief Resolves which game object is a projectile.
			@param pGameObject1 A pointer to the first game object to test.
			@param pGameObject2 A pointer to the second game object to test.
			@return Returns a pointer to an projectile, or a null pointer. */
		static Projectile *Resolve(GameObject *pGameObject1, GameObject *pGameObject2);

		/** @brief Sets the texture of the player ship.
			@param pTexture A pointer to the texture resource. */
		static void SetTexture(Texture *pTexture);

		/** @brief Called when the game determines it is time to draw a frame.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime);

		/** @brief Called when the game determines it is time to draw a frame.
			@param pGameTime Timing values including time since last update. */
		virtual void Draw(const GameTime *pGameTime);

		/** @brief Activates the projectile.
			@param position The starting position of the projectile.
			@param isShotByPlayer Indicates if the player shot the projectile. */
		virtual void Activate(const Vector2 &position, bool isShotByPlayer = true);

		/** @brief Gets the damage of the projectile.
			@return Returns a the amount of damage the projectile inflicts. */
		virtual float GetDamage() const { return m_damage; }

		/** @brief Gets a string representation of the projectile.
			@return Returns a string displaying the type of object. */
		virtual std::string ToString() const;

		/** @brief Gets the collision type mask.
			@return Returns bit-mask value for the collision type.
			@see CollisionTypes
			@see CollisionManager */
		virtual uint32_t GetCollisionType() const;


	protected:

		/** @brief Sets the speed of the projectile.
			@param speed The desired speed in pixels per second. */
		virtual void SetSpeed(const float speed) { m_speed = speed; }

		/** @brief Gets the speed of the projectile in pixels per second. */
		virtual float GetSpeed() const { return m_speed; }


	private:

		static Texture *s_pTexture;
		static Vector2 s_textureOrigin;

		float m_speed;

		Vector2 m_direction;

		bool m_isShotByPlayer;

		float m_damage;
	};
}