#pragma once
#include "GameMessage.h"
#include "Vector2D.h"
class Vector2D;

class CreateDynamicArrive : public GameMessage
{
public: 
	CreateDynamicArrive(const Vector2D& pos);
	~CreateDynamicArrive();
	void process();

private:
	Vector2D mPos;
};