
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

	template <typename T>
	class Gun : public Weapon
	{

	public:

		/** @brief Instantiates a new Weapon object.
		@param pGameObject The game object that the weapon is attached to. */
		Gun(bool isActive = false)
			: Weapon(isActive) { }

		virtual ~Gun() { }

		/** @brief Called when the game determines it is time to draw a frame.
		@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime) { }

		/** @brief Called when the game determines it is time to draw a frame.
		@param pGameTime Timing values including time since last update. */
		virtual void Draw(const GameTime *pGameTime) { }

		/** @brief Fires the weapon. */
		virtual void Fire(TriggerType triggerType)
		{
			bool match = (GetTriggerType() & triggerType) > 0;
			if (match && IsActive())
			{
				Projectile *pProjectile = m_pProjectilePool->GetInactiveProjectile<T>();
				if (pProjectile)
				{
					pProjectile->Activate(GetPosition(), true);
				}
			}
		}

		virtual void SetProjectilePool(ProjectilePool *pool) { m_pProjectilePool = pool; }

		virtual bool CanFire() const { return true; }


	private:

		ProjectilePool *m_pProjectilePool;

	};
}
