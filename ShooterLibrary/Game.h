
#pragma once

namespace ShooterLibrary
{

	/** @brief Base class for a shooter game. */
	class Game : public KatanaEngine::Game
	{

	public:

		Game();
		virtual ~Game() { }

		/** @brief Called when the game determines it is time to draw a frame.
			@param pGameTime Timing values including time since last update. */
		virtual void Draw(const GameTime *pGameTime);

	};
}