#include "LivingAgent.h"

LivingAgent::LivingAgent()
{
	Hp = 100;
	IsDead = false;
}

LivingAgent::~LivingAgent()
{
}

Vector2 LivingAgent::MoveTowards(Vector2 _target, Vector2 _current, float maxDelta)
{
	Vector2 a;

	a.x = _MovePoint.x - _Position.x;
	a.y = _MovePoint.y - _Position.y;

	float magnitude = sqrt(pow(a.x, 2) + pow(a.y, 2));

	//float magnitude = ((a.x * a.x) + (a.y * a.y));

	if (magnitude <= 5 || magnitude == 0) {
		return _target;
	}

	Vector2 b;

	b.x = a.x / magnitude;
	b.y = a.y / magnitude;

	b.x *= maxDelta;
	b.y *= maxDelta;

	b.x = _current.x + b.x;
	b.y = _current.y + b.y;

	return b;
}