#include "UnitManager.h"
#include "Sprite.h"
#include "SpriteManager.h"
#include "Game.h"
#include "KinematicUnit.h"

UnitManager::UnitManager()
{
	mpEnemySprite = SPRITE_MANAGER->getSprite(AI_ICON_SPRITE_ID);
}

UnitManager::~UnitManager()
{
	cleanup();
}

void UnitManager::addUnit(KinematicUnit* newUnit)
{
	mpUnits.push_back(newUnit);
}

void UnitManager::createDynamicArriveUnit(const Vector2D& pos)
{
	Vector2D mPos = pos;
	mPos.setX(mPos.getX() + 200);
	Vector2D vel(0.0f, 0.0f);
	KinematicUnit* mpAIUnit = new KinematicUnit(mpEnemySprite, mPos, 1, vel, 0.0f, 180.0f, 100.0f);
	mpAIUnit->dynamicArrive(mpUnits[0]);
	addUnit(mpAIUnit);
	mpAIUnit = NULL;
}

void UnitManager::createDynamicSeekUnit(const Vector2D& pos)
{
	Vector2D mPos = pos;
	mPos.setX(mPos.getX() - 100);
	Vector2D vel(0.0f, 0.0f);
	KinematicUnit* mpAIUnit = new KinematicUnit(mpEnemySprite, mPos, 1, vel, 0.0f, 180.0f, 100.0f);
	mpAIUnit->dynamicSeek(mpUnits[0]);
	mpAIUnit = NULL;
}

void UnitManager::deleteUnit()
{
	//http://www.cplusplus.com/reference/cstdlib/rand/
}

void UnitManager::updateUnits(float time)
{
	for (int i = 0; i < mpUnits.size(); i++)
	{
		mpUnits[i]->update(time);
	}
}

void UnitManager::cleanup()
{

	for (int i = 0; i < mpUnits.size(); i++)
	{
		delete mpUnits[i];

	}
}