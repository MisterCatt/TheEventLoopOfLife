#pragma once
#include "Core.h"
#include <list>
#include "Sheep.h"
#include <iostream>

class SheepManager
{
public:
	static SheepManager* Instance;

	static SheepManager* GetInstance();

	void Update();
	void Render();

	void RemoveDead();

	void DrawHitbox();

	std::list<Sheep*> sheepList;

	~SheepManager();

private:
	SheepManager();

	void DrawHitBox();

	int totalSheep;

	Texture sheepTexture;

	bool isHitBox;
};

