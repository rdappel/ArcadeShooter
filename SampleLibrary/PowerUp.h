
#pragma once

namespace Sample
{
	class PowerUp : public ShooterLibrary::GameObject
	{

	public:

		PowerUp();
		virtual ~PowerUp() { }

		static void SetTexture(Texture *pTexture) { s_pTexture = pTexture; }
		static void SetGlowTexture(Texture *pTexture) { s_pGlowTexture = pTexture; }

		static PowerUp *Resolve(GameObject *pGameObject1, GameObject *pGameObject2);

		virtual void Update(const GameTime *pGameTime);

		virtual void Draw(const GameTime *pGameTime);

		virtual void Activate(const Vector2 position);

		virtual uint32_t GetCollisionMask() const { return POWER_UP; }

		virtual std::string ToString() const { return "Power Up"; }


	private:

		static Texture *s_pTexture;
		static Texture *s_pGlowTexture;

		Vector2 m_velocity;

	};
}