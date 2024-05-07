#pragma once
#include "Entity.h"
#include "utils.h"
#include "wolf.h"
#include "vector2D.h"

#define MAX_SHEEP_FRAME_WALK 120
#define MAX_SHEEP_FRAME_IDLE 240

class Sheep : public Entity
{
private:
	std::vector<SDL_Rect> idle_clips;
	int speed = 3;
	int speed_random = 5;

	const int WANDER_RADIUS = 50;
	const float WANDER_SPEED = 1.0f;

	float currentAngle = 0.0f;
public:
	Sheep(SDL_Renderer* renderer, std::string name) : Entity(renderer, name) {
		//SDL_Log("Sheep constructor called \n");
	}

	~Sheep() {
		//SDL_Log("Sheep destructor called \n");
	}
	static SDL_Texture* texture;
	virtual void init();
	virtual void render();
	void loadClips();
	void moveRandom();
	//bool isSafeFromWolf();
	bool trackWolf(Vector2D v);
	void moveToSafeZone(Vector2D v);
	void actions(Wolf* wolf);
	bool isCollideHorizontal(int vel);
	bool isCollideVertical(int vel);
	bool isInSafeZone();
};

