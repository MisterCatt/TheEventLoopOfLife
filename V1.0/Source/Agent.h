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

	virtual void Update() = 0;

	void Timer();

	bool dead;
	bool isActive;
	bool shouldSense;

	float hp;

	virtual Vector2 GetPosition();
	void SetPosition(int x, int y);
	void SetPosition(float x, float y);
	void SetPosition(Vector2 pos);

	enum class AgentState {Sensing, Deciding, Acting} state;

protected:

	Vector2 position;

private:
	float time;

};

