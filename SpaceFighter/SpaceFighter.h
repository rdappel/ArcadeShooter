
#pragma once

#include "KatanaEngine.h"
#include "SpriteBatch.h"

using namespace KatanaEngine;

class SpaceFighter : public Game
{
public:

	SpaceFighter();

	virtual ~SpaceFighter() { }

	virtual std::string GetName() const { return "SpaceFighter"; }

	virtual void Draw(SpriteBatch *pSpriteBatch);

	virtual void LoadContent(ResourceManager *pResourceManager);
};