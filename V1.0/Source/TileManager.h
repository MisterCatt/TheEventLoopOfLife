#pragma once
#include "Core.h"
#include "TileMap.h"

class TileManager
{
public:

	static TileManager* Instance;

	static TileManager* GetInstance();

	
	~TileManager();

	void Render();
	void Update();

	Rectangle GetTile(int x, int y);

private:
	TileManager();

	TileMap tm;
};
