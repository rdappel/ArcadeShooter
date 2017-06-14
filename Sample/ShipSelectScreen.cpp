
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
	ShipSelectScreen::ShipSelectScreen(int8_t controllingPlayerIndex)
	{
		m_controllingPlayerIndex = controllingPlayerIndex;
		m_pFont = nullptr;
		
		SetTransitionInTime(1.0);

		Show();
	}

	void ShipSelectScreen::LoadContent(ResourceManager *pResourceManager)
	{
		m_pFont = pResourceManager->Load<Font>("Fonts\\Ethnocentric.ttf");
	}

	void ShipSelectScreen::HandleInput(const InputState *pInput)
	{
		Screen::HandleInput(pInput);
	}

	void ShipSelectScreen::Update(const GameTime *pGameTime)
	{
	}

	void ShipSelectScreen::Draw(SpriteBatch *pSpriteBatch)
	{
		std::string text = "Press A\nto Join";

		pSpriteBatch->Begin();

		int maxPlayers = (int)InputState::MAX_NUM_GAMEPADSTATES;
		int spacing = (int)(Game::GetScreenWidth() / (float)(maxPlayers + 1));
		int y = Game::GetScreenHeight() / 2;
		
		for (int i = 0; i < maxPlayers; i++)
		{
			Color color = PlayerShip::GetShipColor(i);
			pSpriteBatch->DrawString(m_pFont, &text, Vector2(spacing * (i + 1), y), color * GetAlpha(), TextAlign::CENTER);
		}
			
		pSpriteBatch->End();
	}
}
