#pragma once
#include <SDL.h>
#include "Configuration.h"

class Entity
{
public:
	Entity(short x, short y, short w, short h);

	short getSpriteID();
	void setSpriteID(short spriteID);

	short getXPos();
	void setXPos(const short xPos);

	short getYPos();
	void setYPos(const short yPos);

	short getWidth();
	void setWidth(const short width);

	short getHeight();
	void setHeight(const short height);

	bool getCastShadow();
	void setCastShadow(bool castShadow);

	virtual void update() = 0;
	virtual void draw(SDL_Renderer* renderer, SDL_Texture* sprite);

	bool checkCollision(Entity *entity);

private:
	short spriteID;
	short xPos;
	short yPos;
	short width;
	short height;
	bool castShadow;
};