
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

		/** @brief Instantiate a player ship object.
			@param playerIndex The controlling player's index. */
		PlayerShip(const uint8_t playerIndex);

		virtual ~PlayerShip() { }

		/** @brief Called when resources need to be loaded.
			@param pResourceManager The game's resource manager, used for loading
			and managing game resources. */
		virtual void LoadContent(ResourceManager *pResourceManager);

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

		/** @brief Initializes the player ship at the start of the level.
			@param pLevel The current level. */
		virtual void Initialize(Level *pLevel);

		/** @brief Sets the target position for the AI to move to.
			@param position The position to move to. */
		virtual void SetAITarget(Vector2 position)
		{
			m_isAIControlled = true;
			m_targetPosition = position;
			ConfineToScreen(false);
		}

		/** @brief Gets the half dimensions of the game object.
			@return Returns the half dimensions of the object. */
		virtual Vector2 GetHalfDimensions() const;

		/** @brief Determines if the player ship is currently being controlled by AI.
			@return Returns true if the ship being is controlled by AI, false otherwise. */
		virtual bool IsAIControlled() const { return m_isAIControlled; }

		/** @brief Powers up the ship.
			@todo This is just a test to see that gaining a power up does something. This
			will eventually be replaced when specific power up types are created. */
		virtual void PowerUp()
		{
			if (!GetWeapon(1)->IsActive()) GetWeapon(1)->Activate();
			else
			{
				GetWeapon(2)->Activate();
				((Launcher *)GetWeapon(1))->ResetCooldown();
				((Launcher *)GetWeapon(2))->ResetCooldown();
			}
		}


	private:

		Animation *m_pAnimation;
		Animation *m_pColorAnimation;

		Level *m_pLevel;

		Color m_color;

		float m_scale = 1.5f;

		Animation *m_pThrusterAnimation;
		Vector2 m_thrusterOffset[2];
		float m_thrusterScale;

		Vector2 m_targetPosition;

		bool m_isAIControlled;

	};
}