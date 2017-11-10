
#pragma once

#include "EnemyShip.h"

class BioEnemyShip : public EnemyShip
{

public:

	BioEnemyShip();
	virtual ~BioEnemyShip() { }

	void SetTexture(Texture *pTexture) { m_pTexture = pTexture; }

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(SpriteBatch *pSpriteBatch);


private:

	Texture *m_pTexture;

};