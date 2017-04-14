
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
	class Level;

	/** @brief Class for player ships. */
	class PlayerShip : public ShooterLibrary::PlayerShip
	{

	public:

		PlayerShip();
		virtual ~PlayerShip() { }

		/** @brief Called when the game has determined that game logic needs to be processed.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime);

		/** @brief Called when the game determines it is time to draw a frame.
			@param pSpriteBatch The game's sprite batch, used for rendering. */
		virtual void Draw(SpriteBatch *pSpriteBatch);

		/** @brief Called when the game has determined that player input needs to be processed.
			@param pInput The current state of all player input devices. */
		virtual void HandleInput(const InputState *pInput);

		/** @brief Hits the ship, dealing damage to it.
			@param damage The amount of damage to inflict. */
		virtual void Hit(const float damage);

		/** @brief Sets the current level.
			@param pLevel The current level. */
		virtual void SetLevel(Level *pLevel) { m_pLevel = pLevel; }

		/** @brief Sets the animation for the ships thruster.
			@param pAnimation The thruster animation. */
		virtual void SetThrusterAnimation(Animation *pAnimation) { m_pThrusterAnimation = pAnimation; }

		/** @brief Sets the target position for the AI to move to.
			@param position The position to move to. */
		virtual void SetAITarget(Vector2 position) 
		{
			m_isAIControlled = true;
			m_targetPosition = position;
			ConfineToScreen(false);
		}

		/** @brief Powers up the ship.
			@todo This is just a test to see that gaining a power up does something. This
			will eventually be replaced when specific power up types are created. */
		virtual void PowerUp()
		{
			if (!GetWeapon(1)->IsActive()) GetWeapon(1)->Activate();
			else
			{
				GetWeapon(2)->Activate();
				(static_cast<Launcher *>(GetWeapon(1)))->ResetCooldown();
				(static_cast<Launcher *>(GetWeapon(2)))->ResetCooldown();
			}
		}


	private:

		Level *m_pLevel;

		Animation *m_pThrusterAnimation;

		Vector2 m_targetPosition;

		bool m_isAIControlled;

	};
}