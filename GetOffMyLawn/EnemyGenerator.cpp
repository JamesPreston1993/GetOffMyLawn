#include "EnemyGenerator.h"

EnemyGenerator::EnemyGenerator()
{
	this->generateTime = 0;
	this->neighbourChance = 50;
	this->salesmanChance = 30;
	this->dogChance = 20;
}

GenericEnemy* EnemyGenerator::generateEnemy()
{
	if (this->generateTime == 150)
	{
		// Random enemy at random time		
		this->generateTime = 0;

		srand(time(NULL));

		unsigned short random = rand() % 100;
		unsigned short xPos = rand() % (ConfigurationManager::getScreenWidth() / ConfigurationManager::getSpriteWidth());

		if (random < neighbourChance)
			return new Neighbour(xPos * ConfigurationManager::getSpriteWidth(), -ConfigurationManager::getSpriteHeight());
		else if (random < neighbourChance + salesmanChance)
			return new Salesman(xPos * ConfigurationManager::getSpriteWidth(), -ConfigurationManager::getSpriteHeight());
		else
			return new Dog(xPos * ConfigurationManager::getSpriteWidth(), -ConfigurationManager::getSpriteHeight());
	}
	else
	{
		this->generateTime++;
		return NULL;
	}
}
