#pragma once
#include "GenericEnemy.h"
class Salesman : public GenericEnemy
{
public:
	Salesman(short x, short y);
	~Salesman();
	void move();
};

