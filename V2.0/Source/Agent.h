#pragma once
#include "Core.h"

class Agent
{
public:
	Agent();
	~Agent();

	virtual void Update() = 0;
	virtual void Render() = 0;

protected:
	virtual void Sense() = 0;
	virtual void Decide() = 0;
	virtual void Act() = 0;

	Vector2 _Position;
	Vector2 _Energy;

private:

	void Timer();

};

