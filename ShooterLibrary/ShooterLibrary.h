
#pragma once

#pragma message("Started precompiling header files for Shooter Library.")

#include "KatanaEngine.h"

/* Game Objects */
#pragma message("Game Object Headers...")
#include "GameObject.h"
#include "Projectile.h"
#include "Ship.h"
#include "PlayerShip.h"
#include "EnemyShip.h"
#pragma message("                ... Finished.")
/* ----------------- */

/* Core */
#pragma message("Core Headers...")
#include "Game.h"
#pragma message("                ... Finished.")
/* ----------------- */


/* Screens */
#pragma message("Screen Headers...")
#include "GameplayScreen.h"
#pragma message("                ... Finished.")
/* ----------------- */


/* Levels */
#pragma message("Level Headers...")
#include "Level.h"
#pragma message("                ... Finished.")
/* ----------------- */


#pragma message("Finished precompiling header files for Shooter Library.")