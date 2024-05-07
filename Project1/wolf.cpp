#include "wolf.h"

#define MAX_WOLF_FRAME_WALK 30


//SDL_Texture* Wolf::texture = Texture::loadImage(Global::renderer, "resources/object/dog.png");
SDL_Texture* Wolf::texture = nullptr;
void Wolf::handleUserEvents(SDL_Event e) {
	if (!Global::gameover) {
		action();
		if (e.type == SDL_KEYDOWN) {
			switch (e.key.keysym.sym) {
			case SDLK_a:
			case SDLK_LEFT:
				if (orient.right == 1) return;
				status = WALK;
				orient.left = 1;
				velocity.dx = -speed;
				flip = SDL_FLIP_HORIZONTAL;
				break;
			case SDLK_s:
			case SDLK_DOWN:
				if (orient.up == 1) return;
				orient.down = 1;
				velocity.dy = speed;
				status = WALK;
				break;
			case SDLK_d:
			case SDLK_RIGHT:
				if (orient.left == 1) return;
				flip = SDL_FLIP_NONE;
				orient.right = 1;
				velocity.dx = speed;
				status = WALK;
				break;
			case SDLK_w:
			case SDLK_UP:
				if (orient.down == 1) return;
				orient.up = 1;
				velocity.dy = -speed;
				status = WALK;
				break;
			}
		}
		if (e.type == SDL_KEYUP) {
			switch (e.key.keysym.sym) {
			case SDLK_a:
			case SDLK_LEFT:
				if (orient.left == 1) {
					//status = IDLE;
					orient.left = 0;
					velocity.dx += speed;
					//velocity.dx = 0;
				}
				break;
			case SDLK_s:
			case SDLK_DOWN:
				if (orient.down == 1) {
					//status = IDLE;
					orient.down = 0;
					velocity.dy -= speed;
					//velocity.dy = 0;

				}
				break;
			case SDLK_d:
			case SDLK_RIGHT:
				if (orient.right == 1) {
					//status = IDLE;
					orient.right = 0;
					velocity.dx -= speed;
					//velocity.dx = 0;

				}
				break;
			case SDLK_w:
			case SDLK_UP:
				if (orient.up == 1) {
					//status = IDLE;
					orient.up = 0;
					velocity.dy += speed;
				}
				break;
			}
		}
		if (check == true) {
			status = IDLE;
		}
	}
}

void Wolf::loadClips() {
	for (int i = 0; i < 6; i++) {
		SDL_Rect rect = { i * 108 + 10, 10, 100, 80 };
		clips.push_back(rect);
	}
}

void Wolf::init() {
	SDL_Log("wolf init \n");
	setLocation({ 600, 320 });
	loadClips();
	des.w = 100;
	des.h = 80;
}

void Wolf::render() {

	//if (texture == nullptr) std::cout << "null texture" << std::endl;

	if (status == IDLE) {
		frameCount = 0;
		src = clips[0];
	}
	else if (status == WALK) {
		frameCount++;
		if (frameCount == MAX_WOLF_FRAME_WALK - 1) frameCount = 0;
		src = clips[frameCount / 5];
	}
	SDL_RenderCopyEx(Global::renderer, texture, &src, &des, NULL, NULL, flip);
}

void Wolf::action() {
	if (velocity.dx == 0 && velocity.dy == 0) return;
	Vector2D v = Vector2D(velocity.dx, velocity.dy);
	if (v.getX() != 0 && v.getY() != 0) v / sqrt(2);
	des.x += v.getX();
	des.y += v.getY();
}