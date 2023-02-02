#include "EventLoopOfLife.h"

EventLoopOfLife::EventLoopOfLife(int _screenWidth, int _screenHeight)
{
	screenSize.x = (float)_screenWidth;
	screenSize.y = (float)_screenHeight;

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

void EventLoopOfLife::SetWindowSize(int _screenWidth, int _screenHeight)
{
	screenSize.x = (float)_screenWidth;
	screenSize.y = (float)_screenHeight;
}

void EventLoopOfLife::SetWindowSize(Vector2 _screenSize)
{
	screenSize = _screenSize;
}

void EventLoopOfLife::SetWindowWidth(int _screenWidth)
{
	screenSize.x = (float)_screenWidth;
}

void EventLoopOfLife::SetWindowHeight(int _screenHeight)
{
	screenSize.y = (float)_screenHeight;
}

Vector2 EventLoopOfLife::GetWindowSize()
{
	return screenSize;
}

int EventLoopOfLife::GetWindowWidth()
{
	return (int)screenSize.x;
}

int EventLoopOfLife::GetWindowHeight()
{
	return (int)screenSize.y;
}

void EventLoopOfLife::Update()
{
	tileManager->Instance->Update();
	ma.Update();
}

void EventLoopOfLife::Render()
{
	ClearBackground(BLACK);

	tileManager->Render();
	ma.Render();
}
