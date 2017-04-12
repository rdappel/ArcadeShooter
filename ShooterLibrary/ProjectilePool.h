
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

	/** @brief Used to recycle projectiles. */
	class ProjectilePool
	{

	public:

		/** @brief Instantiate a projectile pool object.
			@param pLevel A pointer to the current level.
			@param expands Allows the pool to dynamically create
			projectiles when it's empty. */
		ProjectilePool(Level *pLevel, bool expands = true)
		{
			m_pLevel = pLevel;
			m_expands = expands;
		}

		virtual ~ProjectilePool() { }


		/** @brief Add a projectile to the pool.
			@param pProjectile The projectile to add. */
		void Add(Projectile *pProjectile);


		/** @brief Get the next available projectile.
			@return Returns a pointer to the projectile. */
		template <typename T>
		Projectile *GetInactiveProjectile()
		{
			m_projectileIt = m_projectiles.begin();
			for (; m_projectileIt != m_projectiles.end(); m_projectileIt++)
			{
				Projectile *pProjectile = (*m_projectileIt);
				if (!pProjectile->IsActive()) return pProjectile;
			}

			if (m_expands)
			{
				T *pT = new T();
				m_pLevel->AddGameObject(pT);
				m_projectiles.push_back(pT);
				return pT;
			}

			return nullptr;
		}

	private:

		Level *m_pLevel;

		bool m_expands;

		std::vector<Projectile *> m_projectiles;
		std::vector<Projectile *>::iterator m_projectileIt;

	};
}
