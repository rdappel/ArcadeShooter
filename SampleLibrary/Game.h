
#pragma once

namespace Sample
{
	class Game : public ShooterLibrary::Game
	{

	public:

		Game();
		virtual ~Game() { }

		virtual void LoadContent();

	};
}