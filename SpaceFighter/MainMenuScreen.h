#pragma once

#include "KatanaEngine.h"

using namespace KatanaEngine;

class MainMenuScreen : public MenuScreen
{

public:

	MainMenuScreen();

	virtual ~MainMenuScreen() { }

	virtual void LoadContent(ResourceManager *pResourceManager);
	
	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(SpriteBatch *pSpriteBatch);


	virtual void SetQuitFlag() { m_isQuittingGame = true; }

	virtual bool IsQuittingGame() { return m_isQuittingGame; }


private:
	
	Texture *m_pTexture;

	Vector2 m_texturePosition;

	bool m_isQuittingGame = false;

};