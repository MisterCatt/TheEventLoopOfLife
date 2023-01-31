#include "Tile.h"

Tile::Tile()
{
	type = 0;
	hp = 100;
	energy = 0;
	tile = { 0,0,0,0 };
	position = { 0,0 };
	multiplying = false;
	trampled = false;
	state = AgentState::Sensing;
}

Tile::~Tile()
{
}

void Tile::Update() 
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
}

Rectangle Tile::GetTile()
{
	return { position.x, position.y, (float)GetScreenWidth() / 20, (float)GetScreenHeight() / 20 };
}

void Tile::Sense() 
{
	state = AgentState::Deciding;
}

void Tile::Decide() 
{
	state = AgentState::Acting;
}

void Tile::Act() 
{
	if(trampled)
	{
		if(energy > 0)
		energy-=0.2;
	}
	else
	{
		if (energy <= 100) {
			energy += 0.2;
		}
		
	}


	if (shouldSense)
		state = AgentState::Sensing;
}