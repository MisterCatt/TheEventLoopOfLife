#include "Sheep.h"

Sheep::Sheep()
{
	position = Vector2{(float) GetRandomValue(0, GetScreenWidth()), (float)GetRandomValue(0, GetScreenHeight())};

	dead = false;
	isActive = true;

	energy = 100;
}

Sheep::~Sheep()
{
}

void Sheep::Sense()
{
}

void Sheep::Decide()
{
}

void Sheep::Act()
{
}

void Sheep::Idle()
{

}

void Sheep::Run()
{
}
