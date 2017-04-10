
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
	class Level;

	class PlayerShip : public ShooterLibrary::PlayerShip
	{

	public:

		PlayerShip();
		virtual ~PlayerShip() { }

		virtual void Update(const GameTime *pGameTime);

		virtual void Draw(const GameTime *pGameTime);

		virtual void SetLevel(Level *pLevel) { m_pLevel = pLevel; }

		virtual void SetThrusterAnimation(Animation *pAnimation) { m_pThrusterAnimation = pAnimation; }

		virtual void PowerUp() {
			if (!GetWeapon(1)->IsActive()) GetWeapon(1)->Activate();
			else GetWeapon(2)->Activate();
		}



	private:

		Level *m_pLevel;

		Animation *m_pThrusterAnimation;

	};
}