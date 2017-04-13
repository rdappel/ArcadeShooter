
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
	void Background::LoadContent(ResourceManager *pResourceManager)
	{
		m_pTexture = pResourceManager->Load<Texture>("Textures\\StarBackground_01.png");
		m_position = Vector2(800, 0);
	}

	void Background::Update(const GameTime *pGameTime)
	{
		m_position.Y += GetScrollSpeed() * pGameTime->GetTimeElapsed();
		if (m_position.Y >= Game::GetScreenHeight())
		{
			m_position.Y -= 1600;
		}
	}

	void Background::Draw(SpriteBatch *pSpriteBatch)
	{
		Vector2 origin = Vector2(800, 0);
		pSpriteBatch->Draw(m_pTexture, m_position, Color::White, origin);

		if (m_position.Y > 0)
		{
			pSpriteBatch->Draw(m_pTexture, m_position - Vector2(0, 1600), Color::White, origin);
		}
	}
}
