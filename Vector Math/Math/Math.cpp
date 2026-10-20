#include "Math.h"

Vec2 getDelta(const Entity& p, const Entity& e)
{
    Vec2 delta;

    delta.x = e.pos.x - p.pos.x;
    delta.y = e.pos.y - p.pos.y;

    return delta;
}

float getDistance(const Vec2& delta)
{
    constexpr float unitsPerMeters = 10.0f;

    float distance = sqrt((delta.x * delta.x) + (delta.y * delta.y));

    float distanceMeters = distance / unitsPerMeters;

    return distanceMeters;
}
