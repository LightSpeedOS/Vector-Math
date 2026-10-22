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

void printRange(float d)
{
    
    Range currentRange = Range::CLOSE;

    if (d >= 5.0f) currentRange = Range::LONG_RANGE;
    else if (d >= 2.0f) currentRange = Range::MEDIUM;

    switch (currentRange)
    {
    case Range::CLOSE:
        cout << "CLOSE" << endl;
        break;

    case Range::MEDIUM:
        cout << "Medium" << endl;
        break;

    case Range::LONG_RANGE:
        cout << "Far" << endl;
        break;
    }

}

void checkRange(const Entity& pLocal, const Entity& pEnemy)
{
    clear();

    cout << "Player: (" << pLocal.pos.x << ", " << pLocal.pos.y << ")" << endl;
    cout << "Enemy: (" << pEnemy.pos.x << ", " << pEnemy.pos.y << ")" << endl;
    space();

    Vec2 delta = getDelta(pLocal, pEnemy);
    float distance = getDistance(delta);

    cout << "Distance: " << distance << "[m]" << endl;
    cout << "Range: "; printRange(distance);
    getKey();
} 

float getAngle(const Vec2& delta)
{
    constexpr float PI = 3.14159f;

    float angle = atan2(delta.y, delta.x);
    float degrees = angle * (180.0f / PI);

    if (degrees < 0) degrees += 360.0f;

    return degrees;
}
