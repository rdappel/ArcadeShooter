
#pragma once

namespace Sample
{
	class Level;

	class PlayerShip : public ShooterLibrary::PlayerShip
	{

	public:

		PlayerShip();
		virtual ~PlayerShip() { }

		static PlayerShip *Resolve(GameObject *pGameObject1, GameObject *pGameObject2);

		virtual void Fire();

		virtual void Update(const GameTime *pGameTime);

		virtual void Draw(const GameTime *pGameTime);

		virtual void SetLevel(Level *pLevel) { m_pLevel = pLevel; }

		virtual void SetThrusterAnimation(Animation *pAnimation) { m_pThrusterAnimation = pAnimation; }

		virtual bool CanFire() const { return (m_coolDownTime <= 0); }

	protected:

		//virtual float GetSpeed() const { return PlayerShip::GetSpeed(); }

		virtual float GetResponsiveness() const;


	private:

		Level *m_pLevel;

		Animation *m_pThrusterAnimation;

		float m_coolDownTime;

	};
}