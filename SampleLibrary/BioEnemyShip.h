#pragma once

#include "ShooterLibrary.h"

class BioEnemyShip : public EnemyShip
{

public:

	BioEnemyShip();
	virtual ~BioEnemyShip() { }

	static void SetTexture(Texture *pTexture) { s_pTexture = pTexture; }

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(const GameTime *pGameTime);


private:

	static Texture *s_pTexture;

};

