
#include "GameplayScreen.h"
#include "Level.h"
#include "Level01.h"

GameplayScreen::GameplayScreen(const int levelIndex)
{
	m_pLevel = nullptr;
	switch (levelIndex)
	{
	case 0: m_pLevel = new Level01(); break;
	}


	SetTransitionInTime(1.0f);
	SetTransitionOutTime(0.5f);

	Show();
}

void GameplayScreen::LoadContent(ResourceManager *pResourceManager)
{
	m_pLevel->LoadContent(pResourceManager);
}

void GameplayScreen::HandleInput(const InputState *pInput)
{
	m_pLevel->HandleInput(pInput);
}

void GameplayScreen::Update(const GameTime *pGameTime)
{
	m_pLevel->Update(pGameTime);
}

void GameplayScreen::Draw(SpriteBatch *pSpriteBatch)
{
	pSpriteBatch->Begin();

	m_pLevel->Draw(pSpriteBatch);

	pSpriteBatch->End();
}
