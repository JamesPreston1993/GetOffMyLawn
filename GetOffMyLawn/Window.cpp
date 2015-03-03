#include "Window.h"

Window::Window(short width, short height)
{
	this->winWidth = width;
	this->winHeight = height;
	this->setup();
}

Window::~Window()
{
}

void Window::setup()
{
	// Initialise SDL
	SDL_Init(SDL_INIT_VIDEO);

	// Load Font
	TTF_Init();

	// Create window
	this->window = SDL_CreateWindow("Get Off My Lawn!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->winWidth, this->winHeight, SDL_WINDOW_OPENGL);

	// Create renderer
	this->renderer = SDL_CreateRenderer(this->window, 0, SDL_RENDERER_ACCELERATED);

	// Load background
	SDL_Surface* bkFile = IMG_Load("Images/grass.png");
	if (bkFile == NULL)
		SDL_ShowSimpleMessageBox(NULL, "ERROR: Loading png", SDL_GetError(), this->window);
	this->background = SDL_CreateTextureFromSurface(this->renderer, bkFile);
	if (background == NULL)
		SDL_ShowSimpleMessageBox(NULL, "ERROR: Loading sprite sheet", SDL_GetError(), this->window);
	SDL_FreeSurface(bkFile);

	// Load spritesheet
	SDL_Surface* imgFile = IMG_Load("Images/spriteSheet.png");
	if (imgFile == NULL)
		SDL_ShowSimpleMessageBox(NULL, "ERROR: Loading png", SDL_GetError(), this->window);
	this->spritesheet = SDL_CreateTextureFromSurface(this->renderer, imgFile);
	if (spritesheet == NULL)
		SDL_ShowSimpleMessageBox(NULL, "ERROR: Loading sprite sheet", SDL_GetError(), this->window);
	SDL_FreeSurface(imgFile);

	// Refresh
	this->update();
}

void Window::update()
{
	SDL_RenderPresent(this->renderer);
}

void Window::clear()
{
	SDL_RenderClear(this->renderer);
}

void Window::drawPlayer(Player* player)
{
	player->draw(this->renderer, this->spritesheet);
}

void Window::drawEnemy(GenericEnemy* enemy)
{
	enemy->draw(this->renderer, this->spritesheet);
}

void Window::drawBackground()
{
	SDL_RenderCopy(this->renderer, this->background, NULL, NULL);
}

void Window::drawGUI(unsigned short score)
{
	unsigned short scaleX = 64;
	unsigned short scaleY = 64;

	// Format the scoreboard
	if (score < 10)
		scaleX = 64;
	else if (score < 100)
		scaleX = 128;
	else if (score < 1000)
		scaleX = 192;
	else
		scaleX = 256;

	TTF_Font* font = TTF_OpenFont("Fonts/DSAccent.ttf", 64);
	SDL_Color colour = { 255, 255, 255 };

	SDL_Surface* surface = TTF_RenderText_Blended(font, std::to_string(score).c_str(), colour);

	SDL_Texture* texture = SDL_CreateTextureFromSurface(this->renderer, surface);

	SDL_Rect* scoreBoard = new SDL_Rect();
	scoreBoard->x = this->winWidth - scaleX;
	scoreBoard->y = 0;
	scoreBoard->w = scaleX;
	scoreBoard->h = scaleY;

	SDL_RenderCopy(this->renderer, texture, NULL, scoreBoard);

	TTF_CloseFont(font);
}

SDL_Renderer* Window::getRenderer()
{
	return this->renderer;
}

short Window::getWidth()
{
	return this->winWidth;
}

short Window::getHeight()
{
	return this->winHeight;
}