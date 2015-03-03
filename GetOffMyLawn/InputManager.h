#pragma once
#include <SDL.h>
#include "Player.h"

class InputManager
{
public:
	InputManager();
	~InputManager();
	bool checkInput(Player* player);
private:
	bool checkKeyboardInput(Player* player);
	const Uint8* keystate;
};