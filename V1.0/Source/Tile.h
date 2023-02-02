#pragma once
#include "Core.h"
#include "Agent.h"
#include <iostream>

class Tile : public Agent
{
public:
	Tile();
	~Tile();

	float energy;

	int type;

	bool multiplying;
	bool trampled;
	bool eaten;

	Rectangle GetTile();

	void Update();

	void Sense();
	void Decide();
	void Act();

private:

	Rectangle tile;

	
};

