
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
	class GameplayScreen : public KatanaEngine::Screen
	{

	public:
		
		GameplayScreen(const uint8_t levelToLoad = 0);
		virtual ~GameplayScreen();

		virtual void LoadContent(ResourceManager *pResourceManager);

		virtual void HandleInput(const InputState *pInput);

		virtual void Update(const GameTime *pGameTime);

		virtual void Draw(SpriteBatch *pSpriteBatch);

		virtual int GetNextLevelIndex() const;

	protected:

		virtual Level *GetLevel() { return m_pLevel; }


	private:

		Level *m_pLevel = nullptr;
		
		ResourceManager *m_pResourceManager = nullptr;

		PlayerCollection m_players;

	};
}