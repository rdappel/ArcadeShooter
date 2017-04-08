
#pragma once

namespace Sample
{
	class Game : public ShooterLibrary::Game
	{

	public:

		Game();
		virtual ~Game() { }

		virtual std::string GetName() const { return "Sample Game"; }

		virtual void LoadContent();

	};
}