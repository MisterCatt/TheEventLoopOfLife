#pragma once
#include "Core.h"
#include <iostream>
#include "TileManager.h"
#include "MouseAction.h"
#include "SheepManager.h"

class EventLoopOfLife
{
public:
	EventLoopOfLife(int _screenWidth = 800, int _screenHeight = 800);
	~EventLoopOfLife();

	void Run();

private:

	Vector2 screenSize;

	void Update();
	void Render();

	SheepManager* sheepManager;
	TileManager* tileManager;

	MouseAction ma;

};

