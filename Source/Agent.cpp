#include "Agent.h"

Agent::Agent()
{
	position = Vector2{(float)GetRandomValue(0,GetScreenWidth()),(float)GetRandomValue(0,GetScreenHeight())};
	dead = false;
	isActive = true;

	hp = 100;
}

Agent::~Agent()
{
}

Vector2 Agent::GetPosition()
{
	return position;
}

