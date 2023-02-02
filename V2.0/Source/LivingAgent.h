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

	Vector2 MoveTowards(Vector2 _target, Vector2 _current, float maxDelta);

	float Hp;
	bool IsDead;

protected:

	Vector2 _MovePoint;

private:

};

