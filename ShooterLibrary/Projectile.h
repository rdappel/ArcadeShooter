
#pragma once

namespace ShooterLibrary
{
	class Projectile : public GameObject
	{

	public:

		Projectile();
		virtual ~Projectile() { }

		static Projectile *Resolve(GameObject *pGameObject1, GameObject *pGameObject2);

		static void SetTexture(Texture *pTexture);

		virtual void Update(const GameTime *pGameTime);

		virtual void Draw(const GameTime *pGameTime);

		virtual void Activate(const Vector2 &position, bool isShotByPlayer = true);

		virtual float GetDamage() const { return m_damage; }

		virtual std::string ToString() const;

		virtual uint32_t GetCollisionMask() const;


	protected:

		virtual void SetSpeed(const float speed) { m_speed = speed; }

		virtual float GetSpeed() const { return m_speed; }


	private:

		static Texture *s_pTexture;
		static Vector2 s_textureOrigin;

		float m_speed;

		Vector2 m_direction;

		bool m_isShotByPlayer;

		float m_damage;
	};
}