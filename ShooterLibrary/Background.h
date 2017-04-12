
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

namespace ShooterLibrary
{

	/** @brief Abstract base class for a scrolling background. */
	class Background
	{

	public:

		Background();
		virtual ~Background();

		/** @brief Called when resources need to be loaded.
			@param pResourceManager The game's resource manager, used for loading
			and managing game resources. */
		virtual void LoadContent(ResourceManager *pResourceManager) = 0;

		/** @brief Called when resources need to be unloaded. Override this method to unload
			any unneeded resources. */
		virtual void UnloadContent() { }

		/** @brief Called when the game has determined that game logic needs to be processed.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime) = 0;

		/** @brief Called when the game determines it is time to draw a frame.
			@param pSpriteBatch The game's sprite batch, used for rendering. */
		virtual void Draw(SpriteBatch *pSpriteBatch) = 0;

		/** @brief Gets the scrolling speed of the background, measured in pixels per second. */
		virtual int GetScrollSpeed() const { return 100; }

	};
}
