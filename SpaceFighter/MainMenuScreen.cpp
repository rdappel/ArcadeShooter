
#include <string>
#include "MainMenuScreen.h"


MainMenuScreen::MainMenuScreen()
{
	m_pTexture = nullptr;

	SetTransitionInTime(0.5f);
	SetTransitionOutTime(0.5f);

	Show(); // Show the screen
}

void MainMenuScreen::LoadContent(ResourceManager *pResourceManager)
{
	// Logo
	m_pTexture = pResourceManager->Load<Texture>("Textures\\Logo.png");
	m_texturePosition = Game::GetScreenCenter() - Vector2::UNIT_Y * 150;

	// Create the menu items
	const int COUNT = 2;
	const int VERTICAL_SPACING = 50;
	MenuItem *pItem;
	Vector2 position = Game::GetScreenCenter() + Vector2::UNIT_Y * 160;
	Font::SetLoadSize(20, true);
	Font *pFont = pResourceManager->Load<Font>("Fonts\\Ethnocentric.ttf");

	SetDisplayCount(COUNT);
	std::string text[COUNT] = { "Start Game", "Quit" };

	for (int i = 0; i < COUNT; i++)
	{
		pItem = new MenuItem(text[i]);
		pItem->SetPosition(position + Vector2::UNIT_Y * (VERTICAL_SPACING * i));
		pItem->SetFont(pFont);
		pItem->SetColor(Color::Blue);
		pItem->SetTextAlign(TextAlign::CENTER);
		pItem->SetSelected(i == 0);
		AddMenuItem(pItem);
	}
}

void MainMenuScreen::Update(const GameTime *pGameTime)
{
	MenuItem *pItem;

	// Set the menu item colors
	for (int i = 0; i < GetDisplayCount(); i++)
	{
		pItem = GetMenuItem(i);
		pItem->SetAlpha(GetAlpha());

		if (pItem->IsSelected()) pItem->SetColor(Color::White);
		else pItem->SetColor(Color::Blue);

		std::cout << i << " is " << ((!pItem->IsSelected()) ? " not " : " ") << "selected || ";
	}

	MenuScreen::Update(pGameTime);
}

void MainMenuScreen::Draw(SpriteBatch *pSpriteBatch)
{
	pSpriteBatch->Begin();
	pSpriteBatch->Draw(m_pTexture, m_texturePosition, Color::White * GetAlpha(), m_pTexture->GetCenter());
	pSpriteBatch->End();

	MenuScreen::Draw(pSpriteBatch);
}
