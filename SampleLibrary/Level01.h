#pragma once

#include "ShooterLibrary.h"
#include "SampleLevel.h"


class Level01 : public SampleLevel
{

public:
	
	Level01();
	virtual ~Level01() { }

	virtual void LoadContent();

	virtual void Update(const GameTime *pGameTime);

private:

	float m_POWERUPTEST = 1;

};

