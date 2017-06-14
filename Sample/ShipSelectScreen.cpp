
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

	/** @brief Callback function for when the screen is removed from
		the screen manager.
		@param pScreen The screen that is about to be removed. */
	void RemoveShipSelect(Screen *pScreen)
	{
		ShipSelectScreen *pShipSelectScreen = (ShipSelectScreen *)pScreen;
		PlayerData *pPlayerData = pShipSelectScreen->GetPlayerData();
		pScreen->GetScreenManager()->AddScreen(new GameplayScreen(1, pPlayerData));
	}


	ShipSelectScreen::ShipSelectScreen(int8_t controllingPlayerIndex)
	{
		m_controllingPlayerIndex = controllingPlayerIndex;
		m_pFont = nullptr;

		SetTransitionInTime(0);
		SetTransitionInTime(0.5);

		SetRemoveCallback(RemoveShipSelect);

		Show();
	}

	ShipSelectScreen::~ShipSelectScreen()
	{
		for (int i = 0; i < MAX_PLAYERS; i++)
		{
			delete m_pPlayerShips[i];
		}
	}


	void ShipSelectScreen::LoadContent(ResourceManager *pResourceManager)
	{
		m_pFont = pResourceManager->Load<Font>("Fonts\\Ethnocentric.ttf");

		for (int i = 0; i < MAX_PLAYERS; i++)
		{
			m_pPlayerShips[i] = new PlayerShip(i);
			m_pPlayerShips[i]->LoadContent(pResourceManager);

			m_hasJoined[i] = (i == m_controllingPlayerIndex);
			m_gamePadActive[i] = true;
			m_bodyStyleIndices[i] = 0;
		}
	}


	void ShipSelectScreen::HandleInput(const InputState *pInput)
	{
		Screen::HandleInput(pInput);

		m_activeGamePadCount = 0;
		for (int i = 0; i < MAX_PLAYERS; i++)
		{
			m_gamePadActive[i] = pInput->GetGamePadState(i).IsConnected;
			if (m_gamePadActive[i]) m_activeGamePadCount++;
			playerData[i].IsActive = m_gamePadActive[i] && m_hasJoined[i];
		}

		int8_t playerIndex = 0;

		if (m_activeGamePadCount == 0)
		{
			playerData[0].IsActive = true;
			if (pInput->IsNewKeyPress(Key::ENTER)) Exit();
		}

		if (pInput->IsNewButtonPress(Button::A, playerIndex))
		{
			if (m_hasJoined[playerIndex]) Exit();
			else m_hasJoined[playerIndex] = true;

			playerData[playerIndex].IsActive = m_gamePadActive[playerIndex] && m_hasJoined[playerIndex];
		}

		if (pInput->IsNewButtonPress(Button::B, playerIndex))
		{
			m_hasJoined[playerIndex] = false;

			playerData[playerIndex].IsActive = m_gamePadActive[playerIndex] && m_hasJoined[playerIndex];
		}

		if (pInput->IsNewButtonPress(Button::DPAD_LEFT, playerIndex) || pInput->IsNewKeyPress(Key::LEFT))
		{
			m_bodyStyleIndices[playerIndex]--;
			if (m_bodyStyleIndices[playerIndex] < 0) m_bodyStyleIndices[playerIndex] += PlayerShip::BODY_STYLE_COUNT;

			m_pPlayerShips[playerIndex]->SetBodyStyleIndex(m_bodyStyleIndices[playerIndex]);
			m_pPlayerShips[playerIndex]->LoadContent(GetGame()->GetResourceManager());

			playerData[playerIndex].BodyStyleIndex = (uint8_t)m_bodyStyleIndices[playerIndex];
		}

		if (pInput->IsNewButtonPress(Button::DPAD_RIGHT, playerIndex) || pInput->IsNewKeyPress(Key::RIGHT))
		{
			m_bodyStyleIndices[playerIndex]++;
			if (m_bodyStyleIndices[playerIndex] == PlayerShip::BODY_STYLE_COUNT) m_bodyStyleIndices[playerIndex] = 0;

			m_pPlayerShips[playerIndex]->SetBodyStyleIndex(m_bodyStyleIndices[playerIndex]);
			m_pPlayerShips[playerIndex]->LoadContent(GetGame()->GetResourceManager());

			playerData[playerIndex].BodyStyleIndex = (uint8_t)m_bodyStyleIndices[playerIndex];
		}
	}


	void ShipSelectScreen::Update(const GameTime *pGameTime)
	{
		for (int i = 0; i < MAX_PLAYERS; i++)
		{
			m_pPlayerShips[i]->Update(pGameTime);
		}
	}


	void ShipSelectScreen::Draw(SpriteBatch *pSpriteBatch)
	{
		std::string joinText = "Press A\nto Join";

		pSpriteBatch->Begin();

		float count = m_activeGamePadCount;
		if (count == 0) count++;
		int spacing = (int)(Game::GetScreenWidth() / (count + 1));
		int y = Game::GetScreenHeight() / 2;

		int slot = 0;

		for (int i = 0; i < MAX_PLAYERS; i++)
		{
			if (m_gamePadActive[i] || i == 0)
			{
				Color color = PlayerShip::GetShipColor(i);

				if (m_hasJoined[i])
				{
					m_pPlayerShips[i]->SetDisplayPosition(Vector2(spacing * (slot + 1), y));
					m_pPlayerShips[i]->Draw(pSpriteBatch);
				}
				else
				{
					pSpriteBatch->DrawString(m_pFont, &joinText, Vector2(spacing * (slot + 1), y), color * GetAlpha(), TextAlign::CENTER);
				}

				slot++;
			}
		}

		pSpriteBatch->End();
	}
}
