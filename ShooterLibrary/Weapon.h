
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

		Weapon(bool isActive = true)
		{
			m_isActive = isActive;
			SetFireType(TRIGGERTYPE_PRIMARY);
		}

		virtual ~Weapon() { }

		virtual void Update(const GameTime *pGameTime) = 0;

		/** @brief Called when the game determines it is time to draw a frame.
		@param pGameTime Timing values including time since last update. */
		virtual void Draw(SpriteBatch *pSpriteBatch) = 0;

		/** @brief Fires the weapon. */
		virtual void Fire(TriggerType triggerType) = 0;

		virtual void SetGameObject(GameObject *pGameObject) { m_pGameObject = pGameObject; }

		virtual void SetOffset(Vector2 offset) { m_offset = offset; }

		virtual void SetFireType(TriggerType fireType) { m_triggerType = fireType; }

		virtual void SetProjectilePool(ProjectilePool *pool) = 0;

		virtual void Activate() { m_isActive = true; }

		virtual void Dectivate() { m_isActive = false; }

		virtual bool IsActive() const { return m_isActive && m_pGameObject->IsActive(); }

	protected:

		virtual TriggerType GetTriggerType() const { return m_triggerType; }

		virtual Vector2 GetPosition() const { return m_pGameObject->GetPosition() + m_offset; }


	private:

		bool m_isActive;

		GameObject *m_pGameObject;

		Vector2 m_offset;

		TriggerType m_triggerType;

	};
}