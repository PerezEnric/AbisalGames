#ifndef __ModuleInput_H__
#define __ModuleInput_H__

#include "Module.h"
#include "Globals.h"
#include "SDL\include\SDL_scancode.h"
#include "SDL\include\SDL.h"
#include "SDL\include\SDL_gamecontroller.h"


#define MAX_KEYS 200
#define MAX_BUTTONS 4
#define MAX_GAMEPADS 1

enum KEY_STATE
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

enum BUTTONS {

	BUTTON_A
};

class ModuleInput : public Module
{
public:

	ModuleInput();
	~ModuleInput();

	bool Init();
	update_status PreUpdate();
	bool CleanUp();

public:
	KEY_STATE keyboard[MAX_KEYS];
	SDL_Event ev;
	bool controller_state[MAX_BUTTONS];
	KEY_STATE controller[MAX_BUTTONS];
	SDL_GameController* gamepads[MAX_GAMEPADS] = { nullptr };


	struct ControllerDir
	{
		bool up = false;
		bool down = false;
		bool right = false;
		bool left = false;
		Sint16 axisX = 0;
		Sint16 axisY = 0;
		int deadzone = 8000;
	};


	ControllerDir GamepadDir[MAX_GAMEPADS];
};

#endif // __ModuleInput_H__