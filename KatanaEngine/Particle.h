#pragma once

class ParticleTemplate;

class Particle
{
public:

	Particle();
	virtual ~Particle() { }

	virtual void Activate() { m_lifeSeconds = m_lifespan; }

	virtual bool IsActive() const { return m_lifeSeconds > 0; }

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(const GameTime *pGameTime);

	virtual float GetInterpolationValue();

	virtual void SetLifespan(const float lifespan) { m_lifespan = lifespan; }

	virtual void SetTemplate(ParticleTemplate *pTemplate) { m_pTemplate = pTemplate; }


	virtual void SetPosition(const Vector2 position) { m_position = position; }
	virtual Vector2 &GetPosition() { return m_position; }

	virtual void SetAlpha(const float alpha) { m_alpha = alpha; }
	virtual float GetAlpha() const { return m_alpha; }

	virtual void SetScale(const float scale) { m_scale = scale; }
	virtual float GetScale() const { return m_scale; }

	virtual void SetRotation(const float rotation) { m_rotation = rotation; }
	virtual float GetRotation() const { return m_rotation; }

protected:

	float m_lifespan;
	float m_lifeSeconds;

	Vector2 m_position;
	Color m_color;

	float m_alpha;
	float m_scale;
	float m_rotation;


	ParticleTemplate *m_pTemplate;
};

