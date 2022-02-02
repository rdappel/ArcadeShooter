
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

#include "GuardianFinalZero.h"

namespace GuardianFinalZero
{
	void Explosion::Update(const GameTime *pGameTime)
	{
		m_pAnimation->Update(pGameTime);
	}


	void Explosion::Draw(SpriteBatch *pSpriteBatch)
	{
		if (IsActive())
		{
			Vector2 center = m_pAnimation->GetFrame(0)->GetCenter();
			pSpriteBatch->Draw(m_pAnimation, m_position, Color::White, center, Vector2::ONE * m_scale, m_rotation);
		}
	}


	void Explosion::Activate(const Vector2 position, const float scale) 
	{
		SetPosition(position);
		m_scale = scale;
		m_rotation = Math::GetRandomFloat() * 2 * Math::PI;
		m_pAnimation->SetLoopCount(0);
		m_pAnimation->Play();
	}

}