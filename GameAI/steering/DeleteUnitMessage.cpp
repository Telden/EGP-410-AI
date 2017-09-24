#include "Game.h"
#include "UnitManager.h"
#include "GameMessageManager.h"
#include "DeleteUnitMessage.h"

DeleteUnitMessage::DeleteUnitMessage() :GameMessage(DELETE_UNIT_MESSAGE)
{

}

DeleteUnitMessage::~DeleteUnitMessage()
{

}

void DeleteUnitMessage::process()
{
	UNIT_MANAGER->deleteUnit();
}