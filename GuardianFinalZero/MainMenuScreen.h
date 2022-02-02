
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

#pragma once

namespace GuardianFinalZero
{
	class MainMenuScreen : public MenuScreen
	{

	public:

		MainMenuScreen();
		virtual ~MainMenuScreen() { }

		virtual void LoadContent(ResourceManager *pResourceManager);

		virtual void Update(const GameTime *pGameTime);

		virtual void Draw(SpriteBatch *pSpriteBatch);

	private:

		Color m_selectedColor;
		Color m_unselectedColor;

		float m_selectedAlpha = 0;

		Texture *m_pLogoTexture = nullptr;

		Vector2 m_position;
		Vector2 m_targetPosition;

		float m_menuFadeInTime = 0;
		float m_menuFadeValue = 0;
		float m_menuAlpha = 0;
	};
}