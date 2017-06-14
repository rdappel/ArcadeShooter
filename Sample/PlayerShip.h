
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
			@param playerIndex The controlling player's index.
			@param bodyStyleIndex The body style index of the ship. */
		PlayerShip(const uint8_t playerIndex, const uint8_t bodyStyleIndex = 0);

		virtual ~PlayerShip() { }

		static const int BODY_STYLE_COUNT = 4;

		static Color GetShipColor(const uint8_t playerIndex) { return s_colors[playerIndex]; }

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
			@param pLevel The current level.
			@param startPosition The screen position where the ship will start. */
		virtual void Initialize(Level *pLevel, Vector2 &startPosition);

		/** @brief Sets the target position for the AI to move to.
			@param position The position to move to. */
		virtual void SetAITarget(Vector2 position);

		/** @brief Sets the position of the ship for display purposes.
			@param position The position to move to. */
		virtual void SetDisplayPosition(Vector2 position) { SetPosition(position); }

		/** @brief Sets the body style of the player ship.
			@param bodyStyleIndex Sets the body style index of the ship.
			@remark LoadContent must be called to reflect body style changes. */
		virtual void SetBodyStyleIndex(const uint8_t bodyStyleIndex = 0) { m_bodyStyleIndex = bodyStyleIndex; }

		/** @brief Gets the half dimensions of the game object.
			@return Returns the half dimensions of the object. */
		virtual Vector2 GetHalfDimensions() const;

		/** @brief Determines if the player ship is currently being controlled by AI.
			@return Returns true if the ship being is controlled by AI, false otherwise. */
		virtual bool IsAIControlled() const { return m_isAIControlled; }

		/** @brief Powers up the ship.
			@param powerUpType The type of power up that the ship collected. */
		virtual void PowerUp(const int powerUpType);


	private:

		static Color s_colors[4];

		Animation *m_pAnimation;
		Animation *m_pColorAnimation;

		Level *m_pLevel;

		Color m_color;

		uint8_t m_bodyStyleIndex = 0;

		float m_scale = 1.5f;

		Animation *m_pThrusterAnimation;
		Vector2 m_thrusterOffset[2][3];
		float m_thrusterScale;

		Vector2 m_targetPosition;

		bool m_isAIControlled;

	};
}