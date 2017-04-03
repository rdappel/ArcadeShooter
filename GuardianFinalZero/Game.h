
#pragma once

#include "GuardianFinalZero.h"

namespace GuardianFinalZero
{
	class Game : public ShooterLibrary::Game
	{

	public:

		Game();
		virtual ~Game() { }

		virtual void LoadContent();

	};
}