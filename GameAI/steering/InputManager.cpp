#include "InputManager.h"
#include "Defines.h"
#include <sstream>
#include <stdio.h>
#include <allegro5/allegro.h>
#include "GameMessageManager.h"
#include "GameMessage.h"
#include "PlayerMoveToMessage.h"
#include "DrawTextMessage.h"
#include "Game.h"

InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

bool InputManager::init()
{
	//should probably be done in the InputSystem!
	if (!al_install_keyboard())
	{
		printf("Keyboard not installed!\n");
		return false;
	}

	//should probably be done in the InputSystem!
	if (!al_install_mouse())
	{
		printf("Mouse not installed!\n");
		return false;
	}
}


bool InputManager::checkInput()
{
	al_get_mouse_state(&mouseState);

	if (al_mouse_button_down(&mouseState, 1))//left mouse click
	{
		Vector2D pos(mouseState.x, mouseState.y);
		GameMessage* pMessage = new PlayerMoveToMessage(pos);
		MESSAGE_MANAGER->addMessage(pMessage, 0);
	}

	//all this should be moved to InputManager!!!
	{
		//get mouse state

		al_get_mouse_state(&mouseState);

		//create mouse text
		std::stringstream mousePos;
		mousePos << mouseState.x << ":" << mouseState.y;

		GameMessage* pMessage = new DrawtextMessage(255, 255, 255, mouseState.x, mouseState.y, mousePos.str());
		MESSAGE_MANAGER->addMessage(pMessage, 0);

		//get current keyboard state
		al_get_keyboard_state(&keyState);


		//if escape key was down then exit the loop
		if (al_key_down(&keyState, ALLEGRO_KEY_ESCAPE))
		{
			mShouldExit = true;
		}

		return mShouldExit;
	}
}