#include "sheep.h"

SDL_Texture* Sheep::texture = nullptr;

void Sheep::init() {
	//SDL_Log("Sheep init \n");
	setLocation({ Rand::Randint(0, SCREENWIDTH - 100), Rand::Randint(0, SCREENHEIGHT - 80) });
	loadClips();
	des.w = 100;
	des.h = 80;
}

void Sheep::loadClips() {
	//SDL_Log("Sheep load \n");
	for (int i = 0; i < 6; i++) {
		//SDL_Log("Sheep  \n");
		SDL_Rect idle = { 105 * i, 0, 105, 90 };
		idle_clips.push_back(idle);
		SDL_Rect walk = { 105 * i, 90, 105, 90 };
		clips.push_back(walk);
	}
}

void Sheep::render() {
	if (status == IDLE) {
		frameCount++;
		if (frameCount >= MAX_SHEEP_FRAME_IDLE - 1) frameCount = 0;
		src = idle_clips[frameCount / 40];
	}
	else if (status == WALK) {
		frameCount++;
		if (frameCount >= MAX_SHEEP_FRAME_WALK - 1) frameCount = 0;
		src = clips[frameCount / 20];
	}
	SDL_RenderCopyEx(Global::renderer, texture, &src, &des, NULL, NULL, flip);
}

void Sheep::actions(Wolf* wolf) {
	Vector2D v = Vector2D(getPosition(), wolf->getPosition());
	if (trackWolf(v)) {
		status = WALK;
		moveToSafeZone(v);
	}
	else {
		status = IDLE;
	}
}

void Sheep::randomAction() {
	int randomNum = Rand::Randint(0, 999);
	if (randomNum < 2) {
		bool checkRanAct = true;
		int ranX = Rand::Randint(380, 1000);
		int ranY = Rand::Randint(250, 500);
		std::cout << ranX << " " << ranY << std::endl;
		while (checkRanAct) {
			int sheepX = getPosition().x;
			int sheepY = getPosition().y;
			Vector2D v = Vector2D(ranX-sheepX, ranY - sheepY);
			//std::cout << v.getX() << " " << v.getY() << " " << v.length() << std::endl;
			status = WALK;
			moveRandom(v);
			checkRanAct = !trackRandom(v);
		}
	}
}

bool Sheep::trackRandom(Vector2D v) {
	if (v.length() < 10 ) return true;
	return false;
}

bool Sheep::trackWolf(Vector2D v) {
	if (v.length() <= 32 * 10) return true;
	return false;
}

void Sheep::moveRandom(Vector2D v) {
	if (v.getX() > 0) flip = SDL_FLIP_HORIZONTAL;
	else if (v.getX() < 0) flip = SDL_FLIP_NONE;
	/*v.reverse();*/
	//Vector2D t = v;
	if (/*v.getX() != 0 && v.getY() != 0*/ true) v.normalize();
	if (!isCollideHorizontal(v.getX() * speed)) {
		des.x += v.getX() * speed;
		std::cout << "des X >> " << des.x << std::endl;
	}
	if (!isCollideVertical(v.getY() * speed)) des.y += v.getY() * speed;
}

void Sheep::moveToSafeZone(Vector2D v) {
	if (v.getX() > 0) flip = SDL_FLIP_HORIZONTAL;
	else if (v.getX() < 0) flip = SDL_FLIP_NONE;
	v.reverse();
	//Vector2D t = v;
	if (/*v.getX() != 0 && v.getY() != 0*/ true) v.normalize();
	if (!isCollideHorizontal(v.getX() * speed)) {
		des.x += v.getX() * speed;
		/*std::cout << "des X >> " << des.x << std::endl;*/
	}
	if (!isCollideVertical(v.getY() * speed)) des.y += v.getY() * speed;
}

bool Sheep::isCollideHorizontal(int vel) {
	if (des.x + vel < 0 || des.x + des.w + vel > SCREENWIDTH) return true;
	return false;
}

bool Sheep::isCollideVertical(int vel) {
	if (des.y + vel < 0 || des.y + des.h + vel > SCREENHEIGHT) return true;
	return false;
}

//void Sheep::randomAction() {
//	// Generate a random number between 0 and 99
//	int randomNum = Rand::Randint(0, 999);
//
//	// If the random number is less than 2 (2% chance), change direction randomly
//	if (randomNum < 2) {
//		// Generate random values for dx and dy
//		status = WALK;
//		int randomDx = Rand::Randint(-15, 15); // Adjust range as needed
//		int randomDy = Rand::Randint(-15, 15); // Adjust range as needed
//
//		// Create a normalized velocity vector
//		Vector2D v = Vector2D(randomDx, randomDy);
//		v.normalize();
//
//		// Update the flip based on the horizontal velocity
//		flip = (v.getX() > 0) ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;
//
//		// Increase the distance traveled by multiplying by a factor
//		float distanceFactor = 10.0f; // Adjust as needed
//		float moveX = v.getX() * speed * distanceFactor; // Adjust speed as needed
//		float moveY = v.getY() * speed * distanceFactor; // Adjust speed as needed
//
//		// Move the sheep only once per frame
//		if (!isCollideHorizontal(moveX)) {
//			des.x += moveX;
//		}
//		if (!isCollideVertical(moveY)) {
//			des.y += moveY;
//		}
//	}
//	else {
//		status = IDLE;
//	}
//}