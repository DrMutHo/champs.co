#include "game.h"

void Game::run() {
	init();
	gameLoop();
}

void Game::init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	window = SDL_CreateWindow("Happy Sheep and Grey Wolf", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREENWIDTH, SCREENHEIGHT, SDL_WINDOW_SHOWN);
	Global::renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	interface = new Interface(Global::renderer);
	interface->init();
	entities = new EntityManager();
	entities->init();
}

void Game::gameLoop() {
	while (Global::gamestate != EXIT) {
		handleEvents();
		render();
	}
}

void Game::handleEvents() {
	SDL_PollEvent(&e);
	entities->handleEvents(e);
}

void Game::render() {
	SDL_RenderClear(Global::renderer);
	interface->render();
	entities->render();
	SDL_RenderPresent(Global::renderer);
}