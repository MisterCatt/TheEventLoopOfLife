#include "EventLoopOfLife.h"

EventLoopOfLife::EventLoopOfLife(int _screenWidth, int _screenHeight)
{
	screenSize.x = _screenWidth;
	screenSize.y = _screenHeight;
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
	screenSize.x = _screenWidth;
	screenSize.y = _screenHeight;
}

void EventLoopOfLife::SetWindowSize(Vector2 _screenSize)
{
	screenSize = _screenSize;
}

void EventLoopOfLife::SetWindowWidth(int _screenWidth)
{
	screenSize.x = _screenWidth;
}

void EventLoopOfLife::SetWindowHeight(int _screenHeight)
{
	screenSize.y = _screenHeight;
}

Vector2 EventLoopOfLife::GetWindowSize()
{
	return screenSize;
}

int EventLoopOfLife::GetWindowWidth()
{
	return screenSize.x;
}

int EventLoopOfLife::GetWindowHeight()
{
	return screenSize.y;
}

void EventLoopOfLife::Update()
{
	std::cout << "Updating" << std::endl;
}

void EventLoopOfLife::Render()
{
	ClearBackground(BLACK);

	std::cout << "Rendering" << std::endl;
}
