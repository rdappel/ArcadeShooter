
/*   .oooooo..o       .o.       ooo        ooooo ooooooooo.   ooooo        oooooooooooo
	d8P'    `Y8      .888.      `88.       .888' `888   `Y88. `888'        `888'     `8
	Y88bo.          .8"888.      888b     d'888   888   .d88'  888          888
	 `"Y8888o.     .8' `888.     8 Y88. .P  888   888ooo88P'   888          888oooo8
		 `"Y88b   .88ooo8888.    8  `888'   888   888          888          888    "
	oo     .d8P  .8'     `888.   8    Y     888   888          888       o  888       o
	8""88888P'  o88o     o8888o o8o        o888o o888o        o888ooooood8 o888ooooood8

					        Sample © 2017 - Shuriken Studios LLC                          */

#pragma once

using ShooterLibrary::GameObject;
using ShooterLibrary::Projectile;
using ShooterLibrary::ProjectilePool;

namespace Sample
{
	class PlayerShip;
	class PowerUp;
	

	/** @brief Base class for shooter levels. */
	class Level : public ShooterLibrary::Level
	{

	public:

		Level();
		virtual ~Level() { }

		/** @brief Called when resources need to be loaded.
			@param pResourceManager The game's resource manager, used for loading
			and managing game resources. */
		virtual void LoadContent(ResourceManager *pResourceManager);

		/** @brief Adds a game object to the level.
			@param pGameObject The game object to add. */
		virtual void AddGameObject(GameObject *pGameObject);

		/** @brief Gets the player ship.
			@return Returns a pointer to the player ship. */
		virtual ShooterLibrary::PlayerShip *GetPlayerShip() { return m_pPlayerShip; }

		/** @brief Adds a power up to the level.
			@param position The position to place the power up. */
		virtual void SpawnPowerUp(const Vector2 position);


	private:

		PlayerShip *m_pPlayerShip;
		
		std::vector<PowerUp *> m_powerUps;
		std::vector<PowerUp *>::iterator m_powerUpIt;

	};
}