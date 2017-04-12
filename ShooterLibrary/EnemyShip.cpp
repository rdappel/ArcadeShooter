
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
	EnemyShip::EnemyShip()
	{
		SetMaxHitPoints(1);
		SetCollisionRadius(20);
	}

	void EnemyShip::Update(const GameTime *pGameTime)
	{
		if (m_delaySeconds > 0)
		{
			m_delaySeconds -= pGameTime->GetTimeElapsed();

			if (m_delaySeconds <= 0)
			{
				GameObject::Activate();
			}
		}

		if (IsActive())
		{
			m_activationSeconds += pGameTime->GetTimeElapsed();
			if (m_activationSeconds > 2 && !IsOnScreen()) Deactivate();
		}

		Ship::Update(pGameTime);
	}

	void EnemyShip::Initialize(const Vector2 position, const double delaySeconds)
	{
		SetPosition(position);
		m_delaySeconds = delaySeconds;

		Ship::Initialize();
	}
}