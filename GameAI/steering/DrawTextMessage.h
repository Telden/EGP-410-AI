#pragma once
#include "GameMessage.h"


class DrawtextMessage : public GameMessage
{
private:
	float mRed, mGreen, mBlue, mMouseX, mMouseY;
	std::string mMousePos;
public:
	DrawtextMessage();
	DrawtextMessage(float red, float green, float blue, float mouseX, float mouseY, std::string mousePos);
	~DrawtextMessage();
	
	void process();
};