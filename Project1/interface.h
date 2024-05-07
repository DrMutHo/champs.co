#pragma once

#include "utils.h"
#include "constant.h"

class Interface {
private:
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;
	SDL_Rect object = { 0,0,TILE,TILE };
	SDL_Rect cage = { 5 * TILE + 20, 1 * TILE + 20, 6 * TILE - 40, 6 * TILE - 40 };
	SDL_Color color1 = { 255, 255, 255, 255 };
	SDL_Color color2 = { 0, 0, 0, 255 };
public:
	Interface(SDL_Renderer* renderer) : renderer(renderer) {
		std::cout << ".";
	}
	void drawBackground();
	void init();
	void render();
	//void handle();
};