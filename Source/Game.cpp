#include "Game.h"

Game::Game()
{
	sm = SheepManager::GetInstance();
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
	sm->Update();
}

void Game::Render() {
	sm->Render();
}