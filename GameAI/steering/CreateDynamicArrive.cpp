#include"Game.h"
#include "UnitManager.h"
#include "GameMessageManager.h"
#include "CreateDynamicArrive.h"

CreateDynamicArrive::CreateDynamicArrive(const Vector2D& pos) : GameMessage(CREATE_DYNAMIC_ARRIVE_UNIT_MESSAGE)
{
	mPos = pos;
}

CreateDynamicArrive::~CreateDynamicArrive()
{

}

void CreateDynamicArrive::process()
{
	UNIT_MANAGER->createDynamicArriveUnit(mPos);
}