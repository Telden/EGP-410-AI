#pragma once
#ifndef UNITMANAGER_H
#define UNITMANAGER_H

#include "Trackable.h"
#include <vector>

#include "KinematicUnit.h"


class UnitManager : public Trackable
{
private:
	std::vector<KinematicUnit*> mpUnits;
public:
	UnitManager();
	~UnitManager();

	void addUnit(KinematicUnit* newUnit);
	void createUnit();
	void updateUnits(float time);
	void cleanup();

};
#endif 