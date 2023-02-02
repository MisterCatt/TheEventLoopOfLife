#include "Sheep.h"

Sheep::Sheep()
{
	_Position = Vector2{ (float)GetRandomValue(0, GetScreenWidth()), (float)GetRandomValue(0, GetScreenHeight()) };
}

Sheep::~Sheep()
{
}

void Sheep::Update()
{
	switch (state)
	{
	case Agent::AgentState::Sensing:
		Sense();
		break;
	case Agent::AgentState::Deciding:
		Decide();
		break;
	case Agent::AgentState::Acting:
		Act();
		break;
	default:
		break;
	}
	Timer();
}

void Sheep::Sense()
{
	state = AgentState::Deciding;
}

void Sheep::Decide()
{
	state = AgentState::Acting;
}

void Sheep::Act()
{
	switch (_ShouldSense)
	{
	case true:
		state = AgentState::Sensing;
		_ShouldSense = false;
		break;
	default:
		state = AgentState::Acting;
		break;
	}
	Hp -= 0.2f;
}

void Sheep::EvadeWolves()
{
}

void Sheep::Find()
{
}

void Sheep::Eat()
{
	Hp += 50;

	if (Hp > 100)
		Hp = 100;
}

void Sheep::Breed()
{
}

void Sheep::Wander()
{
}
