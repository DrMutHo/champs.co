#pragma once

#define SCREENWIDTH 1280
#define SCREENHEIGHT 640

#define wb 16
#define hb 8
#define TILE 80

#define check (!orient.up && !orient.down && !orient.left && !orient.right)

enum GameState {
	MENU,
	PLAY,
	EXIT,
	PAUSE,
};

enum Status {
	WALK,
	IDLE,
	EAT
};

struct Velocity {
	int dx;
	int dy;
};

struct Orient {
	bool up = 0;
	bool down = 0;
	bool left = 0;
	bool right = 0;
};
