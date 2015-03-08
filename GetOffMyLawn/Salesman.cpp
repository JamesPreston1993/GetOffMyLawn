#include "Salesman.h"

Salesman::Salesman(short x, short y) : GenericEnemy(x, y)
{
	this->setSpriteID(3);
	this->setSpeed(5);
	this->setPoints(20);
	this->setHealth(3);
}

Salesman::~Salesman()
{
}

void Salesman::move()
{
	if (this->getTimer() == 10 - this->getSpeed())
	{
		this->setYPos(this->getYPos() + this->getSpeed());
		this->setTimer(0);
	}
	else
		this->setTimer(this->getTimer() + 1);
}