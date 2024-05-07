#include "sheep.h"
#include <cstdlib> // For rand() and RAND_MAX
#include <cmath> 



static float customRandFloat(float min, float max) {
	return min + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (max - min));
}

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


bool Sheep::trackWolf(Vector2D v) {
	if (v.length() <= 32 * 10) return true;
	return false;
}

void Sheep::moveToSafeZone(Vector2D v) {
	if (v.getX() > 0) flip = SDL_FLIP_HORIZONTAL;
	else if (v.getX() < 0) flip = SDL_FLIP_NONE;
	v.reverse();
	//Vector2D t = v;
	if (/*v.getX() != 0 && v.getY() != 0*/ true) v.normalize();
	if (!isCollideHorizontal(v.getX() * speed)) {
		des.x += v.getX() * speed;
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

bool Sheep::isInSafeZone() {
	int sheepX = getPosition().x;
	int sheepY = getPosition().y;
	if (sheepX >= 400 && sheepX <= 800 && sheepY >= 50 && sheepY <= 480) {
		return true;
	}
}


void Sheep::moveRandom() {
	// Increment the wander angle to gradually change direction
	currentAngle += customRandFloat(-0.1f, 0.1f); // Adjust the range of angle change as needed

	// Calculate the velocity vector based on the wander angle and speed
	Vector2D velocity(WANDER_SPEED * std::cos(currentAngle), WANDER_SPEED * std::sin(currentAngle));

	// Update the position based on the velocity
	int newX = des.x + static_cast<int>(velocity.getX());
	int newY = des.y + static_cast<int>(velocity.getY());

	// Ensure the new position is within screen bounds
	if (newX >= 0 && newX + des.w <= SCREENWIDTH && newY >= 0 && newY + des.h <= SCREENHEIGHT) {
		des.x = newX;
		des.y = newY;
	}
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