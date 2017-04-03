
#pragma once

namespace Sample
{
	class MainMenuScreen : public MenuScreen
	{

	public:

		MainMenuScreen();
		virtual ~MainMenuScreen() { }

		virtual void LoadContent();

		virtual void Update(const GameTime *pGameTime);

		virtual void Draw(const GameTime *pGameTime);

	private:

		Color m_selectedColor;
		Color m_unselectedColor;

		float m_selectedAlpha;

		Texture *m_pTexture;

		Vector2 m_position;
	};
}