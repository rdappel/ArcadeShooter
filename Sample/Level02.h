
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

	/** @brief Class for level 1. */
	class Level02 : public Level
	{

	public:


		/** @brief Instantiate the level.
			@param pGameplayScreen The gameplay screen that is controlling the level. */
		Level02(GameplayScreen *pGameplayScreen);

		virtual ~Level02() { }

		/** @brief Called when resources need to be loaded.
			@param pResourceManager The game's resource manager, used for loading
			and managing game resources. */
		virtual void LoadContent(ResourceManager *pResourceManager);

		/** @brief Gets the index of the next level.
			@return Returns the next level's index.
			@remark Returning an invalid index will exit to the main menu. */
		virtual int GetNextLevelIndex() const { return -1; }

	};
}