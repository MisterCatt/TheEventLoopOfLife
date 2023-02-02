#pragma once
#include "LivingAgent.h"
#include <cmath>

class Sheep : public LivingAgent
{
public:
	Sheep();
	~Sheep();

	void Update();

	void Sense();
	void Decide();
	void Act();

	void EvadeWolves();
	void Find();
	void Eat();
	void Breed();
	void Wander();

	enum class SheepDecision { Evade, Find, Eat, Breed, Wander} descision;

private:

	

};

