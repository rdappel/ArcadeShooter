
#pragma once

#pragma message("")
#pragma message("  ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗")
#pragma message("  ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗")
#pragma message("  █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║")
#pragma message("  ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║")
#pragma message("  ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║")
#pragma message("  ╚═╝  ╚═╝ ╚═╝  ╚═╝/\\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝")
#pragma message("/vvvvvvvvvvvvvvvvvvv \\=========================================,")
#pragma message("`^^^^^^^^^^^^^^^^^^^ /---------------------------------------\"")
#pragma message("     Katana Engine \\/ © 2012 - Shuriken Studios LLC")
#pragma message("")


/* Standard Headers */
#include <stdlib.h>
#include <malloc.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <map>
#pragma message("Standard Headers... Finished.")


/* Allegro Specific */
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#pragma message("Allegro Specific Headers... Finished.")


/* Math Specific */
#include "MathUtil.h"
#include "Point.h"
#include "Vector2.h"
#include "GameTime.h"
#include "Region.h"
#include "Color.h"
#pragma message("Math Specific Headers... Finished.")


/* Input Specific */
#include "KeyState.h"
#include "GamepadState.h"
#include "MouseState.h"
#include "InputState.h"
#pragma message("Input Specific Headers... Finished.")


/* Resource Management */
#include "Resource.h"
#include "Font.h"
#include "Texture.h"
#include "Animation.h"
#include "ResourceManager.h"
#pragma message("Resource Management Headers... Finished.")


/* Graphics Management */
#include "RenderTarget.h"
#include "SpriteBatch.h"
#pragma message("Graphics Management Headers... Finished.")


/* Particle Management */
#include "Particle.h"
#include "ParticleTemplate.h"
#include "ParticleManager.h"
#include "Emitter.h"
#pragma message("Particle Management Headers... Finished.")


/* Screen Management */
#include "MenuItem.h"
#include "Screen.h"
#include "MenuScreen.h"
#include "ScreenManager.h"
#pragma message("Screen Management Headers... Finished.")


/* Game Engine */
#include "GameTime.h"
#include "Game.h"
#pragma message("Game Engine Headers... Finished.")

#pragma message("Finished precompiling header files for Katana Engine.")
#pragma message("")
