#pragma once
#include "Entity.h"
class GenericEnemy : public Entity
{
public:
	GenericEnemy(short x, short y);

	short getSpeed();
	void setSpeed(short speed);

	short getHealth();
	void setHealth(short health);

	short getPoints();
	void setPoints(short points);

	short getTimer();
	void setTimer(short timer);

	virtual void move() = 0;
	void update();

private:
	short speed;
	short health;
	short points;
	short canMoveTimer;
};