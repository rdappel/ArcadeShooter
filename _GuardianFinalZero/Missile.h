
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

	/** @brief Class for missiles. */
	class Missile : public ShooterLibrary::Projectile
	{

	public:

		Missile();
		virtual ~Missile() { }

		/** @brief Sets the animation for the missile.
			@param pAnimation The animation to set for the missile. */
		virtual void SetAnimation(Animation *pAnimation) { m_pAnimation = pAnimation; }

		/** @brief Called when the game determines it is time to draw a frame.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime);

		/** @brief Called when the game determines it is time to draw a frame.
			@param pSpriteBatch The game's sprite batch, used for rendering. */
		virtual void Draw(SpriteBatch *pSpriteBatch);

		/** @brief Activates the missile.
			@param position The starting position of the missile.
			@param wasShotByPlayer Indicates if the player fired the missile. */
		virtual void Activate(const Vector2 &position, bool wasShotByPlayer = true);

		/** @brief Sets the particle emitter for particle trail.
			@param pEmitter A pointer to the emitter. */
		virtual void SetEmitter(Emitter *pEmitter) { m_pEmitter = pEmitter; }

		/** @brief Gets a string representation of the missile.
			@return Returns a string displaying the type of object. */
		virtual std::string ToString() const { return "Missile"; }


	protected:

		/** @brief Sets the turn speed of the missile.
			@param turnSpeed The degrees in radians that the missile can turn in one second. */
		void SetTurnSpeed(const float turnSpeed) { m_turnSpeed = Math::Abs(turnSpeed); }

		/** @brief Sets the  target range of the missile.
			@param range The range which the missile can seek enemy targets. */
		void SetRange(const float range) { m_range = range; }

		/** @brief Sets the current angle of the missile.
			@param angle The missiles angle in radians. */
		void SetAngle(const float angle) { m_angle = angle; }

		/** @brief Sets the missile's target.
			@param pTarget The missiles target, pass nullptr to unset the target. */
		void SetTarget(GameObject *pTarget = nullptr) { m_pTarget = pTarget; }

		/** @brief Resets the timer for when the missile should reaquire a target. */
		void ResetTargetingDelay() { m_targetingDelayFrames = Math::GetRandomInt(8, 9); }

		/** @brief Gets the missile's target object.
			@return Returns a pointer to the target object. */
		GameObject *GetTarget() const { return m_pTarget; }


	private:

		Animation *m_pAnimation;

		int m_targetingDelayFrames;

		Vector2 m_targetingOffset;

		float m_angle;
		float m_range;
		float m_turnSpeed;

		GameObject *m_pTarget;

		Emitter *m_pEmitter;

	};
}
