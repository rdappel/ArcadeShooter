
#pragma once

#include "KatanaEngine.h"

using namespace KatanaEngine;

class Level;

class GameplayScreen : public Screen
{

public:

	GameplayScreen(const int levelIndex = 0);

	virtual ~GameplayScreen() { }

	virtual void LoadContent(ResourceManager *pResourceManager);

	virtual void HandleInput(const InputState *pInput);

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(SpriteBatch *pSpriteBatch);


private:

	Level *m_pLevel;


};
