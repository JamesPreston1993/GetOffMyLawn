#include "Player.h"

Player::Player(short x, short y) : Entity(x, y, 96, 128)
{
	this->setSpriteID(0);
	this->animState = AnimState::IDLE;
	this->shootTimer = 0;
}

Player::~Player()
{
	for each(WaterBlast* waterBlast in this->waterBlasts)
	{
		delete waterBlast;
	}
}

void Player::moveLeft()
{
	if (this->getXPos() > 16)
	{
		this->setXPos(this->getXPos() - 8);
		this->animState = AnimState::MOVING;
	}
}

void Player::moveRight()
{
	if (this->getXPos() < Configuration::getScreenWidth() - (this->getWidth() + 16))
	{
		this->setXPos(this->getXPos() + 8);
		this->animState = AnimState::MOVING;
	}
}

void Player::stop()
{
	this->animState = AnimState::IDLE;
}

void Player::shoot()
{
	if (this->shootTimer == 0)
	{
		this->shootTimer = 50;
		WaterBlast* blast = new WaterBlast(this->getXPos(), this->getYPos() - this->getHeight());
		blast->setXPos(this->getXPos() + (blast->getWidth() / 2));
		this->waterBlasts.push_back(blast);
	}
}

void Player::update()
{
	if (this->shootTimer > 0)
	{
		this->shootTimer--;
	}

	for (short index = 0; index < this->waterBlasts.size();)
	{
		WaterBlast* waterBlast = this->waterBlasts.at(index);
		waterBlast->update();

		if (waterBlast->getYPos() < -waterBlast->getHeight())
		{
			this->waterBlasts.erase(this->waterBlasts.begin() + index);
			delete waterBlast;
		}
		else
			index++;
	}
}

void Player::draw(SDL_Renderer* renderer, SDL_Texture* texture)
{
	SDL_Rect* sourceRect = new SDL_Rect();
	sourceRect->x = (SDL_GetTicks() / 500 % 2) * this->getWidth();
	sourceRect->y = (this->animState + this->getSpriteID()) * this->getHeight();
	sourceRect->w = this->getWidth();
	sourceRect->h = this->getHeight();

	SDL_Rect* destRect = new SDL_Rect();
	destRect->x = this->getXPos();
	destRect->y = this->getYPos();
	destRect->w = this->getWidth();
	destRect->h = this->getHeight();

	SDL_RenderCopy(renderer, texture, sourceRect, destRect);

	for each(WaterBlast* waterBlast in this->waterBlasts)
	{
		waterBlast->draw(renderer, texture);
	}

	delete sourceRect;
	delete destRect;
}

vector<WaterBlast*> &Player::getWaterBlasts()
{
	return this->waterBlasts;
}