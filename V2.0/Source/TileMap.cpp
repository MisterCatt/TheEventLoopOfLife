#include "TileMap.h"

TileMap::TileMap()
{

	for (int x = 0; x < xTiles; x++) {
		for (int y = 0; y < yTiles; y++) {
			map[x][y].SetTileType(GetRandomTile());
			map[x][y].SetPosition({ (float)x * xTiles, (float)y * yTiles });
		}
	}

}

TileMap::~TileMap()
{
}

TileType TileMap::GetRandomTile() {
	int x = GetRandomValue(0, 100);

	if (x > 90) {
		return Rock;
	}
	if (x > 70) {
		return Grass;
	}
	else
	{
		return Dirt;
	}
}

