
#pragma once

#include "ShooterLibrary.h"

class PlayerShip : public Ship
{
public:

	PlayerShip();
	virtual ~PlayerShip();

	virtual void SetTexture(Texture *pTexture) { m_pTexture = pTexture; }

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(const GameTime *pGameTime);

	virtual void Fire();

	virtual bool CanFireBullet() { return (m_bulletCoolDownTime <= 0); }
	virtual bool CanFireMissile() { return (m_missileCoolDownTime <= 0); }

	virtual void SetDesiredDirection(const Vector2 direction) { m_desiredDirection.Set(direction); }

	virtual std::string ToString() const { return "PlayerShip"; }

	virtual Vector2 GetHalfDimensions() const { return m_textureOrigin; }

	virtual void ToggleInvulnurability() { m_isInvulnurable = !m_isInvulnurable; }

	virtual CollisionMask GetCollisionMask() const {
		return (IsInvulnurable()) ? CollisionMask::NONE : CollisionMask::PLAYER_SHIP; 
	}


protected:


private:

	Texture *m_pTexture;
	Vector2 m_textureOrigin;

	double m_bulletCoolDownTime;
	double m_missileCoolDownTime;
	double m_maxBulletCoolDownTime;
	double m_maxMissileCoolDownTime;

	Vector2 m_desiredDirection;
	Vector2 m_velocity;

	virtual void ConfineToScreen();

//	Thruster *m_pThruster;
//	Vector2 m_thrusterOffset;

};