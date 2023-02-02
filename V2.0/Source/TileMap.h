#pragma once
#include "Tile.h"

class TileMap
{
public:
	TileMap();
	~TileMap();

	static const int xTiles = 20, yTiles = 20;

	Tile map[xTiles][yTiles];

private:
	
	TileType GetRandomTile();

};

