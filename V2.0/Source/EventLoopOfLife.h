#pragma once
#include "Core.h"
#include <iostream>
#include "TileManager.h"
#include "MouseAction.h"

class EventLoopOfLife
{
public:
	EventLoopOfLife(int _screenWidth = 800, int _screenHeight = 800);
	~EventLoopOfLife();

	void Run();
	void SetWindowSize(int _screenWidth, int _screenHeight);
	void SetWindowSize(Vector2 _screenSize);
	void SetWindowWidth(int _screenWidth);
	void SetWindowHeight(int _screenHeight);

	Vector2 GetWindowSize();
	int GetWindowWidth();
	int GetWindowHeight();

private:

	Vector2 screenSize;

	void Update();
	void Render();

	TileManager* tileManager;
	MouseAction ma;

};

