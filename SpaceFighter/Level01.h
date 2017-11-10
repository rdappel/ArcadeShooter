#pragma once

#include "Level.h"

class Level01 :	public Level
{

public:
	
	Level01() { }

	virtual ~Level01() { }

	virtual void LoadContent(ResourceManager *pResourceManager);

	virtual void UnloadContent() { }

};

