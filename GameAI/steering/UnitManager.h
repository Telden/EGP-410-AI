#pragma once
#ifndef UNITMANAGER_H
#define UNITMANAGER_H

#include "Trackable.h"
#include <vector>


class Sprite;
class KinematicUnit;

class UnitManager : public Trackable
{
private:
	std::vector<KinematicUnit*> mpUnits;
	Sprite* mpEnemySprite;
	const IDType AI_ICON_SPRITE_ID = 2;
public:
	UnitManager();
	~UnitManager();

	void addUnit(KinematicUnit* newUnit);
	void createDynamicArriveUnit(const Vector2D& pos);
	void createDynamicSeekUnit(const Vector2D& pos);
	void deleteUnit();
	void updateUnits(float time);
	void cleanup();

};
#endif 