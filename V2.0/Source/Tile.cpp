#include "Tile.h"

Tile::Tile(TileType _tileType)
{
	tileType = _tileType;

	switch (tileType)
	{
	case Dirt:
		_Energy = 0;
		break;
	case Grass:
		_Energy = 50;
		break;
	case Rock:
		_Energy = -1;
		break;
	default:
		break;
	}

	trampeled = false;

	tm = TileManager::GetInstance();
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

void Tile::Sense()
{
	//set trampled to true if any of the alive agents are trampling on this.
	state = AgentState::Deciding;
}

void Tile::Decide()
{
	if(tileDecision != Descision::Trampeled)
		if (_Energy >= 100) 
		{
			tileDecision = Descision::Spread;
		}
		else 
		{
			tileDecision = Descision::Grow;
		}


	state = AgentState::Acting;
}

void Tile::Act()
{

	switch (tileDecision)
	{
	case Tile::Descision::Spread:
		//spread to adjacant tile

		break;
	case Tile::Descision::Grow:
		_Energy += 0.2f;
		break;
	case Tile::Descision::Trampeled:
		_Energy -= 0.2f;
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
}

TileType Tile::GetTileType()
{
	return tileType;
}

void Tile::SetTileType(TileType _tileType)
{
	tileType = _tileType;

	switch (tileType)
	{
	case Dirt:
		_Energy = 0;
		break;
	case Grass:
		_Energy = 50;
		break;
	case Rock:
		_Energy = -1;
		break;
	default:
		break;
	}
}

Rectangle Tile::GetTileBox()
{
	return Rectangle(_Position.x, _Position.y, (float)GetScreenWidth() / 20, (float)GetScreenHeight() / 20);
}
