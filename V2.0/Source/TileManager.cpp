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

			if (tileMap.map[x][y].SpreadGrass) 
			{
				SpreadGrass(x,y);
				tileMap.map[x][y].Spreading();
				tileMap.map[x][y].SpreadGrass = false;
			}
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
	int xPos = (int)floor(x / 40);
	int yPos = (int)floor(y / 40);


	return tileMap.map[xPos][yPos];
}

void TileManager::SpreadGrass(int x, int y)
{
	for (int i = 0; i < 4; i++) {
		char dir = "udlr"[rand() % 4];

		if (dir == 'u') {
			if (tileMap.map[x][y + 1].GetTileType() == Dirt) 
			{
				tileMap.map[x][y+1].SetTileType(Grass);
				break;
			}
		}
		if (dir == 'd') {
			if (tileMap.map[x][y - 1].GetTileType() == Dirt) 
			{
				tileMap.map[x][y-1].SetTileType(Grass);
				break;
			}
		}
		if (dir == 'l') {
			if (tileMap.map[x - 1][y].GetTileType() == Dirt) 
			{
				tileMap.map[x - 1][y].SetTileType(Grass);
				break;
			}
		}
		if (dir == 'r') {
		if (tileMap.map[x + 1][y].GetTileType() == Dirt) {
				tileMap.map[x +1][y].SetTileType(Grass);
				break;
			}
		}
	}


}
