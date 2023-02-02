#include "Sheep.h"

Sheep::Sheep()
{
	_Position = Vector2{ (float)GetRandomValue(0, GetScreenWidth()), (float)GetRandomValue(0, GetScreenHeight()) };

	descision = SheepDecision::Wander;

	_MovePoint = { _Position.x + (float)GetRandomValue(-50, 50), _Position.y + (float)GetRandomValue(-50, 50) };
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
	/*if (IsKeyDown(KEY_RIGHT)) {
		movePoint.x+=10;
	}
	if (IsKeyDown(KEY_UP)) {
		movePoint.y-=10;
	}
	if (IsKeyDown(KEY_LEFT)) {
		movePoint.x-=10;
	}
	if (IsKeyDown(KEY_DOWN)) {
		movePoint.y+=10;
	}*/

	Timer();
}

void Sheep::Sense()
{
	state = AgentState::Deciding;
}

void Sheep::Decide()
{
	descision = SheepDecision::Wander;

	state = AgentState::Acting;
}

void Sheep::Act()
{
	switch (descision)
	{
	case Sheep::SheepDecision::Evade:
		EvadeWolves();
		break;
	case Sheep::SheepDecision::Find:
		Find();
		break;
	case Sheep::SheepDecision::Eat:
		Eat();
		break;
	case Sheep::SheepDecision::Breed:
		Breed();
		break;
	case Sheep::SheepDecision::Wander:
		Wander();
		break;
	default:
		break;
	}

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
	//movePoint = { _Position.x + (float)GetRandomValue(0, GetScreenWidth()), _Position.y + (float)GetRandomValue(0, GetScreenHeight()) };

	

	_Position = MoveTowards(_MovePoint, _Position, 0.5f);
}




