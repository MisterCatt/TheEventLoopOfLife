#include "SheepManager.h"


SheepManager* SheepManager::Instance = nullptr;

SheepManager::SheepManager()
{
    sheep.push_back(new Sheep());
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
            DrawCircle(s->position.x, s->position.y, 50, BLUE);
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