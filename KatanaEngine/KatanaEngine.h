
#pragma once

#pragma message("Started precompiling header files for Katana Engine.")


/* Standard Headers */
#pragma message("Standard Headers...")
#include <stdlib.h>
#include <malloc.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#pragma message("                ... Finished.")
/* ---------------- */


/* Allegro Specific */
#pragma message("Allegro Specific Headers...")
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#pragma message("                ... Finished.")
/* ---------------- */


/* Math Specific */
#pragma message("Math Specific Headers...")
#include "MathUtil.h"
#include "Point.h"
#include "Vector2.h"
#include "GameTime.h"
#include "Region.h"
#include "Color.h"
#pragma message("                ... Finished.")
/* ------------- */


/* Input Specific */
#pragma message("Input Specific Headers...")
#include "ButtonState.h"
#include "GamepadState.h"
#include "MouseState.h"
#include "InputState.h"
#pragma message("                ... Finished.")
/* -------------- */


/* Resource Management */
#pragma message("Resource Management Headers...")
#include "Resource.h"
#include "Font.h"
#include "Texture.h"
#include "Animation.h"
#include "ResourceManager.h"
#pragma message("                ... Finished.")
/* ------------------- */


/* Graphics Management */
#pragma message("Graphics Management Headers...")
#include "RenderTarget.h"
#include "SpriteBatch.h"
#pragma message("                ... Finished.")
/* ------------------- */


/* Particle Management *
#pragma message("Particle Management Headers...")
#include "Particle.h"
#include "Emitter.h"
#include "ParticleManager.h"
#pragma message("                ... Finished.")
/* ------------------- */


/* Screen Management */
#pragma message("Screen Management Headers...")
#include "MenuItem.h"
#include "Screen.h"
#include "MenuScreen.h"
#include "ScreenManager.h"
#pragma message("                ... Finished.")
/* ----------------- */


/* Game Engine */
#pragma message("Game Engine Headers...")
#include "GameTime.h"
#include "Game.h"
#pragma message("                ... Finished.")
/* ----------- */


#pragma message("Finished precompiling header files for Katana Engine.")