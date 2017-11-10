
#pragma once

#include "KatanaEngine.h"
#include "CollisionType.h"

using namespace KatanaEngine;


class Level;

class GameObject
{

public:

	GameObject();
	virtual ~GameObject() { s_count--; }


	static void SetCurrentLevel(Level *pLevel) { s_pCurrentLevel = pLevel; }

	static Level *GetCurrentLevel() { return s_pCurrentLevel; }

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(SpriteBatch *pSpriteBatch) = 0;

	virtual bool IsActive() const { return m_isActive; }

	virtual void Activate() { m_isActive = true; }

	virtual void Deactivate();

	virtual Vector2 &GetPosition() { return m_position; }

	virtual Vector2 &GetPreviousPosition() { return m_previousPosition; }

	virtual std::string ToString() const = 0;

	virtual Vector2 GetHalfDimensions() const;

	virtual uint32_t GetIndex() const { return m_index; }

	virtual CollisionType GetCollisionType() const = 0;

	virtual float GetCollisionRadius() const { return m_collisionRadius; }

	virtual void Hit(const float damage) { }

	virtual bool HasMask(CollisionType mask) const { return mask.Contains(GetCollisionType()); }

	virtual bool IsMask(CollisionType mask) const { return (GetCollisionType() == mask); }

	virtual bool IsDrawnByLevel() const { return true; }


protected:

	virtual void SetCollisionRadius(const int radius) { m_collisionRadius = radius; }

	virtual void SetPosition(const float x, const float y);

	virtual void SetPosition(const Vector2 &position);

	virtual void TranslatePosition(const float x, const float y);

	virtual void TranslatePosition(const Vector2 &offset);

	virtual bool IsOnScreen() const;


private:
	
	static Level *s_pCurrentLevel;
	static uint32_t s_count;

	uint32_t m_index;

	bool m_isActive;

	Vector2 m_position;
	Vector2 m_previousPosition;

	float m_collisionRadius;
};

