#include "EnemyGenerator.h"

EnemyGenerator::EnemyGenerator()
{
	this->generateTime = 0;
	this->neighbourChance = 65;
	this->salesmanChance = 25;
	this->dogChance = 20;
}

GenericEnemy* EnemyGenerator::generateEnemy()
{
	if (this->generateTime == 100)
	{
		// Random enemy at random time		
		this->generateTime = 0;

		srand(time(NULL));

		unsigned short random = rand() % 100;
		unsigned short xPos = rand() % (Configuration::getScreenWidth() / Configuration::getSpriteWidth());

		if (random < neighbourChance)
			return new Neighbour(xPos * Configuration::getSpriteWidth(), -Configuration::getSpriteHeight());
		else if (random < neighbourChance + salesmanChance)
			return new Salesman(xPos * Configuration::getSpriteWidth(), -Configuration::getSpriteHeight());
		else
			return new Dog(xPos * Configuration::getSpriteWidth(), -Configuration::getSpriteHeight());
	}
	else
	{
		this->generateTime++;
		return NULL;
	}
}
