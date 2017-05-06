
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

	class SaveData : public KatanaEngine::Resource
	{

	public:

		SaveData();
		virtual ~SaveData() { }

		/** @brief Load the desired animation into memory.
			@param path The path to the desired animation.
			@param pManager A pointer to the resource manager that will manage the animation.
			@return Returns true if the animation was loaded, false otherwise. */
		virtual bool Load(const std::string &path, ResourceManager *pManager);

		/** @brief Used to determine if the animation is cloneable.
			@return Returns true if the animation is clonable, false otherwise.
			@remark Animations should usually be kept as cloneable. Sharing an animation will
			result in the animations playing syncronized. */
		virtual bool IsCloneable() const { return false; }


	private:

		int m_maxLevel;

	};
}
