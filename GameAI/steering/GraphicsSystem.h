#pragma once

#include <allegro5/allegro.h>
#include "Trackable.h"
#include "Vector2D.h"

class GraphicsBuffer;

class GraphicsSystem:public Trackable
{
public:
	GraphicsSystem();
	~GraphicsSystem();

	bool init( int width, int height );
	void cleanup();

	void swap();
	void wrapCoordinates( Vector2D& vector );//change the x and y values in the vector to keep them on the visible screen
	void drawPointerText(float red, float green, float blue, float mouseX, float mouseY, std::string mousePos);

	//accessors
	int getWidth() const { return mWidth; };
	int getHeight() const { return mHeight; };
	ALLEGRO_DISPLAY* getDisplay() const { return mpDisplay; };
	inline GraphicsBuffer* getBackBuffer() { return mpBackBuffer; };

	static ALLEGRO_BITMAP* switchTargetBitmap( ALLEGRO_BITMAP* pNewTarget );//return old target

private:
	ALLEGRO_DISPLAY* mpDisplay;
	GraphicsBuffer* mpBackBuffer;
	ALLEGRO_FONT* mpFont;
	int mWidth;
	int mHeight;
};