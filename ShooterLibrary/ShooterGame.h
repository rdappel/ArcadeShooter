#pragma once

class ShooterGame : public Game
{

public:

	ShooterGame();
	virtual ~ShooterGame() { }


	virtual void Draw(const GameTime *pGameTime);

};

