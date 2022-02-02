
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

using ShooterLibrary::Projectile;
using ShooterLibrary::ProjectilePool;

namespace GuardianFinalZero
{
	/** @brief Base class for all Guardian Final Zero levels. */
	class Level : public ShooterLibrary::Level
	{

	public:

		Level(GameplayScreen *pGameplayScreen);

		virtual ~Level() { }

		virtual void LoadContent(ResourceManager *pResourceManager);

		virtual void HandleInput(const InputState *pInput);

		virtual ShooterLibrary::Projectile *GetInactiveProjectile();

		virtual int GetNextLevelIndex() const = 0;

		virtual bool IsComplete() { return m_isComplete; }


	private:

		bool m_isComplete;

		GameplayScreen* m_pGameplayScreen = nullptr;

		std::vector<ShooterLibrary::Projectile *> m_projectiles;
		std::vector<ShooterLibrary::Projectile *>::iterator m_projectileIt;

	};
}