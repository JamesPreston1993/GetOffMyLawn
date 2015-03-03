#pragma once
#include "WaterBlast.h"
#include <vector>

using std::vector;

class Player : public Entity
{
public:
	enum AnimState
	{
		IDLE = 0,
		MOVING = 1
	};
	Player(short x, short y);
	~Player();
	void moveLeft();
	void moveRight();
	void stop();
	void shoot();
	void update();
	void draw(SDL_Renderer* renderer, SDL_Texture* sprite);
	vector<WaterBlast*> &getWaterBlasts();
	AnimState animState;
private:
	unsigned short shootTimer;
	vector<WaterBlast*> waterBlasts;
};