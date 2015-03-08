#pragma once
#include "GenericEnemy.h"

class Dog :	public GenericEnemy
{
public:
	Dog(short x, short y);
	void move();
private:	
	const unsigned short patternLength = 16;
	short* xMovePattern;
	unsigned short xIndex;
};