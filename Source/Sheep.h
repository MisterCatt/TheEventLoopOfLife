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

	void Update();

	float energy;

	enum class Behaviour {Idle, Running} sheepBehaviour;

private:

	void Idle();
	void Run();

};

