#pragma once
#include "Agent.h"

class Sheep : public Agent
{
public:
	Sheep();
	~Sheep();

	void Sense();
	void Decide();
	void Act();

	float energy;

private:

	void Idle();
	void Run();



};

