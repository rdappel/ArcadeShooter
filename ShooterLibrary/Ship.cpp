
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

#include "ShooterLibrary.h"

namespace ShooterLibrary
{
	Ship::Ship()
	{
		SetPosition(0, 0);
		SetCollisionRadius(10);

		m_speed = 300;
		m_maxHitPoints = 3;
		m_isInvulnurable = false;

		Initialize();
	}

	void Ship::Hit(const float damage)
	{
		if (!m_isInvulnurable)
		{
			m_hitPoints -= damage;

			if (m_hitPoints <= 0)
			{
				GameObject::Deactivate();
			}
		}
	}

	void Ship::Initialize()
	{
		m_hitPoints = m_maxHitPoints;
	}

	void Ship::FireWeapons(TriggerType type)
	{
		m_weaponIt = m_weapons.begin();
		for (; m_weaponIt != m_weapons.end(); m_weaponIt++)
		{
			(*m_weaponIt)->Fire(type);
		}
	}
	
	void Ship::AttachWeapon(Weapon *pWeapon, Vector2 position)
	{
		pWeapon->SetGameObject(this);
		pWeapon->SetOffset(position);
		m_weapons.push_back(pWeapon);
	}
}