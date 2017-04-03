
#pragma once

namespace ShooterLibrary
{
	class EnemyShip : public Ship
	{
	public:

		EnemyShip();
		virtual ~EnemyShip() { }

		static EnemyShip *Resolve(GameObject *pGameObject1, GameObject *pGameObject2);

		virtual void Update(const GameTime *pGameTime);

		virtual void Draw(const GameTime *pGameTime) = 0;

		virtual void Initialize(const Vector2 position, const double delaySeconds);

		virtual void Fire() { }

		virtual std::string ToString() const { return "EnemyShip"; }

		virtual uint32_t GetCollisionMask() const { return ENEMY | SHIP; }


	protected:

		virtual double GetDelaySeconds() const { return m_delaySeconds; }


	private:

		double m_delaySeconds;

	};
}