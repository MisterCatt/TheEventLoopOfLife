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

	Tile GetTile(int, int);
	void SpreadGrass(int, int);

	TileMap tileMap;

private:
	TileManager();
};
