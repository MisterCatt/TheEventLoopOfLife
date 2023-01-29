#pragma once
#include "Core.h"
#include "SheepManager.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

private:

	enum class AgentState {Sensing, Deciding, Acting} aState;

	SheepManager* sm;

};

