
#pragma once

namespace Sample
{

	class Missile : public ShooterLibrary::Projectile
	{

	public:

		Missile();
		virtual ~Missile() { }

		/** @brief Sets the texture of the player ship.
			@param pTexture A pointer to the texture resource. */
		static void SetTexture(Texture *pTexture) { s_pTexture = pTexture; }

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

		void SetSpeed(const float speed) { m_speed = speed; }

		void SetRange(const float range) { m_range = range; }

		void SetAngle(const float angle) { m_angle = angle; }

		void SetTarget(GameObject *pTarget = nullptr) { m_pTarget = pTarget; }

		void SetTargetingDelay(const float delaySeconds) { m_targetingDelaySeconds = delaySeconds; }

		GameObject *GetTarget() const { return m_pTarget; }


	private:

		static Texture *s_pTexture;

		Animation *m_pAnimation;

		float m_targetingDelaySeconds;
		float m_currentTargetingDelay;

		Vector2 m_targetingOffset;

		Vector2 m_direction;

		float m_speed;
		float m_angle;
		float m_range;
		float m_turnSpeed;

		GameObject *m_pTarget;

		Emitter *m_pEmitter;

	};
}
