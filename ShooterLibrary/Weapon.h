
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
	/** @brief Base class for all Weapons */
	class Weapon
	{ 
	public:

		/** @brief Instantiates a new weapon object.
			@param isActive Specifies if the weapon is active. */
		Weapon(bool isActive = true)
		{
			m_isActive = isActive;
			SetTriggerType(TriggerType::PRIMARY);
		}

		virtual ~Weapon() { }

		/** @brief Called when the game determines it is time to draw a frame.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime) { };

		/** @brief Called when the game determines it is time to draw a frame.
		@param pSpriteBatch The game's sprite batch, used for rendering. */
		virtual void Draw(SpriteBatch *pSpriteBatch) { };

		/** @brief Fires the weapon.
			@param triggerType Specifies how the weapon is triggered. */
		virtual void Fire(TriggerType triggerType) = 0;

		/** @brief Sets the game object that the weapon is attached to.
			@param pGameObject The attached game object. */
		virtual void SetGameObject(GameObject *pGameObject) { m_pGameObject = pGameObject; }

		/** @brief Sets the position on the parented game object.
			@param offset The position on the game object. */
		virtual void SetOffset(Vector2 offset) { m_offset = offset; }

		/** @brief Sets how the weapon is triggered.
			@param triggerType Specifies how the weapon is triggered. */
		virtual void SetTriggerType(TriggerType triggerType) { m_triggerType = triggerType; }

		/** @brief Sets the pool where the weapon gets it's projectiles.
			@param pPool The pool to use. */
		virtual void SetProjectilePool(ProjectilePool *pPool) = 0;

		/** @brief Activates the weapon. */
		virtual void Activate() { m_isActive = true; }

		/** @brief Deactivates the weapon. */
		virtual void Dectivate() { m_isActive = false; }

		/** @brief Determines if the weapon is active.
			@return Returns true if the weapon is active, false otherwise. */
		virtual bool IsActive() const { return m_isActive && m_pGameObject->IsActive(); }


	protected:

		/** @brief Gets the action that triggers the weapon.
			@return Returns the type of trigger that fires the weapon. */
		virtual TriggerType GetTriggerType() const { return m_triggerType; }

		/** @brief Gets the weapon's position.
			@return Returns the position of the weapon. */
		virtual Vector2 GetPosition() const { return m_pGameObject->GetPosition() + m_offset; }


	private:

		bool m_isActive;

		GameObject *m_pGameObject;

		Vector2 m_offset;

		TriggerType m_triggerType;

	};
}