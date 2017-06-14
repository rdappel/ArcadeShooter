
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

#include "ShooterLibrary.h"

namespace ShooterLibrary
{

	/** @brief Base class for all ships. */
	class Ship : public GameObject
	{
	public:

		Ship();
		virtual ~Ship() { }

		/** @brief Updates the game object.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime);

		/** @brief Called when the game determines it is time to draw a frame.
			@param pSpriteBatch The game's sprite batch, used for rendering. */
		virtual void Draw(SpriteBatch *pSpriteBatch) = 0;

		/** @brief Hits the ship, dealing damage to it.
			@param damage The amount of damage to inflict. */
		virtual void Hit(const float damage);

		/** @brief Determines if the ship takes damage.
			@return Returns true if the ship is invulnurable (does not take damage),
			false otherwise. */
		virtual bool IsInvulnurable() const { return m_isInvulnurable; }

		/** @brief Sets whether or not the ship takes damage.
			@param isInvulnurable Pass true to make the ship invulnurable (does not
			take damage), of false to make the ship take damage. */
		virtual void SetInvulnurable(bool isInvulnurable = true) { m_isInvulnurable = isInvulnurable; }

		/** @brief Gets a string representation of the ship.
			@return Returns a string displaying the type of object. */
		virtual std::string ToString() const { return "Ship"; }

		/** @brief Gets the collision type mask.
			@return Returns bit-mask value for the collision type.
			@see CollisionTypes
			@see CollisionManager */
		virtual CollisionType GetCollisionType() const = 0;

		/** @brief Attaches a weapon to the ship.
			@param pWeapon The weapon to attach.
			@param position The position, on the ship, to attach the weapon. */
		virtual void AttachWeapon(Weapon *pWeapon, Vector2 position);

		/** @brief Gets the speed of the projectile in pixels per second. */
		virtual float GetSpeed() const { return m_speed; }

		/** @brief Sets the speed of the ship.
			@param speed The desired speed in pixels per second. */
		virtual void SetSpeed(const float speed) { m_speed = speed; }

		/** @brief Sets the maximum hit points of the ship.
			@param hitPoints The desired hit point maximum. */
		virtual void SetMaxHitPoints(const float hitPoints) { m_maxHitPoints = hitPoints; }


	protected:

		/** @brief Initializes the ship. */
		virtual void Initialize();

		/** @brief Fires the ship's weapons.
			@param type The type mask for weapons that should be fired. */
		virtual void FireWeapons(TriggerType type = TriggerType::ALL);

		/** @brief Gets the weapon at the specified index.
			@param index The index of the desired weapon.
			@return Returns a pointer to the specified weapon. */
		virtual Weapon *GetWeapon(const int index) { if (index < m_weapons.size()) return m_weapons[index]; return nullptr; }

		/** @brief Gets the amount of hit points that the ship has.
			@return Returns the amount of hit points remaining. */
		virtual float GetHitPoints() const { return m_hitPoints; }

		/** @brief Gets the maximum amount of hit points that the ship has.
		@return Returns the maximum amount of hit points. */
		virtual float GetMaxHitPoints() const { return m_maxHitPoints; }


	private:

		float m_speed;

		float m_hitPoints;
		float m_maxHitPoints;

		bool m_isInvulnurable;

		std::vector<Weapon *> m_weapons;
		std::vector<Weapon *>::iterator m_weaponIt;
	};
}