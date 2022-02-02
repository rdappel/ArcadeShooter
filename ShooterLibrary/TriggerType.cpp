
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

	const TriggerType TriggerType::NONE			= TriggerType(0);
	const TriggerType TriggerType::PRIMARY		= TriggerType(1 << 0);
	const TriggerType TriggerType::SECONDARY	= TriggerType(1 << 1);
	const TriggerType TriggerType::SPECIAL		= TriggerType(1 << 2);
	const TriggerType TriggerType::ALL			= TriggerType((uint32_t)-1);

	TriggerType::TriggerType(uint32_t value)
	{
		m_value = value;
	}

}
