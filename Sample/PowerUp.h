
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

	/** @brief Class for power ups. */
	class PowerUp : public ShooterLibrary::GameObject
	{

	public:

		PowerUp();
		virtual ~PowerUp() { }

		/** @brief Sets the texture of the power up.
			@param pTexture A pointer to the texture resource. */
		static void SetTexture(Texture *pTexture) { s_pTexture = pTexture; }

		/** @brief Sets the glow texture of the power up.
			@param pTexture A pointer to the texture resource. */
		static void SetGlowTexture(Texture *pTexture) { s_pGlowTexture = pTexture; }

		/** @brief Sets the color texture of the power up.
			@param pTexture A pointer to the texture resource. */
		static void SetColorTexture(Texture *pTexture) { s_pColorTexture = pTexture; }

		/** @brief Called when the game has determined that game logic needs
			to be processed.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime);

		/** @brief Called when the game determines it is time to draw a frame.
			@param pSpriteBatch The game's sprite batch, used for rendering. */
		virtual void Draw(SpriteBatch *pSpriteBatch);

		/** @brief Activates the power up.
			@param position The position to place the power up.
			@param pLevel The level that contains the power up. */
		virtual void Activate(const Vector2 position, Level *pLevel);

		/** @brief Gets the collision type mask.
			@return Returns bit-mask value for the collision type.
			@see CollisionTypes
			@see CollisionManager */
		virtual ShooterLibrary::CollisionType GetCollisionType() const { return CollisionType::POWERUP; }

		/** @brief Gets a string representation of the power up.
			@return Returns a string displaying the type of object. */
		virtual std::string ToString() const { return "Power Up"; }


	private:

		static Texture *s_pTexture;
		static Texture *s_pGlowTexture;
		static Texture *s_pColorTexture;

		Vector2 m_velocity;

		PlayerShip *m_pTarget;
		int m_pMagnetDistance;

		Level *m_pLevel;

		int m_targetCheck;

		float m_alpha;

	};
}