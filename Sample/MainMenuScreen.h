
/*   .oooooo..o       .o.       ooo        ooooo ooooooooo.   ooooo        oooooooooooo
	d8P'    `Y8      .888.      `88.       .888' `888   `Y88. `888'        `888'     `8
	Y88bo.          .8"888.      888b     d'888   888   .d88'  888          888
	 `"Y8888o.     .8' `888.     8 Y88. .P  888   888ooo88P'   888          888oooo8
		 `"Y88b   .88ooo8888.    8  `888'   888   888          888          888    "
	oo     .d8P  .8'     `888.   8    Y     888   888          888       o  888       o
	8""88888P'  o88o     o8888o o8o        o888o o888o        o888ooooood8 o888ooooood8

					   Sample © 2017 - Shuriken Studios LLC                          */

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