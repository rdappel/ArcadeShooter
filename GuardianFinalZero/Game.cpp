
/*                '888 88888888888 888888888',8888'
                    88 888888888888 8888888',8888'
                     8 8888             ,8',8888'
          ==̲=̲=̲=̲=̲=̲=== 8 8888 ========== ,8 ,̲8̲88̲8_==============
          /  ____/__ 8_̲88̲8̲8̲8̲88̲88̲8̲8̲8__ ,̲8__/ //_/____ _ ____
	     / /  __ / / / /ˊ __ `// ___/ˊ __  /__ ˊ __ `// __ \
	    / /__/ // /_/ // /_/ // /   / /_/ // // /_/ // / / /
	    \_____/ \__,_/ \__,_//_/    \__,_//_/ \__,_//_/ /_/
      ============== 8 8888 ===== ,8',8888' ===============
                    88 8888      ,8',8888888888888 
                   ,88 8888     ,8',888888888888888,
				   
				           ファイナル ゼロ

               Guardian FZ © 2017 - Shuriken Studios LLC          */

#include "GuardianFinalZero.h"

namespace GuardianFinalZero
{
	//PlayerCollection* Game::s_pPlayers = new PlayerCollection;

	Game::Game()
	{
		SetResourceDirectory("..\\GuardianFinalZero\\Content\\");

		Font::SetLoadSize(18, true);

		Font *pFont = GetResourceManager()->Load<Font>("Fonts\\Arialbd.ttf", false);
		SetFrameCounterFont(pFont);
	}

	void Game::LoadContent(ResourceManager* pResourceManager)
	{
		/*
		// load commonly used assets
		std::string path;
		Texture* pTexture = nullptr;

		pTexture = pResourceManager->Load<Texture>("Textures\\Projectile.png");
		ShooterLibrary::Projectile::SetTexture(pTexture);

		// default textures for single player
		PlayerShip* pShip = s_pPlayers->GetPlayerShip(0);

		path = "Textures\\GameObjects\\Ships\\Player\\Player01.png";
		pTexture = pResourceManager->Load<Texture>(path);
		pShip->SetTexture(pTexture);

		path = "Textures\\GameObjects\\Ships\\Player\\Player01Color.png";
		pTexture = pResourceManager->Load<Texture>(path);
		pShip->SetColorTexture(pTexture);
	
		/**/


		GetScreenManager()->AddScreen(new MainMenuScreen());
	}
}