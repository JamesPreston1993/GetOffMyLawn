#include "Neighbour.h"

Neighbour::Neighbour(short x, short y) : GenericEnemy(x, y)
{
	this->setSpriteID(2);
	this->setSpeed(7);
	this->setPoints(5);
	this->setHealth(1);
}

void Neighbour::move()
{
	if (this->getTimer() == 10 - this->getSpeed())
	{
		this->setYPos(this->getYPos() + this->getSpeed());
		this->setTimer(0);
	}
	else
		this->setTimer(this->getTimer() + 1);
}