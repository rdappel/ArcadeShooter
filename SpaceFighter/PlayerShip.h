
#pragma once

#include "Ship.h"


class PlayerShip : public Ship
{

public:

	PlayerShip() { }
	virtual ~PlayerShip() { }

	virtual void LoadContent(ResourceManager *pResourceManager);

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(SpriteBatch *pSpriteBatch);

	virtual void HandleInput(const InputState *pInput);

	virtual void Initialize(Level *pLevel, Vector2 &startPosition);

	virtual Vector2 GetHalfDimensions() const;

	virtual void SetDesiredDirection(const Vector2 direction) { m_desiredDirection.Set(direction); }

	virtual std::string ToString() const { return "Player Ship"; }

	virtual CollisionType GetCollisionType() const { return (CollisionType::PLAYER | CollisionType::SHIP); }

	virtual void ConfineToScreen(const bool isConfined = true) { m_isConfinedToScreen = isConfined; }


protected:

	virtual void SetResponsiveness(const float responsiveness);

	virtual float GetResponsiveness() const { return m_responsiveness; }

	virtual Vector2 GetDesiredDirection() const { return m_desiredDirection; }


private:

	Vector2 m_desiredDirection;
	Vector2 m_velocity;

	float m_responsiveness;

	bool m_isConfinedToScreen;

	Texture *m_pTexture;

};