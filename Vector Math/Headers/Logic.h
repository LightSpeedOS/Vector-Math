#pragma once
#include "Struct.h"
#include "../Math/Math.h"

inline void setUpEntities(vector<Entity>& e)
{
	e.push_back(Entity("Jamaal", true, Vec2{ 128, 37 }));
	e.push_back(Entity("Dummy", false, Vec2{ 200, 10 }));
}

inline Entity* getLocalPlayer(vector<Entity>& entities)
{
	for (Entity& e : entities)
	{
		if (e.isLocal)
			return &e;
	}
	return nullptr;
}

inline Entity* getEnemy(vector<Entity>& entities)
{
	for (Entity& e : entities)
	{
		if (!e.isLocal)
			return &e;
	}
	return nullptr;
}

inline void moveXY(Entity& e, const Vec2& delta)
{
	if (delta.x > 0)
	{
		if (delta.x < 5)
			e.pos.x -= delta.x;
		else
			e.pos.x -= 5;
	}
	else if (delta.x < 0)
	{
		if (delta.x > -5)
			e.pos.x -= delta.x;
		else
			e.pos.x += 5;
	}

	if (delta.y > 0)
	{
		if (delta.y < 5)
			e.pos.y -= delta.y;
		else
			e.pos.y -= 5;
	}
	else if (delta.y < 0)
	{
		if (delta.y > -5)
			e.pos.y -= delta.y;
		else
			e.pos.y += 5;
	}
}

inline void moveEntity(const Entity& pLocal, Entity& pEnemy)
{
	clear();

	cout << "Moving Entity..." << endl;
	pause();

	Vec2 delta = getDelta(pLocal, pEnemy);
	float distanceMeters = getDistance(delta);

	while (distanceMeters > 0.01f)
	{
		clear();

		delta = getDelta(pLocal, pEnemy);
		distanceMeters = getDistance(delta);

		moveXY(pEnemy, delta);

		cout << pEnemy.getName() << " is Moving Towards " << pLocal.getName() << endl;
		cout << "Distance: " << distanceMeters << "[m]" << endl;
		space();
		cout << "Press Space To Return" << endl;
		pause();

		if (GetAsyncKeyState(VK_SPACE))
		{
			return;
		}
	}
}

inline void printInfo(const Entity& pLocal, Entity& pEnemy)
{
	clear();

	Vec2 delta = getDelta(pLocal, pEnemy);
	float distanceMeters = getDistance(delta);
	float degrees = getAngle(delta);

	cout << "Vector Math" << endl;
	space();

	cout << "Player Position: (" << pLocal.pos.x << ", " << pLocal.pos.y << ")" << endl;
	cout << "Enemey Position: (" << pEnemy.pos.x << ", " << pEnemy.pos.y << ")" << endl;
	space();

	cout << "Delta X: " << delta.x << endl;
	cout << "Delta Y: " << delta.y << endl;
	space();

	cout << "Distance: " << fixed << setprecision(2) << distanceMeters << "[m]" << endl;;
	cout << "Degrees: " << degrees << endl;
	getKey();

	moveEntity(pLocal, pEnemy);
	checkRange(pLocal, pEnemy);
}
