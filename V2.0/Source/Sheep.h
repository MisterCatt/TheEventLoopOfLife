#pragma once
#include "LivingAgent.h"

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

	

private:


};

