#include "Game.h"
#include "GraphicsSystem.h"
#include "GameMessageManager.h"
#include "DrawTextMessage.h"

DrawtextMessage::DrawtextMessage(float red, float green, float blue, float mouseX, float mouseY, std::string mousePos) : GameMessage(DRAW_TEXT_MESSAGE)
{
	mRed = red; mGreen = green; mBlue = blue;
	mMouseX = mouseX; mMouseY = mMouseY;
	mMousePos = mousePos;
}

DrawtextMessage::~DrawtextMessage()
{

}
void DrawtextMessage::process()
{
	GRAPHICS_SYSTEM->drawPointerText(mRed, mGreen, mBlue, mMouseX, mMouseY, mMousePos);
}