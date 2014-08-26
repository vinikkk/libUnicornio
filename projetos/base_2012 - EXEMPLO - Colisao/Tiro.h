#pragma once
#include "libUnicornio.h"

class Tiro
{
public:
	Tiro();
	~Tiro();

	void setSpriteSheet(SpriteSheet* sheet);
	void setPos(float x, float y);

	Sprite* getSprite();
	float getPosX();
	float getPosY();
	float getRot();

	void atualizar();
	void desenhar();

private:
	Sprite spr;
	float x, y;
	float vel;
};
