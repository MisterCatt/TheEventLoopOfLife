#include "Game.h"

Game::Game()
{
	sm = SheepManager::GetInstance();
}

Game::~Game()
{
}

void Game::Update() {
	
}

void Game::Draw() {
	sm->Render();
}