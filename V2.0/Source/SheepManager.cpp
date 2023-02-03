#include "SheepManager.h"

SheepManager* SheepManager::Instance = nullptr;

SheepManager::SheepManager()
{
    isHitBox = false;
    sheepTexture = LoadTexture("Assets/Sheep.png");

    totalSheep = 10;

    for (int i = 0; i < totalSheep; i++) {
        sheepList.push_back(new Sheep());
    }
}

SheepManager* SheepManager::GetInstance()
{
	if (!Instance)
		Instance = new SheepManager;
	return Instance;
}

void SheepManager::Update()
{
    for (Sheep* s : sheepList) {
        if (!s->IsActive)
            continue;
        s->Update();
    }

    RemoveDead();
}

void SheepManager::Render()
{
    for (Sheep* s : sheepList) {
        if (!s->IsActive)
            continue;
        s->Render();
        DrawTexture(sheepTexture, (int)s->GetPosition().x, (int)s->GetPosition().y, RAYWHITE);
    }

    DrawHitBox();
}

void SheepManager::RemoveDead()
{
    for (Sheep* s : sheepList) {
        if (!s->IsActive)
            continue;
        if (s->IsDead) 
        {
            s->IsActive = false;
        }
    }
}

void SheepManager::DrawHitBox()
{
    if (IsKeyPressed(KEY_SPACE))
        isHitBox = (isHitBox) ? false : true;

    if (isHitBox) {
        for (Sheep* s : sheepList) {
            if (!s->IsActive)
                continue;
            DrawRectangle((int)s->GetPosition().x, (int)s->GetPosition().y, sheepTexture.width, sheepTexture.height, RED);
        }

    }
}

SheepManager::~SheepManager()
{

}