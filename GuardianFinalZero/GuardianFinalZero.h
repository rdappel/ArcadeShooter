
#pragma once

#pragma message("Started precompiling header files for Guardian Final Zero.")

#include "ShooterLibrary.h"

#include "CollisionType.h"


/* Game Objects */
#pragma message("Game Object Headers...")
#include "PlayerShip.h"
#pragma message("                ... Finished.")
/* ----------------- */


/* Levels */
#pragma message("Level Headers...")
#include "Level.h"
#include "Level01.h"
#pragma message("                ... Finished.")
/* ----------------- */


/* Screens */
#pragma message("Screen Headers...")
#include "GameplayScreen.h"
#include "MainMenuScreen.h"
#pragma message("                ... Finished.")
/* ----------------- */


/* Core */
#pragma message("Game Object Headers...")
#include "Game.h"
#pragma message("                ... Finished.")
/* ----------------- */


#pragma message("Finished precompiling header files for Guardian Final Zero.")