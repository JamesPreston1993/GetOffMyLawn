#pragma once
#include <stdlib.h>
#include <time.h>
#include "Neighbour.h"
#include "Dog.h"
#include "Salesman.h"
#include "Configuration.h"

class EnemyGenerator
{
public:
	EnemyGenerator();
	GenericEnemy* generateEnemy();

private:
	unsigned short generateTime;
	unsigned short neighbourChance;
	unsigned short salesmanChance;
	unsigned short dogChance;
};

