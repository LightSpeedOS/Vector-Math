#pragma once
#include "Struct.h"

inline void setUpEntities(vector<Entity>& e)
{
	e.push_back(Entity("Jamaal", true, Vec2{ 128, 37 }));
	e.push_back(Entity("Dummy", false, Vec2{ 72, 50 }));
}

inline Entity* getLocalPlayer(vector<Entity>& entities)
{
	for (Entity& e : entities)
	{
		if (e.isLocal == true)
			return &e;
	}
}