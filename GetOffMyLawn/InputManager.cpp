#include "InputManager.h"


InputManager::InputManager()
{
	this->keystate = SDL_GetKeyboardState(NULL);
}

InputManager::~InputManager()
{
	
}

bool InputManager::checkInput(Player* player)
{
	SDL_PumpEvents();
	this->keystate = SDL_GetKeyboardState(NULL);

	if (this->keystate[SDL_SCANCODE_SPACE])
	{
		player->shoot();
	}

	if (this->keystate[SDL_SCANCODE_ESCAPE])
	{
		return false;
	}

	else if (this->keystate[SDL_SCANCODE_LEFT])
	{
		if (this->keystate[SDL_SCANCODE_RIGHT])
			player->stop();
		else
			player->moveLeft();
	}

	else if (this->keystate[SDL_SCANCODE_RIGHT])
	{
		if (this->keystate[SDL_SCANCODE_LEFT])
			player->stop();
		else
			player->moveRight();
	}

	else
		player->stop();

	return true;
}