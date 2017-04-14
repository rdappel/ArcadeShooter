
/*   .oooooo..o       .o.       ooo        ooooo ooooooooo.   ooooo        oooooooooooo
	d8P'    `Y8      .888.      `88.       .888' `888   `Y88. `888'        `888'     `8
	Y88bo.          .8"888.      888b     d'888   888   .d88'  888          888
	 `"Y8888o.     .8' `888.     8 Y88. .P  888   888ooo88P'   888          888oooo8
		 `"Y88b   .88ooo8888.    8  `888'   888   888          888          888    "
	oo     .d8P  .8'     `888.   8    Y     888   888          888       o  888       o
	8""88888P'  o88o     o8888o o8o        o888o o888o        o888ooooood8 o888ooooood8

					        Sample © 2017 - Shuriken Studios LLC                          */

#include "Sample.h"

namespace Sample
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
			pSpriteBatch->Draw(m_pAnimation, m_position, Color::White, center, Vector2::One * m_scale, m_rotation);
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