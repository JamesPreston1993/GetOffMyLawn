#include "Dog.h"

Dog::Dog(short x, short y) : GenericEnemy(x, y)
{
	this->setSpriteID(4);
	this->setSpeed(8);
	this->setPoints(10);
	this->setHealth(1);
	this->xIndex = 0;
	
	this->xMovePattern = new short[this->patternLength];
	this->xMovePattern[0] = -16;
	this->xMovePattern[1] = -16;
	this->xMovePattern[2] = -16;
	this->xMovePattern[3] = -16;
	this->xMovePattern[4] = 16;
	this->xMovePattern[5] = 16;
	this->xMovePattern[6] = 16;
	this->xMovePattern[7] = 16;
	this->xMovePattern[8] = 16;
	this->xMovePattern[9] = 16;
	this->xMovePattern[10] = 16;
	this->xMovePattern[11] = 16;
	this->xMovePattern[12] = -16;
	this->xMovePattern[13] = -16;
	this->xMovePattern[14] = -16;
	this->xMovePattern[15] = -16;
}

void Dog::move()
{
	if (this->getTimer() == 10 - this->getSpeed())
	{				
		this->setYPos(this->getYPos() + this->getSpeed());		
		this->setXPos(this->getXPos() + this->xMovePattern[this->xIndex]);
		this->setTimer(0);
		this->xIndex++;
		if (this->xIndex == this->patternLength)
			this->xIndex = 0;
	}
	else
		this->setTimer(this->getTimer() + 1);
}