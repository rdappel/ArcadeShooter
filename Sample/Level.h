
#pragma once

using ShooterLibrary::GameObject;
using ShooterLibrary::Projectile;

namespace Sample
{
	class PlayerShip;
	class PowerUp;

	class Level : public ShooterLibrary::Level
	{

	public:

		Level();
		virtual ~Level() { }

		virtual void LoadContent();

		virtual void AddGameObject(GameObject *pGameObject);

		virtual ShooterLibrary::PlayerShip *GetPlayerShip() { return m_pPlayerShip; }

		virtual Projectile *GetInactiveProjectile();

		virtual void GeneratePowerUp(const Vector2 position);


	private:

		PlayerShip *m_pPlayerShip;

		std::vector<Projectile *> m_projectiles;
		std::vector<Projectile *>::iterator m_projectileIt;

		std::vector<PowerUp *> m_powerUps;
		std::vector<PowerUp *>::iterator m_powerUpIt;

	};
}