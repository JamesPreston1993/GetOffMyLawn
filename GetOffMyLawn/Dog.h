#pragma once
#include "GenericEnemy.h"

class Dog :	public GenericEnemy
{
public:
	Dog(short x, short y);
	void move();
};