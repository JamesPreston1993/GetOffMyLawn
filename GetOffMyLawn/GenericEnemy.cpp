#include "GenericEnemy.h"

GenericEnemy::GenericEnemy(short x, short y) : Entity(x, y, 96, 128)
{
	this->canMoveTimer = 0;
	this->setCastShadow(true);
}

short GenericEnemy::getSpeed()
{
	return this->speed;
}

void GenericEnemy::setSpeed(short speed)
{
	this->speed = speed;
}

short GenericEnemy::getHealth()
{
	return this->health;
}

void GenericEnemy::setHealth(short health)
{
	this->health = health;
}

short GenericEnemy::getPoints()
{
	return this->points;
}

void GenericEnemy::setPoints(short points)
{
	this->points = points;
}

short GenericEnemy::getTimer()
{
	return this->canMoveTimer;
}

void GenericEnemy::setTimer(short timer)
{
	this->canMoveTimer = timer;
}

void GenericEnemy::update()
{
	this->move();
}