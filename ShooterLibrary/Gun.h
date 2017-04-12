
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

	/** A weapon type that shoots. */
	template <typename T>
	class Gun : public Weapon
	{

	public:

		/** @brief Instantiates a new Weapon object.
			@param isActive Specifies if the weapon is active. */
		Gun(bool isActive) : Weapon(isActive)
		{
			m_cooldown = 0;
			m_cooldownSeconds = 0.25;
		}

		virtual ~Gun() { }

		/** @brief Called when the game determines it is time to draw a frame.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime)
		{
			if (m_cooldown > 0) m_cooldown -= pGameTime->GetTimeElapsed();
		}

		/** @brief Called when the game determines it is time to draw a frame.
			@param pGameTime Timing values including time since last update. */
		virtual void Draw(SpriteBatch *pSpriteBatch) { }

		/** @brief Fires the weapon. */
		virtual void Fire(TriggerType triggerType)
		{
			if (IsActive() && CanFire())
			{
				if (GetTriggerType() & triggerType)
				{
					Projectile *pProjectile = m_pProjectilePool->GetInactiveProjectile<T>();
					if (pProjectile)
					{
						pProjectile->Activate(GetPosition(), true);
						m_cooldown = m_cooldownSeconds;
					}
				}
			}
		}

		virtual void SetProjectilePool(ProjectilePool *pool) { m_pProjectilePool = pool; }

		virtual bool CanFire() const { return m_cooldown <= 0; }

		virtual void SetCooldownSeconds(const float seconds) { m_cooldownSeconds = seconds; }

		virtual void ResetCooldown() { m_cooldown = 0; }


	private:

		ProjectilePool *m_pProjectilePool;

		float m_cooldown;
		float m_cooldownSeconds;

	};
}
