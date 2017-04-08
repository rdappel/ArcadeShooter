
#pragma once

#include "GuardianFinalZero.h"

namespace GuardianFinalZero
{
	class Game : public ShooterLibrary::Game
	{

	public:

		Game();
		virtual ~Game() { }

		virtual std::string GetName() const { return "Guardian FZ"; }

		virtual void LoadContent();

	};
}