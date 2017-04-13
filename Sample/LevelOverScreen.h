
/*   .oooooo..o       .o.       ooo        ooooo ooooooooo.   ooooo        oooooooooooo
	d8P'    `Y8      .888.      `88.       .888' `888   `Y88. `888'        `888'     `8
	Y88bo.          .8"888.      888b     d'888   888   .d88'  888          888
	 `"Y8888o.     .8' `888.     8 Y88. .P  888   888ooo88P'   888          888oooo8
		 `"Y88b   .88ooo8888.    8  `888'   888   888          888          888    "
	oo     .d8P  .8'     `888.   8    Y     888   888          888       o  888       o
	8""88888P'  o88o     o8888o o8o        o888o o888o        o888ooooood8 o888ooooood8

							Sample © 2017 - Shuriken Studios LLC                          */

#pragma once

namespace Sample
{
	class GameplayScreen;

	/** @brief The pause menu for the sample game. */
	class LevelOverScreen : public KatanaEngine::Screen
	{

	public:

		/** @brief Instantiate a pause menu screen.
			@param pGameplayScreen The underlaying gameplay screen. */
		LevelOverScreen(GameplayScreen *pGameplayScreen, const bool levelCompleted);
		virtual ~LevelOverScreen() { }

		/** @brief Sets the texture to display when the game is over.
			@param pTexture The texture to display. */
		static void SetGameOverTexture(Texture *pTexture) { s_pGameOverTexture = pTexture; }

		/** @brief Sets the texture to display when the level is completed.
			@param pTexture The texture to display. */
		static void SetLevelCompleteTexture(Texture *pTexture) { s_pLevelCompleteTexture = pTexture; }

		/** @brief Called when the game has determined that player input needs to be processed.
			@param pInput The current state of all player input devices. */
		virtual void HandleInput(const InputState *pInput);

		/** @brief Called when the game has determined that screen logic needs to be processed.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime);

		/** @brief Called when the game determines it is time to draw a frame.
			@param pSpriteBatch The game's sprite batch, used for rendering. */
		virtual void Draw(SpriteBatch *pSpriteBatch);

		/** @brief Gets the underlaying gameplay screen.
			@return Returns a pointer to the gameplay screen underneath the pause
			menu screen. */
		virtual GameplayScreen *GetGameplayScreen() const { return m_pGameplayScreen; }


	private:

		static Texture *s_pGameOverTexture;
		static Texture *s_pLevelCompleteTexture;

		GameplayScreen *m_pGameplayScreen;

		bool m_levelCompleted;

		double m_secondsUntilExit;

	};
}
