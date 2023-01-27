#pragma once
#include "SheepManager.h"

class Game
{
public:
	Game();
	~Game();

	void Update();
	void Draw();

	SheepManager* sm;

private:

};

