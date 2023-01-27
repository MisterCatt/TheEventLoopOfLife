#include "Sheep.h"

Sheep::Sheep()
{
	position = Vector2{(float) GetRandomValue(0, GetScreenWidth()), (float)GetRandomValue(0, GetScreenHeight())};

	dead = false;
	isActive = true;

}

Sheep::~Sheep()
{
}