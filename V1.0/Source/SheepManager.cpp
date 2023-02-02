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

    activeSheep = sheep;
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
    for (Sheep* s : activeSheep) {
        DrawTexture(sheepTexture,(int)s->GetPosition().x, (int)s->GetPosition().y,RAYWHITE);
    }

    DrawHitBox();
}

void SheepManager::Update()
{
    for (Sheep* s : activeSheep) {
        if (s->dead) {
            s->isActive = false;
        }
        else {
            s->Update();
        }
    }

    RemoveDead();
}

void SheepManager::RemoveDead() 
{
    for (Sheep* s : activeSheep) {
        if (s->dead) {
            s->isActive = false;
            activeSheep.remove(s);
        }
    }
}

void SheepManager::DrawHitBox()
{
    if (IsKeyPressed(KEY_SPACE))
        isHitBox = (isHitBox) ? false : true;
       
    if (isHitBox) {
        for (Sheep* s : activeSheep) {
            DrawRectangle((int)s->GetPosition().x, (int)s->GetPosition().y, sheepTexture.width, sheepTexture.height, RED);
        }

    }
}
