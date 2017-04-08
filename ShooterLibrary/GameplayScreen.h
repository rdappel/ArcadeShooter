
#pragma once

#include "ShooterLibrary.h"

namespace ShooterLibrary
{

	/** @brief Base class for a shooter gameplay screen. */
	class GameplayScreen : public Screen
	{

	public:

		virtual ~GameplayScreen();

		/** @brief Called when resources need to be loaded. */
		virtual void LoadContent();

		/** @brief Called when resources need to be unloaded. Override this
			method to unload any game-specific resources. */
		virtual void UnloadContent();

		/** @brief Called when the game has determined that player input
			needs to be processed.
			@param pInput The current state of all player input devices. */
		virtual void HandleInput(InputState *pInput);

		/** @brief Called when the game has determined that game logic needs
			to be processed.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime);

		/** @brief Called when the game determines it is time to draw a frame.
			@param pGameTime Timing values including time since last update. */
		virtual void Draw(const GameTime *pGameTime);

		/** @brief Set the current level to display.
			@param pLevel A pointer to the level. */
		virtual void SetLevel(Level *pLevel) { m_pLevel = pLevel; }


	protected:

		GameplayScreen();

		/** @brief Get the current level.
			@return Returns a pointer to the level. */
		virtual Level *GetLevel() { return m_pLevel; }


	private: 

		Level *m_pLevel = nullptr;

	};
}