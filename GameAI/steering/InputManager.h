#pragma once
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "Trackable.h"

class InputManager : public Trackable
{
private:
	ALLEGRO_MOUSE_STATE mouseState;
	ALLEGRO_KEYBOARD_STATE keyState;
	bool mShouldExit = false;
public:
	InputManager();
	~InputManager();
	bool checkInput();
	bool init();
};
#endif // !INPUTMANAGER_H