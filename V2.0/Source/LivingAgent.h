#pragma once
#include "Agent.h"
class LivingAgent : public Agent
{
public:
	LivingAgent();
	~LivingAgent();

	virtual void Eat() = 0;
	virtual void Breed() = 0;
	virtual void Wander() = 0;

	float Hp;
	bool IsDead;

private:

};

