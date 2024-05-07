#include "utils.h"

SDL_Texture* Texture::loadImage(SDL_Renderer* renderer, std::string path) {
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (surface == nullptr) SDL_Log("not found surface\n");
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == nullptr) SDL_Log(SDL_GetError(), "\n");
	SDL_FreeSurface(surface);
	return texture;
}

GameState Global::gamestate = PLAY;
SDL_Renderer* Global::renderer = nullptr;
bool Global::gameover = false;
int Global::cntSafeZone = 0;

int Rand::Randint(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(gen);
}