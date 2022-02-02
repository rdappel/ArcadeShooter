
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

	/** @brief Base class for explosions. */
	class Explosion
	{

	public:
		
		Explosion() { }
		virtual ~Explosion() { }
		/** @brief Called when the game has determined that game logic needs to be processed.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime);

		/** @brief Called when the game determines it is time to draw a frame.
			@param pSpriteBatch The game's sprite batch, used for rendering. */
		virtual void Draw(SpriteBatch *pSpriteBatch);

		/** @brief Sets the explosion's animation.
			@param pAnimation The animation to set. */
		virtual void SetAnimation(Animation *pAnimation) { m_pAnimation = pAnimation; }

		/** @brief Activates the explosion.
			@param position The position to place the explosion.
			@param scale The scale of the explosion.  */
		virtual void Activate(const Vector2 position, const float scale = 1);

		/** @brief Determines if the explosion is active.
			@return Returns true if the explosion is active, false otherwise. */
		virtual bool IsActive() const { return m_pAnimation->IsPlaying(); }


	protected:

		/** @brief Sets the explosion's position.
		@param position The explosion's new position. */
		virtual void SetPosition(const Vector2 position) { m_position = position; }


	private:

		Animation *m_pAnimation = nullptr;

		Vector2 m_position;

		float m_rotation = 0;
		float m_scale = 0;

	};

}