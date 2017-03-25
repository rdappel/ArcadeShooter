
#pragma once

#include "MenuScreen.h"

class MainMenuScreen : public MenuScreen
{

public:

	MainMenuScreen();
	virtual ~MainMenuScreen();

	virtual void LoadContent();

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(const GameTime *pGameTime);

private:

	ALLEGRO_COLOR m_selectedColor;
	ALLEGRO_COLOR m_unselectedColor;

	float m_selectedAlpha;

	ALLEGRO_BITMAP *m_pTexture;

	Vector2 m_textureOrigin;
	Vector2 m_position;
};