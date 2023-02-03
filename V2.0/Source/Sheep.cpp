#include "Sheep.h"

Sheep::Sheep()
{
	tm = TileManager::GetInstance();

	_Position = Vector2{ (float)GetRandomValue(0, GetScreenWidth()), (float)GetRandomValue(0, GetScreenHeight()) };

	descision = SheepDecision::Wander;

	_MovePoint = {(float)GetRandomValue(-50, 50),(float)GetRandomValue(-50, 50) };

	hungry = false;
}

Sheep::~Sheep()
{
}

void Sheep::Render() {
	DrawCircle(_MovePoint.x, _MovePoint.y, 10, RED);
}

void Sheep::Update()
{
	

	switch (state)
	{
	case Agent::AgentState::Sensing:
		Sense();
		break;
	case Agent::AgentState::Deciding:
		Decide();
		break;
	case Agent::AgentState::Acting:
		Act();
		break;
	default:
		break;
	}
	/*if (IsKeyDown(KEY_RIGHT)) {
		movePoint.x+=10;
	}
	if (IsKeyDown(KEY_UP)) {
		movePoint.y-=10;
	}
	if (IsKeyDown(KEY_LEFT)) {
		movePoint.x-=10;
	}
	if (IsKeyDown(KEY_DOWN)) {
		movePoint.y+=10;
	}*/

	Timer();
}

void Sheep::Sense()
{
	/*for (int x = 0; x < 20; x++)
	{
		for (int y = 0; y < 20; y++) 
		{
			
		}
	}*/

	//tile = tm->GetTile(10, 10);

	//std::cout << tile.GetTileType() << std::endl;

	state = AgentState::Deciding;
}

void Sheep::Decide()
{
	if (Hp <= 50) {
		hungry = true;
	}

	if (hungry) {
		descision = SheepDecision::Find;
	}
	else {
		descision = SheepDecision::Wander;
		_MovePoint = { (float)GetRandomValue(_Position.x - 100, _Position.x + 100),(float)GetRandomValue(_Position.y - 100, _Position.y + 100) };

	}

	
	state = AgentState::Acting;
}

void Sheep::Act()
{
	switch (descision)
	{
	case Sheep::SheepDecision::Evade:
		EvadeWolves();
		break;
	case Sheep::SheepDecision::Find:
		Find();
		break;
	case Sheep::SheepDecision::Eat:
		Eat();
		break;
	case Sheep::SheepDecision::Breed:
		Breed();
		break;
	case Sheep::SheepDecision::Wander:
		Wander();
		break;
	default:
		break;
	}

	switch (_ShouldSense)
	{
	case true:
		state = AgentState::Sensing;
		_ShouldSense = false;
		break;
	default:
		state = AgentState::Acting;
		break;
	}
	Hp -= 0.2f;
}

void Sheep::EvadeWolves()
{
}

void Sheep::Find()
{
	
}

void Sheep::Eat()
{
	Hp += 50;

	if (Hp > 100)
		Hp = 100;
}

void Sheep::Breed()
{
}

void Sheep::Wander()
{
	
	_Position = MoveTowards(_MovePoint, _Position, 0.5f);
}




