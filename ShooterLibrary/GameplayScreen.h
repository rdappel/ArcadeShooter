
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

#pragma once

#include "ShooterLibrary.h"

namespace ShooterLibrary
{

	/** @brief Base class for a shooter gameplay screen. */
	class GameplayScreen : public Screen
	{

	public:

		virtual ~GameplayScreen();

		/** @brief Called when resources need to be loaded.
			@param pResourceManager The game's resource manager, used for loading
			and managing game resources. */
		virtual void LoadContent(ResourceManager *pResourceManager);

		/** @brief Called when resources need to be unloaded. Override this
			method to unload any game-specific resources. */
		virtual void UnloadContent();

		/** @brief Called when the game has determined that player input
			needs to be processed.
			@param pInput The current state of all player input devices. */
		virtual void HandleInput(const InputState *pInput);

		/** @brief Called when the game has determined that game logic needs
			to be processed.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime);

		/** @brief Called when the game determines it is time to draw a frame.
			@param pSpriteBatch The game's sprite batch, used for rendering. */
		virtual void Draw(SpriteBatch *pSpriteBatch);

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