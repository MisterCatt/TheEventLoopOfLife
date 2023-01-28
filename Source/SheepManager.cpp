#include "SheepManager.h"

SheepManager* SheepManager::Instance = nullptr;

SheepManager::SheepManager()
{
    isHitBox = false;
    sheepTexture = LoadTexture("Assets/Sheep.png");

    totalSheep = 10;

    for (int i = 0; i < totalSheep; i++) {
        sheep.push_back(new Sheep());
    }
}

SheepManager::~SheepManager()
{
}

SheepManager* SheepManager::GetInstance() 
{
    if (!Instance)
        Instance = new SheepManager;
    return Instance;
}

void SheepManager::Render() 
{
    for (Sheep* s : sheep) {
        if (s->isActive) {
            DrawTexture(sheepTexture,(int)s->GetPosition().x, (int)s->GetPosition().y,RAYWHITE);
        }
    }

    DrawHitBox();
}

void SheepManager::Update()
{
    for (Sheep* s : sheep) {
        if (s->dead) {
            s->isActive = false;
        }
    }
}

void SheepManager::RemoveDead() 
{
    for (Sheep* s : sheep) {
        if (s->dead) {
            s->isActive = false;
        }
    }
}

void SheepManager::DrawHitBox()
{
    if (IsKeyPressed(KEY_SPACE))
        isHitBox = (isHitBox) ? false : true;
       
    if (isHitBox) {
        for (Sheep* s : sheep) {
            if (s->isActive) {
                DrawRectangle((int)s->GetPosition().x, (int)s->GetPosition().y, sheepTexture.width, sheepTexture.height, RED);
            }
        }

    }
}
