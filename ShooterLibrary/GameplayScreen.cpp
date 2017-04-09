
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
	GameplayScreen::GameplayScreen()
	{
		SetTransitionInTime(1.0);
		SetTransitionOutTime(0.5);

		//SetUseRenderTarget();
	}

	GameplayScreen::~GameplayScreen()
	{
		if (m_pLevel) delete m_pLevel;
	}

	void GameplayScreen::LoadContent()
	{
		m_pLevel->SetGameplayScreen(this);
		m_pLevel->LoadContent();

		Show();
	}

	void GameplayScreen::UnloadContent()
	{
		m_pLevel->UnloadContent();
	}


	void GameplayScreen::HandleInput(InputState *pInput)
	{
		if (pInput->IsNewKeyPress(Key::ESCAPE))
		{
			//GetScreenManager()->AddScreen(new PauseMenu(this));
		}

		m_pLevel->HandleInput(pInput);
	}

	void GameplayScreen::Update(const GameTime *pGameTime)
	{
		if (!this->NeedsToBeRemoved())
		{
			bool isPlayerActive = m_pLevel->GetPlayerShip()->IsActive();

			m_pLevel->Update(pGameTime);

			if (isPlayerActive && !m_pLevel->GetPlayerShip()->IsActive())
			{
				//GetScreenManager()->AddScreen(new GameOverScreen(this));
			}

			if (GetTransition() == ScreenTransition::OUT)
			{
				/**
				ALLEGRO_SAMPLE_INSTANCE *pSampleInstance = m_pLevel->GetSampleInstance();

				if (pSampleInstance)
				{
					al_set_sample_instance_gain(pSampleInstance, GetAlpha());
				}
				/**/
			}
		}
	}

	void GameplayScreen::Draw(const GameTime *pGameTime)
	{
		if (!this->NeedsToBeRemoved())
		{
			m_pLevel->Draw(pGameTime);
		}
	}
}