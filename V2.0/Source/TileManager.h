#pragma once
#include "TileMap.h"
#include <math.h>

class TileManager
{
public:
	
	static TileManager* Instance;

	static TileManager* GetInstance();

	~TileManager();

	void Update();
	void Render();

	Tile GetTile(int x, int y);

	TileMap tileMap;

private:
	TileManager();
};
