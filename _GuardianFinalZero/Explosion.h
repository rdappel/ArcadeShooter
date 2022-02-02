
/*                '888 88888888888 888888888',8888'
					88 888888888888 8888888',8888'
					 8 8888             ,8',8888'
		  ==̲=̲=̲=̲=̲=̲=== 8 8888 ========== ,8 ,̲8̲88̲8_==============
		  /  ____/__ 8_̲88̲8̲8̲8̲88̲88̲8̲8̲8__ ,̲8__/ //_/____ _ ____
		 / /  __ / / / /ˊ __ `// ___/ˊ __  /__ ˊ __ `// __ \
		/ /__/ // /_/ // /_/ // /   / /_/ // // /_/ // / / /
		\_____/ \__,_/ \__,_//_/    \__,_//_/ \__,_//_/ /_/
	  ============== 8 8888 ===== ,8',8888' ===============
					88 8888      ,8',8888888888888
				   ,88 8888     ,8',888888888888888,

						   ファイナル ゼロ

			   Guardian FZ © 2017 - Shuriken Studios LLC          */

#pragma once

namespace GuardianFinalZero
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