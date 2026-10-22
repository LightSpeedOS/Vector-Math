#pragma once
#include "../Headers/Struct.h"

Vec2 getDelta(const Entity& p, const Entity& e);

float getDistance(const Vec2& delta);

void checkRange(const Entity& pLocal, const Entity& pEnemy);

void printRange(float d);

float getAngle(const Vec2& delta);

