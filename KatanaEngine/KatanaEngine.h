
#pragma once

#pragma message("")
#pragma message("")
#pragma message("         ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗ ")
#pragma message("         ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗")
#pragma message("         █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║")
#pragma message("         ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║")
#pragma message("         ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║")
#pragma message("         ╚═╝  ╚═╝ ╚═╝  ╚═╝/\\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝")
#pragma message("       /vvvvvvvvvvvvvvvvvvv \\=======================================,")
#pragma message("       `^^^^^^^^^^^^^^^^^^^ /-------------------------------------\"")
#pragma message("            Katana Engine \\/ © 2012 - Shuriken Studios LLC")
#pragma message("                    http://www.shurikenstudios.com")
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


/* Allegro Specific */
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>


/* Math Specific */
#include "MathUtil.h"
#include "Point.h"
#include "Vector2.h"
#include "GameTime.h"
#include "Region.h"
#include "Color.h"


/* Input Specific */
#include "KeyState.h"
#include "GamepadState.h"
#include "MouseState.h"
#include "InputState.h"


/* Resource Management */
#include "Resource.h"
#include "Font.h"
#include "Texture.h"
#include "Animation.h"
#include "ResourceManager.h"


/* Graphics Management */
#include "RenderTarget.h"
#include "SpriteBatch.h"


/* Particle Management */
#include "Particle.h"
#include "RotatingParticle.h"
#include "Emitter.h"
#include "ParticleTemplate.h"
#include "ParticleManager.h"


/* Screen Management */
#include "MenuItem.h"
#include "Screen.h"
#include "MenuScreen.h"
#include "ScreenManager.h"


/* Game Engine */
#include "GameTime.h"
#include "Game.h"
