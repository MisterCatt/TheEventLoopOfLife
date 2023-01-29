#include "GameManager.h"

GameManager::GameManager()
{
	sm = SheepManager::GetInstance();

	aState = AgentState::Sensing;
}

GameManager::~GameManager()
{
}