#include "WaterBlast.h"

WaterBlast::WaterBlast(short x, short y) : Entity(x, y, 48, 128)
{
	this->setSpriteID(5);
}

void WaterBlast::update()
{
	this->setYPos(this->getYPos() - 4);
}