#include "Agent.h"

Agent::Agent()
{
	_ShouldSense = false;
	_Energy = 0;
	_Position = { 0,0 };

	IsActive = true;

	time = 0;

	state = AgentState::Sensing;
}

Agent::~Agent()
{
}

void Agent::Timer()
{
	
	if (!_ShouldSense) {
		time ++;		

		if (time >= (60*0.25)) {
			
			_ShouldSense = true;
			time = 0;
		}
	}
}

Vector2 Agent::GetPosition()
{
	return _Position;
}

void Agent::SetPosition(Vector2 _Pos)
{
	_Position = _Pos;
}

float Agent::GetEnergy()
{
	return _Energy;
}
