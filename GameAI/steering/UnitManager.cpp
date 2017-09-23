#include "UnitManager.h"

UnitManager::UnitManager()
{

}

UnitManager::~UnitManager()
{
	cleanup();
}

void UnitManager::addUnit(KinematicUnit* newUnit)
{
	mpUnits.push_back(newUnit);
}

void UnitManager::createUnit()
{

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