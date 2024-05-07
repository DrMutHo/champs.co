#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "constant.h"
#include <ctime>
#include <random>

namespace Texture {
	SDL_Texture* loadImage(SDL_Renderer* renderer, std::string path);
}

namespace Global {
	extern GameState gamestate;
	extern SDL_Renderer* renderer;
	extern bool gameover;
}

namespace Rand {
	int Randint(int min, int max);
}
