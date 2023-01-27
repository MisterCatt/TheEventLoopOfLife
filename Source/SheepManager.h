#pragma once
#include "Core.h"
#include "Sheep.h"

class SheepManager
{
public:

	static SheepManager* Instance;

	static SheepManager* GetInstance();

	~SheepManager();

	std::list<Sheep*> sheep;

	void Render();
	void Update();

	void RemoveDead();

private:
	SheepManager();

	//Texture2D sheepTexture;
};

