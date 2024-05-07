#include "EntityManager.h"

void EntityManager::init() {
	Wolf::texture = Texture::loadImage(Global::renderer, "./Project1/resources/object/dog.png");
	for (int i = 0; i < 1; i++) {
		Wolf* wolf = new Wolf(Global::renderer, "wolf");
		wolf->init();
		wolves.push_back(wolf);
	}
	Sheep::texture = Texture::loadImage(Global::renderer, "./Project1/resources/object/shep.png");
	for (int i = 0; i < 4; i++) {
		Sheep* shep = new Sheep(Global::renderer, ("sheep" + std::to_string(i + 1)));
		shep->init();
		sheep.push_back(shep);
	}
}

void EntityManager::render() {
	for (const auto& wolf : wolves) wolf->render();
	for (const auto& shep : sheep) shep->render();
}

void EntityManager::handleEvents(SDL_Event e) {
	for (const auto& wolf : wolves) wolf->handleUserEvents(e);
	for (const auto& shep : sheep) { 
		shep->actions(wolves[0]); 
		shep->randomAction();
	}
}

