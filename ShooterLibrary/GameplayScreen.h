
#pragma once

#include "ShooterLibrary.h"

class GameplayScreen : public Screen
{

public:

	GameplayScreen();
	virtual ~GameplayScreen();

	virtual void LoadContent();

	virtual void HandleInput(InputState *pInput);

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(const GameTime *pGameTime);
	
	virtual void SetLevel(Level *pLevel) { m_pLevel = pLevel; }


protected:

	Level *m_pLevel = nullptr;

};