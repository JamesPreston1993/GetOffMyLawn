#pragma once
#include "GenericEnemy.h"

class Neighbour : public GenericEnemy
{
public:
	Neighbour(short x, short y);
	void move();
};