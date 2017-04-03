
#pragma once

namespace GuardianFinalZero
{
	class GameplayScreen : public ShooterLibrary::GameplayScreen
	{

	public:
		GameplayScreen(Level *pLevel);

		virtual ~GameplayScreen() { }
	};
}