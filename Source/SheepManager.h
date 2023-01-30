#pragma once
#include "Sheep.h"
#include <iostream>

class SheepManager
{
public:

	static SheepManager* Instance;

	static SheepManager* GetInstance();

	~SheepManager();

	std::list<Sheep*> sheep;
	std::list<Sheep*> activeSheep;

	void Render();
	void Update();

	void RemoveDead();

	void DrawHitBox();

private:
	SheepManager();

	int totalSheep;

	Texture2D sheepTexture;

	bool isHitBox;
};

