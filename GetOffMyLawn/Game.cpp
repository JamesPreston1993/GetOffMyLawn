#include "Game.h"

#include <iostream>

Game::Game()
{
	this->isRunning = true;
	this->window = new Window(ConfigurationManager::getScreenWidth(), ConfigurationManager::getScreenHeight());

	this->score = 0;
	player = new Player(0, 0);
	this->player->setXPos(this->window->getWidth() / 2 - (this->player->getWidth() / 2));
	this->player->setYPos(this->window->getHeight() - (this->player->getHeight() + 16));
	this->run();
}

Game::~Game()
{
	delete this->player;
	delete this->window;
	for each(GenericEnemy* enemy in this->enemies)
		delete enemy;
}

void Game::run()
{
	while (isRunning)
	{
		// Update
		if (!this->update())
			this->isRunning = false;
		else
		{
			// Draw
			this->draw();

			// Maintain FPS
			unsigned int currentTime = SDL_GetTicks();
			unsigned int currentSpeed = SDL_GetTicks() - currentTime;
			if (this->fpsInMilliseconds > currentSpeed)
				SDL_Delay(fpsInMilliseconds - currentSpeed);
		}
	}
}

bool Game::update()
{
	// Create an event
	SDL_Event event;

	// Wait until the event to trigger something
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			return false;
	}

	// Check game over
	if (this->checkGameOver())
	{
		// Replace this with open a new menu		
		return false;
	}

	// Check if the player has killed
	this->checkKills();

	// Check player input
	if (!this->inputManager.checkInput(this->player))
		return false;

	// Update player
	this->player->update();

	// Update Enemies
	for each(GenericEnemy* enemy in this->enemies)
		enemy->update();

	// Try to generate enemy
	GenericEnemy* enemy = generator.generateEnemy();
	if (enemy != NULL)
		enemies.push_back(enemy);
	else
		delete enemy;

	return true;
}

void Game::draw()
{
	this->window->clear();
	this->window->drawBackground();
	for each(GenericEnemy* enemy in this->enemies)
		this->window->drawEnemy(enemy);
	this->window->drawPlayer(this->player);

	this->window->drawGUI(this->score);

	// TO DO: Draw in reverse	
	this->window->update();
}

bool Game::checkGameOver()
{
	for each(GenericEnemy* enemy in this->enemies)
	{
		short endZone = ConfigurationManager::getScreenHeight() * 3 / 4 - enemy->getHeight();
		if (enemy->getYPos() >= endZone)
		{
			return true;
		}
	}
	return false;
}

void Game::checkKills()
{
	for (int blastIndex = 0; blastIndex < this->player->getWaterBlasts().size(); blastIndex++)
	{
		WaterBlast* blast = this->player->getWaterBlasts().at(blastIndex);

		bool deleteBlast = false;

		for (int enemyIndex = 0; enemyIndex < enemies.size(); enemyIndex++)
		{

			GenericEnemy* enemy = this->enemies.at(enemyIndex);

			if (blast->checkCollision(enemy))
			{
				// Lower the enemy's health and check if they are dead
				enemy->setHealth(enemy->getHealth() - 1);
				if (enemy->getHealth() <= 0)
				{
					// Add points to score and remove the enemy
					this->score += enemy->getPoints();
					enemies.erase(enemies.begin() + enemyIndex);
					delete enemy;
				}

				// Set delete blast to true - handles if one blast hits multiple enemies
				deleteBlast = true;
			}
		}

		if (deleteBlast)
		{
			this->player->getWaterBlasts().erase(this->player->getWaterBlasts().begin() + blastIndex);
			delete blast;
		}
	}
}