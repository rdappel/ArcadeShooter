
#pragma once

class PlayerShip : public Ship
{
public:

	PlayerShip();
	virtual ~PlayerShip() { }

	virtual void SetTexture(Texture *pTexture);

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(const GameTime *pGameTime);

	virtual void Fire() = 0;

	//virtual bool CanFireBullet() { return (m_bulletCoolDownTime <= 0); }

	virtual void SetDesiredDirection(const Vector2 direction) { m_desiredDirection.Set(direction); }

	virtual std::string ToString() const { return "PlayerShip"; }

	virtual Vector2 GetHalfDimensions() const { return m_textureOrigin; }

	virtual CollisionMask GetCollisionMask() const {
		return (IsInvulnurable()) ? CollisionMask::NONE : CollisionMask::PLAYER_SHIP; 
	}


protected:


private:

	Texture *m_pTexture;
	Vector2 m_textureOrigin;

	Vector2 m_desiredDirection;
	Vector2 m_velocity;

	virtual void ConfineToScreen();

};