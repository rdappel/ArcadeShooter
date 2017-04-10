
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

	class Missile : public ShooterLibrary::Projectile
	{

	public:

		Missile();
		virtual ~Missile() { }

		virtual void SetAnimation(Animation *pAnimation) { m_pAnimation = pAnimation; }

		/** @brief Called when the game determines it is time to draw a frame.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime);

		/** @brief Called when the game determines it is time to draw a frame.
			@param pGameTime Timing values including time since last update. */
		virtual void Draw(const GameTime *pGameTime);

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

		void SetTurnSpeed(const float turnSpeed) { m_turnSpeed = Math::Abs(turnSpeed); }

		void SetRange(const float range) { m_range = range; }

		void SetAngle(const float angle) { m_angle = angle; }

		void SetTarget(GameObject *pTarget = nullptr) { m_pTarget = pTarget; }

		void ResetTargetingDelay() { m_targetingDelayFrames = Math::GetRandomInt(8, 9); }

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
