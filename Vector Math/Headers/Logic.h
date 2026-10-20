#pragma once
#include "Struct.h"
#include "../Math/Math.h"

inline void setUpEntities(vector<Entity>& e)
{
	e.push_back(Entity("Jamaal", true, Vec2{ 128, 37 }));
	e.push_back(Entity("Dummy", false, Vec2{ 72, 50 }));
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

inline void moveEntity(const Entity& pLocal, const Entity& pEnemy, Vec2 delta)
{
	clear();

	cout << "Moving Entity..." << endl;
	pause();

	while (delta.x > 0 && delta.y > 0)
	{
		clear();

		float distanceMeters = getDistance(delta);
		delta.x -= 5;
		delta.y -= 5;

		cout << pEnemy.getName() << " is Moving Towards " << pLocal.getName() << endl;
		cout << "Distance: " << distanceMeters << "[m]" << endl;
		pause();

		if (GetAsyncKeyState(VK_SPACE))
		{
			return;
		}
	}
}

inline void printInfo(const Entity& pLocal, const Entity& pEnemy)
{
	clear();

	Vec2 delta = getDelta(pLocal, pEnemy);
	float distanceMeters = getDistance(delta);

	cout << "Vector Math" << endl;
	space();

	cout << "Player Position: (" << pLocal.pos.x << ", " << pLocal.pos.y << ")" << endl;
	cout << "Enemey Position: (" << pEnemy.pos.x << ", " << pEnemy.pos.y << ")" << endl;
	space();

	cout << "Delta X: " << delta.x << endl;
	cout << "Delta Y: " << delta.y << endl;
	space();

	cout << "Distance: " << fixed << setprecision(2) << distanceMeters << "[m]" << endl;;
	getKey();

	moveEntity(pLocal, pEnemy, delta);

}
