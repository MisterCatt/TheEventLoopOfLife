#pragma once
#include "Core.h"

class Agent
{
public:
	Agent();
	~Agent();

	virtual void Update() = 0;

	virtual void Sense() = 0;
	virtual void Decide() = 0;
	virtual void Act() = 0;

	void Timer();
	Vector2 GetPosition();
	void SetPosition(Vector2 _Pos);

	float GetEnergy();

	enum class AgentState { Sensing, Deciding, Acting } state;

	bool IsActive;

protected:
	
	Vector2 _Position;
	float _Energy;
	bool _ShouldSense;

private:
	float time;
};

