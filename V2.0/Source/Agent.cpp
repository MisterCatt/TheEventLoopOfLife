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
		time += GetFrameTime();

		if (time >= 250) {
			_ShouldSense = true;
			time = 0;
		}
	}
}

Vector2 Agent::GetPosition()
{
	return _Position;
}
