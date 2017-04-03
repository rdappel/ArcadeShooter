
#pragma once

#include "ShooterLibrary.h"

namespace ShooterLibrary
{
	class GameplayScreen : public Screen
	{

	public:
		virtual ~GameplayScreen();

		virtual void LoadContent();

		virtual void HandleInput(InputState *pInput);

		virtual void Update(const GameTime *pGameTime);

		virtual void Draw(const GameTime *pGameTime);

		virtual void SetLevel(Level *pLevel) { m_pLevel = pLevel; }


	protected:

		GameplayScreen();

		Level *m_pLevel = nullptr;

	};
}