#include "Game.h"

Game::Game()
{
	sm = SheepManager::GetInstance();
	tm = TileManager::GetInstance();
}

Game::~Game()
{
}

void Game::Play()
{
	Update();
	Render();
}

void Game::Update() {
	tm->Update();
	sm->Update();
}

void Game::Render() {
	tm->Render();
	sm->Render();
	
}