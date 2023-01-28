#pragma once
#include "Core.h"

class Agent
{
public:
	Agent();
	~Agent();

	virtual void Sense() = 0;
	virtual void Decide() = 0;
	virtual void Act() = 0;

	bool dead;
	bool isActive;

	float hp;

	virtual Vector2 GetPosition();

protected:

	Vector2 position;

};

