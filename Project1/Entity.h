#pragma once
#include <iostream>
#include "SDL.h"
#include <vector>
#include "constant.h"


class Entity {
protected:
	std::string name;
	SDL_Texture* texture = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Rect src;
	SDL_Rect des;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	Status status = IDLE;
	Status lastStatus = IDLE;
	Velocity velocity;
	std::vector<SDL_Rect> clips;
	int speed = 5;
	int frameCount = 0;
public:
	Entity(SDL_Renderer* renderer, std::string name) {
		//SDL_Log("Entity Constructor called");
		this->renderer = renderer;
		this->name = name;
	}
	~Entity() {
		//SDL_Log("Entity Destructor called");
	}
	SDL_Point getPosition();
	virtual void init();
	virtual void render();
	void setLocation(SDL_Point point);
	void setLocation(int x, int y);
};