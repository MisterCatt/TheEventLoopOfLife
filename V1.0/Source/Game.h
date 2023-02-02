#pragma once
#include "SheepManager.h"
#include "TileManager.h"

class Game
{
public:
	Game();
	~Game();

	void Play();

private:
	void Update();
	void Render();

	SheepManager* sm;
	TileManager* tm;

};

