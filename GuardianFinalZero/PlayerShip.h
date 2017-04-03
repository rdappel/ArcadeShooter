
#pragma once

namespace GuardianFinalZero
{
	class Level;

	class PlayerShip : public ShooterLibrary::PlayerShip
	{

	public:

		PlayerShip();
		virtual ~PlayerShip() { }

		virtual void Fire();

		virtual void Update(const GameTime *pGameTime);

		virtual void Draw(const GameTime *pGameTime);

		virtual void SetLevel(Level *pLevel) { m_pLevel = pLevel; }

		virtual bool CanFire() const { return (m_coolDownTime <= 0); }


	protected:

		virtual float GetResponsiveness() const;


	private:

		Level *m_pLevel;

		float m_coolDownTime;

	};
}