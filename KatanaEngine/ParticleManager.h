
/*
     ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗ 
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
        Katana Engine \/ © 2012 - Shuriken Studios LLC
			    http://www.shurikenstudios.com
*/

#pragma once

namespace KatanaEngine
{

	/** @brief Manages the active particles in a particle system. */
	class ParticleManager
	{

	public:

		/** @brief Instantiate a particle manager object.
			@param pGame A pointer to the game instance. */
		ParticleManager(Game *pGame);
		virtual ~ParticleManager() { }

		/** @brief Called when the game has determined that screen logic needs to be processed.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime);

		/** @brief Called when the game determines it is time to draw a frame.
			@param pSpriteBatch The game's sprite batch, used for rendering. */
		virtual void Draw(SpriteBatch *pSpriteBatch);

		/** @brief Add a particle to be managed.
			@param pParticle A pointer to the particle to be managed. */
		virtual void AddParticle(Particle *pParticle) { m_particles.push_back(pParticle); }

		/** @brief Gets a pointer to the Game.
			@return A pointer to the game instance. */
		Game *GetGame() const { return m_pGame; }

		/** @brief Gets a pointer to the ResourceManager, for loading and managing resources.
			@return A pointer to the game's ResourceManager instance. */
		ResourceManager *GetResourceManager() const;


	private:

		Game *m_pGame;

		std::vector<Particle *> m_particles;
		std::vector<Particle *>::iterator m_it;

		double temp;


	};
}