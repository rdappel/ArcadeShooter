/* ------------------------------------------------

Space Fighter Game

Ryan Appel
10/2/14


MainMenuScreen.cpp: Source file for game's main
menu.

------------------------------------------------- */


#include "ShooterLibrary.h"


// Removal Function
void MainMenuScreenRemove(Screen *pScreen)
{
	pScreen->GetScreenManager()->AddScreen(new GameplayScreen());
}

// Menu Item Functions
void StartSelect(MenuScreen *pMenuScreen)
{
	pMenuScreen->OnRemove = MainMenuScreenRemove;
	pMenuScreen->Exit();
}

void ExitSelect(MenuScreen *pMenuScreen)
{
	pMenuScreen->Exit();
	pMenuScreen->GetScreenManager()->GetGame()->Quit();
}

MainMenuScreen::MainMenuScreen()
{
	// Setup the menu items
	m_selectedColor = al_map_rgb(0, 100, 255);
	m_unselectedColor = al_map_rgb(255, 255, 255);
	SetItemListWrapping(false);

	m_pTexture = nullptr;

	SetTransitionInTime(1.0);
	SetTransitionOutTime(0.5);

	const int MENU_ITEM_COUNT = 2;
	std::string items[MENU_ITEM_COUNT] = { "Start", /*"Options", */"Quit" };
	SetDisplayCount(MENU_ITEM_COUNT);

	int x = Game::GetScreenWidth() / 2;

	for (int i = 0; i < MENU_ITEM_COUNT; i++)
	{
		MenuItem *pMenuItem = new MenuItem;
		
		//pMenuItem->SetFont(GetResourceManager()->Load<Font>("Fonts\\arial.ttf"));
		pMenuItem->SetText(items[i]);
		pMenuItem->SetTextAlign(TextAlign::ALIGN_CENTER);
		pMenuItem->SetPosition(Vector2(x, 460 + (40 * i)));

		AddMenuItem(pMenuItem);
	}

	GetMenuItem(0)->OnSelect = StartSelect;
	//m_menuItems[1]->OnSelect = nullptr;
	GetMenuItem(1)->OnSelect = ExitSelect;

	
	//SetUseRenderTarget();
	Show();
}


MainMenuScreen::~MainMenuScreen()
{
}


void MainMenuScreen::LoadContent()
{
	/**
	// Setup for the game logo
	ALLEGRO_BITMAP *pTemp = nullptr;

	std::string path = Game::GetContentDirectory();
	path.append("Textures\\Logo.png");

	pTemp = al_load_bitmap(path.c_str());
	if (pTemp)
	{
		m_pTexture = pTemp;
		m_textureOrigin.X = al_get_bitmap_width(m_pTexture) / 2;
		m_textureOrigin.Y = al_get_bitmap_height(m_pTexture) / 2;

		float x = Game::GetScreenWidth() / 2;
		m_position.Set(x, m_textureOrigin.Y + 50);
	}
	/**/

	Screen::LoadContent();
}

void MainMenuScreen::Update(const GameTime *pGameTime)
{
	// Calculations to make the selected menu item pulse
	float sinValue = (float)((1.0f + sin(pGameTime->GetTotalTime() * 6)) * 0.5);
	m_selectedAlpha = 0.5f + 0.5f * sinValue;

	// Set the menu item colors
	for (int i = 0; i < GetDisplayCount(); i++)
	{
		//bool isSelected = (i == m_selectedItemIndex);

		//m_menuItems[i]->SetSelected(isSelected);
		//m_menuItems[i]->SetColor(isSelected ? m_selectedColor : m_unselectedColor);
		//m_menuItems[i]->SetAlpha(isSelected ? m_selectedAlpha : 1.0f);
		//m_menuItems[i]->Update(pGameTime);

	}
}

void MainMenuScreen::Draw(const GameTime *pGameTime)
{
	if (m_pTexture)
	{
		int x = (int)(m_position.X - m_textureOrigin.X);
		int y = (int)(m_position.Y - m_textureOrigin.Y);

		al_draw_bitmap(m_pTexture, x, y, 0);
	}

	MenuScreen::Draw(pGameTime);
}
