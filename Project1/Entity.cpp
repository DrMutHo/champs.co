#include "Entity.h"

void Entity::init() {
	//dino gnar
}

void Entity::render() {
	// dino gnar
}

void Entity::setLocation(SDL_Point point) {
	des.x = point.x;
	des.y = point.y;
}

void Entity::setLocation(int x, int y) {
	des.x = x;
	des.y = y;
}

SDL_Point Entity::getPosition() {
	return { des.x + des.w / 2, des.y + des.h / 2 };
}
