#pragma once
#include "Core.h"
#include "TileManager.h"
#include <iostream>

class MouseAction
{
public:
	MouseAction();
	~MouseAction();

	void Update();
	void Render();

	TileManager* tm;
	Tile selectedTile;
	bool selected;

private:

};
