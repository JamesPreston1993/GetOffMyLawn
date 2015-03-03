#pragma once
#include "Window.h"
#include "InputManager.h"
#include "Dog.h"
#include "Player.h"
#include "EnemyGenerator.h"
#include "ConfigurationManager.h"
#include <vector>

using std::vector;

class Game
{
public:
	Game();
	~Game();
	void run();
	bool update();
	void draw();
private:
	unsigned short score;
	const unsigned short FPS = 60;
	const unsigned short fpsInMilliseconds = 1000 / FPS;
	bool isRunning;
	InputManager inputManager;
	EnemyGenerator generator;
	Window* window;
	Player* player;
	vector<GenericEnemy*> enemies;
	unsigned short generateTime;
	bool checkGameOver();
	void checkKills();
};