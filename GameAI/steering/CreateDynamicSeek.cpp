#include "Game.h"
#include "UnitManager.h"
#include "GameMessageManager.h"
#include "CreateDynamicSeek.h"

CreateDynamicSeek::CreateDynamicSeek(const Vector2D& pos):GameMessage(CREATE_DYNAMIC_SEEK_MESSAGE)
{
	mPos = pos;
}

CreateDynamicSeek::~CreateDynamicSeek()
{

}

void CreateDynamicSeek::process()
{
	UNIT_MANAGER->createDynamicSeekUnit(mPos);
}