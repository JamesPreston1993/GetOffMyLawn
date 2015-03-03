#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Player.h"
#include <string>
#include "GenericEnemy.h"

class Window
{
public:
	Window(short width, short height);
	~Window();
	void setup();
	void update();
	void draw();
	void clear();
	void drawPlayer(Player* player);
	void drawEnemy(GenericEnemy* enemy);
	void drawBackground();
	void drawGUI(unsigned short score);
	SDL_Renderer* getRenderer();
	short getWidth();
	short getHeight();
private:
	// Variables
	short winWidth;
	short winHeight;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* spritesheet;
	SDL_Texture* background;
};