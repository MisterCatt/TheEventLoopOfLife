#include "TileManager.h"

TileManager* TileManager::Instance = nullptr;

TileManager::TileManager()
{
}

TileManager* TileManager::GetInstance()
{
	if (!Instance)
		Instance = new TileManager;
	return Instance;
}

TileManager::~TileManager()
{
}

void TileManager::Update()
{
	for (int x = 0; x < tileMap.xTiles; x++) {
		for (int y = 0; y < tileMap.yTiles; y++) {
			tileMap.map[x][y].Update();
		}
	}
}

void TileManager::Render()
{
	for (int x = 0; x < tileMap.xTiles; x++) {
		for (int y = 0; y < tileMap.yTiles; y++) {
			switch (tileMap.map[x][y].GetTileType()) {
			case Dirt:
				DrawRectangle(GetScreenWidth() / tileMap.xTiles * x, GetScreenHeight() / tileMap.yTiles * y, GetScreenWidth() / tileMap.xTiles, GetScreenHeight() / tileMap.yTiles, BROWN);
				break;
			case Grass:
				DrawRectangle(GetScreenWidth() / tileMap.xTiles * x, GetScreenHeight() / tileMap.yTiles * y, GetScreenWidth() / tileMap.xTiles, GetScreenHeight() / tileMap.yTiles, GREEN);
				break;
			case Rock:
				DrawRectangle(GetScreenWidth() / tileMap.xTiles * x, GetScreenHeight() / tileMap.yTiles * y, GetScreenWidth() / tileMap.xTiles, GetScreenHeight() / tileMap.yTiles, GRAY);
				break;
			default:
				DrawRectangle(GetScreenWidth() / tileMap.xTiles * x, GetScreenHeight() / tileMap.yTiles * y, GetScreenWidth() / tileMap.xTiles, GetScreenHeight() / tileMap.yTiles, BROWN);
				break;
			}
		}
	}
}

Tile TileManager::GetTile(int x, int y)
{
	int xPos = floor(x / 40);
	int yPos = floor(y / 40);


	return tileMap.map[xPos][yPos];
}

