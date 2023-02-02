#pragma once
#include "Core.h"
#include "Agent.h"
#include "TileManager.h"

class Tile : public Agent
{
public:
	Tile(TileType _tileType = Dirt);
	~Tile();

	void Update();

	void Sense();
	void Decide();
	void Act();

	TileType GetTileType();
	void SetTileType(TileType);

	bool trampeled;

	Rectangle GetTileBox();

private:

	enum class Descision { Spread, Grow, Trampeled } tileDecision;

	TileType tileType;

	TileManager* tm;
};

