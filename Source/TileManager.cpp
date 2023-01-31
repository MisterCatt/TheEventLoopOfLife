#include "TileManager.h"

TileManager* TileManager::Instance = nullptr;

TileManager::TileManager()
{
	
}

TileManager::~TileManager()
{
}

void TileManager::Render() 
{
	tm.DrawTiles();
}

void TileManager::Update() {
    tm.Update();
}

TileManager* TileManager::GetInstance()
{
    if (!Instance)
        Instance = new TileManager;
    return Instance;
}

Rectangle TileManager::GetTile(int x, int y) 
{
    return Rectangle{(float)x,(float)y, (float)x+20,(float)y+20};
}