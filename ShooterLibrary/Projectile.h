
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
		static void SetTexture(Texture *pTexture) { s_pTexture = pTexture; }

		/** @brief Called when the game determines it is time to draw a frame.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime);

		/** @brief Called when the game determines it is time to draw a frame.
			@param pGameTime Timing values including time since last update. */
		virtual void Draw(const GameTime *pGameTime);

		/** @brief Activates the projectile.
			@param position The starting position of the projectile.
			@param wasShotByPlayer Indicates if the player fired the projectile. */
		virtual void Activate(const Vector2 &position, bool wasShotByPlayer = true);

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

		/** @brief Sets the amount of damage the projectile inflicts.
			@param damage The damage that the projectile inflicts. */
		virtual void SetDamage(const float damage) { m_damage = damage; }

		/** @brief Sets the direction of the projectile.
			@param direction The normalized direction vector. */
		virtual void SetDirection(const Vector2 direction) { m_direction = direction; }

		/** @brief Gets the speed of the projectile in pixels per second.
			@return Returns the speed of the projectile. */
		virtual float GetSpeed() const { return m_speed; }

		/** @brief Gets the direction of the projectile.
			@return Returns the direction vector of the projectile. */
		virtual Vector2 &GetDirection() { return m_direction; }

		/** @brief Determines if the projectile was shot by a player.
			@return Returns true if the projectile was shot by the player, false otherwise. */
		virtual bool WasShotByPlayer() const { return m_wasShotByPlayer; }

		/** @brief Gets the collision type mask for the projectile.
			@return Returns bit-mask value for the collision type, not including the ship
			type. */
		virtual uint32_t GetProjectileType() const { return COLLISIONTYPE_PROJECTILE; }

		/** @brief Gets a string representation of the projectile.
			@return Returns a string displaying the type of projectile, not including the
			ship type. */
		virtual std::string GetProjectileTypeString() const { return "Projectile"; }


	private:

		static Texture *s_pTexture;

		float m_speed;
		float m_damage;

		Vector2 m_direction;

		bool m_wasShotByPlayer;
	};
}