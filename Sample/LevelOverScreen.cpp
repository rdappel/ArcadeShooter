
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

	Texture *LevelOverScreen::s_pGameOverTexture = nullptr;
	Texture *LevelOverScreen::s_pLevelCompleteTexture = nullptr;

	LevelOverScreen::LevelOverScreen(GameplayScreen *pGameplayScreen, const bool levelCompleted)
	{
		m_pGameplayScreen = pGameplayScreen;
		m_levelCompleted = levelCompleted;

		SetTransitionInTime(3.0);
		SetTransitionOutTime(pGameplayScreen->GetTransitionOutTime());
		SetPassthroughFlags(true, true);

		m_secondsUntilExit = 10;

		Show();
	}

	void LevelOverScreen::HandleInput(const InputState *pInput) 
	{
		if (pInput->IsNewKeyPress(Key::ENTER))
		{
			m_secondsUntilExit = 0;
		}
	}

	void LevelOverScreen::Update(const GameTime *pGameTime)
	{
		if (m_secondsUntilExit >= 0)
		{
			m_secondsUntilExit -= pGameTime->GetTimeElapsed();
			if (m_secondsUntilExit < 0)
			{
				Exit();
				m_pGameplayScreen->Exit();
			}
		}
	}

	void LevelOverScreen::Draw(SpriteBatch *pSpriteBatch)
	{
		pSpriteBatch->Begin();
		Texture *pTexture = (m_levelCompleted) ? s_pLevelCompleteTexture : s_pGameOverTexture;
		pSpriteBatch->Draw(pTexture, Game::GetScreenCenter(), Color::White * GetAlpha(), pTexture->GetCenter());
		pSpriteBatch->End();
	}
}
