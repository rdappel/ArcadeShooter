
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

using namespace ShooterLibrary;

namespace GuardianFinalZero
{

	void GameplayScreenRemove(Screen *pScreen)
	{
		GameplayScreen *pGameplayScreen = (GameplayScreen *)pScreen;

		uint8_t nextLevel = pGameplayScreen->GetNextLevelIndex();
		pScreen->GetScreenManager()->AddScreen(new GameplayScreen(nextLevel, pGameplayScreen->GetPlayerData()));
	}


	GameplayScreen::GameplayScreen(const uint8_t levelToLoad, PlayerData *pPlayerData)
	{
		m_pLevel = nullptr;
		GameObject::SetCurrentLevel(nullptr);

		for (int i = 0; i < InputState::MAX_NUM_GAMEPADSTATES; i++)
		{
			m_playerData[i] = pPlayerData[i];
		}

		switch (levelToLoad)
		{
		case 1: m_pLevel = new Level01(this); break;
		//case 2: m_pLevel = new Level02(this); break;
		}

		if (m_pLevel)
		{
			SetTransitionInTime(1.0);
			SetTransitionOutTime(0.5);
			SetRemoveCallback(GameplayScreenRemove);

			UseRenderTarget();
			Show();
		}
	}

	GameplayScreen::~GameplayScreen()
	{
		delete m_pLevel;
	}


	void GameplayScreen::LoadContent(ResourceManager *pResourceManager)
	{
		if (m_pLevel) m_pLevel->LoadContent(pResourceManager);
		else
		{
			GetScreenManager()->AddScreen(new MainMenuScreen());
			SetTransitionOutTime(0);
			Exit();
		}
	}


	void GameplayScreen::HandleInput(const InputState *pInput)
	{
		int8_t playerIndex = -1;

		if (pInput->IsNewKeyPress(Key::ESCAPE) ||
			pInput->IsNewButtonPress(Button::START, playerIndex))
		{
			//GetScreenManager()->AddScreen(new PauseMenuScreen(this, playerIndex));
		}

		m_pLevel->HandleInput(pInput);
	}


	void GameplayScreen::Draw(SpriteBatch *pSpriteBatch)
	{
		if (!this->NeedsToBeRemoved()) m_pLevel->Draw(pSpriteBatch);
	}


	void GameplayScreen::Update(const GameTime *pGameTime)
	{
		if (!this->NeedsToBeRemoved())
		{
			m_pLevel->Update(pGameTime);
		}
	}

	int GameplayScreen::GetNextLevelIndex() const
	{
		if (m_pLevel && m_pLevel->IsComplete())
		{
			return m_pLevel->GetNextLevelIndex();
		}

		return -1;
	}
}