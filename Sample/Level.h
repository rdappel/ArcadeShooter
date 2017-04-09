
#pragma once

using ShooterLibrary::GameObject;
using ShooterLibrary::Projectile;
using ShooterLibrary::ProjectilePool;

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

		virtual void SpawnPowerUp(const Vector2 position);


	private:

		PlayerShip *m_pPlayerShip;
		
		std::vector<PowerUp *> m_powerUps;
		std::vector<PowerUp *>::iterator m_powerUpIt;

		std::vector<ProjectilePool *> m_pProjectilePools;

	};
}