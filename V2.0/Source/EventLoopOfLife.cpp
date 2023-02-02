#include "EventLoopOfLife.h"

EventLoopOfLife::EventLoopOfLife(int _screenWidth, int _screenHeight)
{
	screenSize.x = (float)_screenWidth;
	screenSize.y = (float)_screenHeight;

	sheepManager = SheepManager::GetInstance();
	tileManager = TileManager::GetInstance();
	
}

EventLoopOfLife::~EventLoopOfLife()
{
}

void EventLoopOfLife::Run()
{
	Update();
	Render();
}

void EventLoopOfLife::Update()
{
	tileManager->Instance->Update();
	sheepManager->Instance->Update();
	ma.Update();
}

void EventLoopOfLife::Render()
{
	ClearBackground(BLACK);

	tileManager->Render();
	sheepManager->Render();
	ma.Render();
}
