#include "Entity.h"

Entity::Entity(short x, short y, short w, short h)
{
	this->xPos = x;
	this->yPos = y;
	this->width = w;
	this->height = h;
	this->castShadow = false;
}

short Entity::getSpriteID()
{
	return this->spriteID;
}

void Entity::setSpriteID(short spriteID)
{
	this->spriteID = spriteID;
}

short Entity::getXPos()
{
	return this->xPos;
}

void Entity::setXPos(const short xPos)
{
	if (xPos >= 0 && xPos <= Configuration::getScreenWidth() - this->width)
		this->xPos = xPos;
}

short Entity::getYPos()
{
	return this->yPos;
}

void Entity::setYPos(const short yPos)
{
	this->yPos = yPos;
}

short Entity::getWidth()
{
	return this->width;
}

void Entity::setWidth(const short width)
{
	this->width = width;
}

short Entity::getHeight()
{
	return this->height;
}

void Entity::setHeight(const short height)
{
	this->height = height;
}

bool Entity::getCastShadow()
{
	return this->castShadow;
}

void Entity::setCastShadow(bool castShadow)
{
	this->castShadow = castShadow;
}

void Entity::draw(SDL_Renderer* renderer, SDL_Texture* texture)
{

	SDL_Rect* sourceRect = new SDL_Rect();
	SDL_Rect* destRect = new SDL_Rect();

	if (this->castShadow)
	{
		// Draw the shadow
		sourceRect->x = 0;
		sourceRect->y = 6 * Configuration::getSpriteHeight();
		sourceRect->w = this->getWidth();
		sourceRect->h = 48;

		destRect->x = this->getXPos();
		destRect->y = this->getYPos() + (this->getHeight() - (48 / 2));
		destRect->w = this->getWidth();
		destRect->h = 48;

		SDL_RenderCopy(renderer, texture, sourceRect, destRect);
	}

	// Draw the entity
	sourceRect->x = (SDL_GetTicks() / 500 % 2) * Configuration::getSpriteWidth();
	sourceRect->y = this->spriteID * Configuration::getSpriteHeight();
	sourceRect->w = Configuration::getSpriteWidth();
	sourceRect->h = Configuration::getSpriteHeight();

	destRect->x = this->getXPos();
	destRect->y = this->getYPos();
	destRect->w = this->getWidth();
	destRect->h = this->getHeight();

	SDL_RenderCopy(renderer, texture, sourceRect, destRect);

	// Clean up
	delete sourceRect;
	delete destRect;
}

bool Entity::checkCollision(Entity *entity)
{
	if (this->xPos + this->getWidth() >= entity->getXPos() &&
		this->xPos <= entity->getXPos() + entity->getWidth() &&
		this->yPos <= entity->getYPos() + entity->getHeight())
	{
		return true;
	}
	return false;
}