#pragma once
#include "TileMap.h"

class EventLoopOfLife
{
public:
	EventLoopOfLife();
	~EventLoopOfLife();

	void Draw();

private:

	void Update();
	void Render();

	TileMap tm;

};

