#pragma once
#include "Core.h"
#include "Tile.h"

class TileMap
{
public:
	TileMap();
	~TileMap();

	void Update();
	void DrawTiles();

private:
	int xTiles;
	int yTiles;

	Tile tileMap[20][20];
};

