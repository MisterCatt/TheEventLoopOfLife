#include "TileMap.h"

TileMap::TileMap()
{
	xTiles = 20;
	yTiles = 20;

	for (int y = 0; y < yTiles; y++) {
		for (int x = 0; x < yTiles; x++) {
			tileMap[y][x].SetPosition(x, y);
			tileMap[y][x].type = GetRandomValue(0,2);
		}
	}

	
}

TileMap::~TileMap()
{
}

void TileMap::DrawTiles() 
{
	for (int y = 0; y < yTiles; y++) {
		for (int x = 0; x < xTiles; x++) {
			switch (tileMap[y][x].type)
			{
			case 0:
				break;
			case 1:
				DrawRectangle(GetScreenWidth() / xTiles * x, GetScreenHeight() / yTiles * y, GetScreenWidth() / xTiles, GetScreenHeight() / yTiles, GREEN);
				break;
			case 2:
				DrawRectangle(GetScreenWidth() / xTiles * x, GetScreenHeight() / yTiles * y, GetScreenWidth() / xTiles, GetScreenHeight() / yTiles, GRAY);
				break;
			default:
				tileMap[y][x].type = 1;
				break;
			}
		}
	}
		
}

void TileMap::Update() 
{
	for (int y = 0; y < yTiles; y++) {
		for (int x = 0; x < yTiles; x++) {
			tileMap[y][x].Update();
		}
	}
}
