#pragma once
#include "Includes.h"

struct Vec2
{
	float x, y;
};

class Entity
{
private:
	string name;

public:
	bool isLocal = false;
	Vec2 pos;

	Entity(const string& n,bool l, Vec2 p)
	{
		name = n;
		isLocal = l;
		pos = p;
	}

	string getName() const
	{
		return name;
	}
};