
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

	/** @brief Callback function for when the gameplay screen is
		removed from the screen manager.
		@param pScreen The screen that is about to be removed. */
	void GameplayScreenRemove(Screen *pScreen)
	{
		pScreen->GetScreenManager()->AddScreen(new MainMenuScreen());
	}


	GameplayScreen::GameplayScreen()
	{
		SetTransitionInTime(1.0);
		SetTransitionOutTime(0.5);
		SetRemoveCallback(GameplayScreenRemove);

		m_pLevel = new Level01(this);

		Show();
	}


	void GameplayScreen::LoadContent(ResourceManager *pResourceManager)
	{
		m_pLevel->LoadContent(pResourceManager);
	}


	void GameplayScreen::HandleInput(const InputState *pInput)
	{
		if (pInput->IsNewKeyPress(Key::ESCAPE))
		{
			GetScreenManager()->AddScreen(new PauseMenuScreen(this));
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
}