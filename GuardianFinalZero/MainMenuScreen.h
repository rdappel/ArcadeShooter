
#pragma once

namespace GuardianFinalZero
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

		Texture *m_pLogoTexture;

		Vector2 m_position;
		Vector2 m_targetPosition;
	};
}