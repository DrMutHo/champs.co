#include "interface.h"

void Interface::drawBackground() {
	for (int y = 0; y < hb; y++) {
		object.y = y * TILE;
		for (int x = 0; x < wb; x++) {
			object.x = x * TILE;
			//std::cout << object.x << " " << object.y << " " << object.w << " " << object.h << std::endl;
			if ((x + y) % 2 == 0) {
				//std::cout << 100;
				SDL_SetRenderDrawColor(renderer, 0, 127, 19, 255);
				SDL_RenderFillRect(renderer, &object);
			}
			else {
				//std::cout << 99;
				SDL_SetRenderDrawColor(renderer, 0, 101, 15, 255);
				SDL_RenderFillRect(renderer, &object);
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 130, 19, 255);
		SDL_RenderFillRect(renderer, &cage);
	}
	
}

void Interface::render() {
	//std::cout << "render" << std::endl;
	drawBackground();
}

void Interface::init() {
	std::cout << "init";
}

