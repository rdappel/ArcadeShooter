
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

namespace GuardianFinalZero
{

	class Coin : public ShooterLibrary::GameObject
	{

	public:

		Coin();
		virtual ~Coin() { }

		static void SetTexture(Texture* pTexture) { s_pTexture = pTexture; }
		static void SetColorTexture(Texture* pTexture) { s_pColorTexture = pTexture; }

		virtual int GetValue() const { return m_value; }

		virtual void Draw(SpriteBatch* pSpriteBatch);

		virtual ShooterLibrary::CollisionType GetCollisionType() const { return CollisionType::COLLECTABLE; }


	private:

		static Texture* s_pTexture;
		static Texture* s_pColorTexture;

		int m_value;

	};
}