#include "Sheep.h"

Sheep::Sheep()
{
	position = Vector2{(float) GetRandomValue(0, GetScreenWidth()), (float)GetRandomValue(0, GetScreenHeight())};

	dead = false;
	isActive = true;

	energy = 100;

	sheepBehaviour = Behaviour::Idle;
}

Sheep::~Sheep()
{
}

void Sheep::Sense()
{
	state = AgentState::Deciding;
}

void Sheep::Decide()
{
	if (energy >= 30) {
		sheepBehaviour = Behaviour::Idle;
	}


	state = AgentState::Acting;
}

void Sheep::Act()
{

	Idle();

	if (shouldSense)
		state = AgentState::Sensing;
	else
		state = AgentState::Acting;
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
	
	switch (sheepBehaviour)
	{
	case Sheep::Behaviour::Idle:
		break;
	case Sheep::Behaviour::Running:
		break;
	default:
		break;
	}

	Timer();
}

void Sheep::Idle()
{
	int x = GetRandomValue(-1,1);
	int y = GetRandomValue(-1,1);

	position.x += x;
	position.y += y;
}

void Sheep::Run()
{
}
