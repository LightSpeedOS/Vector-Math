#include "Headers/Includes.h"
#include "Headers/Logic.h"
#include "Headers/Struct.h"
#include "Math/Math.h"

auto main() -> int
{
	vector<Entity> entities;
	setUpEntities(entities);

	Entity* pLocalPlayer = getLocalPlayer(entities);
	Entity* pEnemy = getEnemy(entities);

	printInfo(*pLocalPlayer, *pEnemy);
}