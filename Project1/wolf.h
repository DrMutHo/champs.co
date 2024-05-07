#pragma once
#include "Entity.h"
#include "utils.h"
#include "vector2D.h"
class Wolf : public Entity
{
private:
	Orient orient;
public:
	Wolf(SDL_Renderer* renderer, std::string name) : Entity(renderer, name) {
		SDL_Log("Wolf constructor called \n");
	}

	~Wolf() {
		SDL_Log("Wolf destructor called \n");
	}
	static SDL_Texture* texture;
	void handleUserEvents(SDL_Event e);
	virtual void init();
	virtual void render();
	void loadClips();
	void action();
};

