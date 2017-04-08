
#pragma once

namespace ShooterLibrary
{

	/** @brief Base class for player ships. */
	class PlayerShip : public Ship
	{

	public:

		PlayerShip();
		virtual ~PlayerShip() { }

		/** @brief Resolves which game object is a player ship.
			@param pGameObject1 A pointer to the first game object to test.
			@param pGameObject2 A pointer to the second game object to test.
			@return Returns a pointer to an player ship, or a null pointer. */
		static PlayerShip *Resolve(GameObject *pGameObject1, GameObject *pGameObject2);

		/** @brief Sets the texture of the player ship.
			@param pTexture A pointer to the texture resource. */
		virtual void SetTexture(Texture *pTexture);

		/** @brief Called when the game determines it is time to draw a frame.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime);

		/** @brief Called when the game determines it is time to draw a frame.
			@param pGameTime Timing values including time since last update. */
		virtual void Draw(const GameTime *pGameTime);

		/** @brief Fires the ships weapons. */
		virtual void Fire() = 0;

		/** @brief Set the desired player direction.
			@param direction The desired direction. */
		virtual void SetDesiredDirection(const Vector2 direction) { m_desiredDirection.Set(direction); }

		/** @brief Gets a string representation of the player ship.
			@return Returns a string displaying the type of object. */
		virtual std::string ToString() const { return "PlayerShip"; }

		/** @brief Gets the half dimensions of the game object.
			@return Returns the half dimensions of the object. */
		virtual Vector2 GetHalfDimensions() const { return m_textureOrigin; }

		/** @brief Gets the collision type mask.
			@return Returns bit-mask value for the collision type.
			@see CollisionTypes
			@see CollisionManager */
		virtual uint32_t GetCollisionType() const { return (IsInvulnurable() ? NONE : (PLAYER | SHIP)); }


	protected:

		/** @brief Set the responsiveness of the player ship.
			@param responsiveness A value from zero (not responsive) to one
			(instantly responsive) that affects how the ship handles. */
		virtual void SetResponsiveness(const float responsiveness);

		/** @brief Get the responsiveness of the player ship.
			@return Returns the responsiveness value. */
		virtual float GetResponsiveness() const { return m_responsiveness; }

		/** @brief Get the desired player direction.
			@return Returns the desired direction. */
		virtual Vector2 GetDesiredDirection() const { return m_desiredDirection; }

		/** @brief Confines the player ship to the screen.
			@param padding The amount of padding around the screen. */
		virtual void ConfineToScreen(const int padding = 5);


	private:

		Texture *m_pTexture;
		Vector2 m_textureOrigin;

		Vector2 m_desiredDirection;
		Vector2 m_velocity;

		float m_responsiveness;

	};
}