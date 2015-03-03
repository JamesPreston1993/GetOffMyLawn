#include "Dog.h"

Dog::Dog(short x, short y) : GenericEnemy(x, y)
{
	this->setSpriteID(4);
	this->setSpeed(8);
	this->setPoints(10);
	this->setHealth(2);
}

void Dog::move()
{
	if (this->getTimer() == 10 - this->getSpeed())
	{
		this->setYPos(this->getYPos() + this->getSpeed());
		this->setTimer(0);
	}
	else
		this->setTimer(this->getTimer() + 1);
}