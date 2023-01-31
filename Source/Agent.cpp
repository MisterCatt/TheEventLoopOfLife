#include "Agent.h"

Agent::Agent()
{
	position = Vector2{(float)GetRandomValue(0,GetScreenWidth()),(float)GetRandomValue(0,GetScreenHeight())};
	dead = false;
	isActive = true;
	shouldSense = true;

	hp = 100;

	time = 0;

	state = AgentState::Sensing;
}

Agent::~Agent()
{
}

void Agent::Timer()
{
	if (!shouldSense) {
		time += GetFrameTime();

		if (time >= 250) {
			shouldSense = true;
			time = 0;
		}
	}
}

Vector2 Agent::GetPosition()
{
	return position;
}

void Agent::SetPosition(int x, int y) 
{
	position = { (float)x, (float)y };
}
void Agent::SetPosition(float x, float y)
{
	position = { x, y };
}
void Agent::SetPosition(Vector2 pos) 
{
	position = pos;
}