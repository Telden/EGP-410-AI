#pragma once

#include  "GameMessage.h"
#include "Vector2D.h"
class Vector2D;

class CreateDynamicSeek : public GameMessage
{
public:
	CreateDynamicSeek(const Vector2D& pos);
	~CreateDynamicSeek();
	void process();

private:
	Vector2D mPos;
};