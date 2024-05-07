#pragma once
#include "wolf.h"
#include "sheep.h"
#include <string>

class EntityManager
{
private:
	std::vector<Wolf*> wolves;
	std::vector<Sheep*> sheep;
public:
	void init();
	void render();
	void handleEvents(SDL_Event e);
};

