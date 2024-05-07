#pragma once
#include "utils.h"
#include "constant.h"
#include "interface.h"

#include "EntityManager.h"
class Game
{
private:
	Interface* interface = nullptr;
	SDL_Window* window = nullptr;
	SDL_Event e;
	EntityManager* entities = nullptr;

public:
	Game() {
		std::cout << ".";
	}
	~Game() {
		std::cout << ".";
	}

	void init();
	void run();
	void gameLoop();
	void render();
	void handleEvents();

};

