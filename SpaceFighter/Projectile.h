
#pragma once

#include "KatanaEngine.h"
#include "GameObject.h"

class Projectile : public GameObject
{

public:

	Projectile();
	virtual ~Projectile() { }

	static void SetTexture(Texture *pTexture) { s_pTexture = pTexture; }

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(SpriteBatch *pSpriteBatch);

	virtual void Activate(const Vector2 &position, bool wasShotByPlayer = true);

	virtual float GetDamage() const { return m_damage; }

	virtual std::string ToString() const;

	virtual CollisionType GetCollisionType() const;

	virtual bool IsDrawnByLevel() const { return m_drawnByLevel; }

	virtual void SetManualDraw(const bool drawManually = true) { m_drawnByLevel = !drawManually; }


protected:

	virtual void SetSpeed(const float speed) { m_speed = speed; }

	virtual void SetDamage(const float damage) { m_damage = damage; }

	virtual void SetDirection(const Vector2 direction) { m_direction = direction; }

	virtual float GetSpeed() const { return m_speed; }

	virtual Vector2 &GetDirection() { return m_direction; }

	virtual bool WasShotByPlayer() const { return m_wasShotByPlayer; }

	virtual CollisionType GetProjectileType() const { return CollisionType::PROJECTILE; }

	virtual std::string GetProjectileTypeString() const { return "Projectile"; }


private:

	static Texture *s_pTexture;

	float m_speed;
	float m_damage;

	Vector2 m_direction;

	bool m_wasShotByPlayer;

	bool m_drawnByLevel;
};

