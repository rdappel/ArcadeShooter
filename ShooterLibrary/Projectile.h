
#pragma once

class Projectile
{

public:

	Projectile();
	virtual ~Projectile() { }

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(const GameTime *pGameTime);

	virtual void Activate(const Vector2 &position, bool isShotByPlayer = true);

	virtual int GetDamage() const { return m_damage; }

protected:

	float m_speed;

	Vector2 m_direction;

	int m_damage;

private:

	static ALLEGRO_BITMAP *s_pTexture;
	static Vector2 s_textureOrigin;
};

