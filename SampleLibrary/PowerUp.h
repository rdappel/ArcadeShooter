#pragma once
#include "ShooterLibrary.h"

class PowerUp : public GameObject
{

public:

	PowerUp();
	virtual ~PowerUp() { }

	static void SetTexture(Texture *pTexture) { s_pTexture = pTexture; }
	static void SetGlowTexture(Texture *pTexture) { s_pGlowTexture = pTexture; }

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(const GameTime *pGameTime);

	virtual void Activate(const Vector2 position);

	CollisionMask GetCollisionMask() const { return CollisionMask::POWER_UP; }


private:

	static Texture *s_pTexture;
	static Texture *s_pGlowTexture;

	Vector2 m_velocity;

};

