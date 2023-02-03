#pragma once
#include "TileManager.h"
#include "LivingAgent.h"
#include <cmath>
#include <iostream>

class Sheep : public LivingAgent
{
public:
	Sheep();
	~Sheep();

	void Update();
	void Render();

	void Sense();
	void Decide();
	void Act();

	void EvadeWolves();
	void Find();
	void Eat();
	void Breed();
	void Wander();

	enum class SheepDecision { Evade, Find, Eat, Breed, Wander} descision;

	Tile tile;
	TileManager* tm;

private:
	bool hungry;
	

};

