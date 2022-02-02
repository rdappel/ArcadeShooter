
/*                '888 88888888888 888888888',8888'
					88 888888888888 8888888',8888'
					 8 8888             ,8',8888'
		  ==̲=̲=̲=̲=̲=̲=== 8 8888 ========== ,8 ,̲8̲88̲8_==============
		  /  ____/__ 8_̲88̲8̲8̲8̲88̲88̲8̲8̲8__ ,̲8__/ //_/____ _ ____
		 / /  __ / / / /ˊ __ `// ___/ˊ __  /__ ˊ __ `// __ \
		/ /__/ // /_/ // /_/ // /   / /_/ // // /_/ // / / /
		\_____/ \__,_/ \__,_//_/    \__,_//_/ \__,_//_/ /_/
	  ============== 8 8888 ===== ,8',8888' ===============
					88 8888      ,8',8888888888888
				   ,88 8888     ,8',888888888888888,

						   ファイナル ゼロ

			   Guardian FZ © 2017 - Shuriken Studios LLC          */

#pragma once

#include "GuardianFinalZero.h"

using namespace ShooterLibrary;

namespace GuardianFinalZero
{
	/** @brief Class for a missile launcher. */
	class Launcher : public Gun<Missile>
	{
	public:

		/** @brief Instantiates a new missile launcher object.
			@param isActive Specifies if the weapon is active. */
		Launcher(const bool isActive) : Gun<Missile>(isActive)
		{
			SetTriggerType(TriggerType::SECONDARY);
			SetCooldownSeconds(1.25f);
		}

		virtual ~Launcher() { }

	};
}
