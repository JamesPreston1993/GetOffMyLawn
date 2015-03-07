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
	this->background = SDL_CreateTextureFromSurface(this->renderer, bkFile);	
	SDL_FreeSurface(bkFile);

	// Load spritesheet
	SDL_Surface* imgFile = IMG_Load("Images/spriteSheet.png");	
	this->spritesheet = SDL_CreateTextureFromSurface(this->renderer, imgFile);	
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
	SDL_Rect* background = new SDL_Rect();
	background->x = 0;
	background->y = 0;
	background->w = this->winWidth;
	background->h = this->winHeight;
	SDL_RenderCopy(this->renderer, this->background, NULL, background);
	delete background;
}

void Window::drawGUI(unsigned short score)
{
	unsigned short scaleX = 48;
	unsigned short scaleY = 48;

	// Format the scoreboard		
	if (score < 10)
		scaleX = scaleX;
	else if (score < 100)
		scaleX *= 2;
	else if (score < 1000)
		scaleX *= 3;
	else if (score < 10000)
		scaleX *= 4;	

	TTF_Font* font = TTF_OpenFont("Fonts/DSAccent.ttf", 64);
	SDL_Color colour = { 255, 255, 255 };

	SDL_Surface* surface = TTF_RenderText_Blended(font, std::to_string(score).c_str(), colour);	

	SDL_Texture* texture = SDL_CreateTextureFromSurface(this->renderer, surface);

	SDL_Rect* scoreBoard = new SDL_Rect();
	scoreBoard->x = 8;
	scoreBoard->y = this->winHeight - scaleY;
	scoreBoard->w = scaleX;
	scoreBoard->h = scaleY;

	SDL_RenderCopy(this->renderer, texture, NULL, scoreBoard);

	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	delete scoreBoard;

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