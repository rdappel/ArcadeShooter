
#pragma once

namespace ShooterLibrary
{
	class Game : public KatanaEngine::Game
	{

	public:

		Game();
		virtual ~Game() { }

		virtual void Draw(const GameTime *pGameTime);

	};
}