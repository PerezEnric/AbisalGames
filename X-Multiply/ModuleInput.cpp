#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "SDL/include/SDL.h"

ModuleInput::ModuleInput() : Module()
{

}

// Destructor
ModuleInput::~ModuleInput()
{}

// Called before render is available
bool ModuleInput::Init()
{
	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if (SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	//Controller

	LOG("Init controller");

	if (SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER) < 0)
	{
		LOG("GamePad controller could not initialize! SDL_Error: %s\n", SDL_GetError());
	}


	int maxJoys = SDL_NumJoysticks();


	for (int i = 0; i < maxJoys; ++i)

	{
		if (i >= MAX_GAMEPADS) break;

		if (SDL_IsGameController(i))
		{
			gamepads[i] = SDL_GameControllerOpen(i);
		}
	}

	return ret;
}

// Called every draw update
update_status ModuleInput::PreUpdate()
{
	SDL_PumpEvents();

	const Uint8* keys = SDL_GetKeyboardState(NULL);

	for (int i = 0; i < MAX_KEYS; ++i)
	{
		if (keys[i] == 1)
		{
			if (keyboard[i] == KEY_IDLE)
				keyboard[i] = KEY_DOWN;
			else
				keyboard[i] = KEY_REPEAT;
		}
		else
		{
			if (keyboard[i] == KEY_REPEAT || keyboard[i] == KEY_DOWN)
				keyboard[i] = KEY_UP;
			else
				keyboard[i] = KEY_IDLE;
		}
	}

	SDL_Event quit;

	SDL_PollEvent(&quit);

	if (quit.type == SDL_QUIT)
		return update_status::UPDATE_STOP;

	if (keyboard[SDL_SCANCODE_ESCAPE])
		return update_status::UPDATE_STOP;

	//Controller inputs : Button

	for (int i = 0; i < MAX_GAMEPADS; ++i)
	{
		if (gamepads[i] != nullptr)
		{
			controller_state[BUTTON_A] = SDL_GameControllerGetButton(gamepads[i], SDL_CONTROLLER_BUTTON_RIGHTSHOULDER);
			controller_state[BUTTON_START] = SDL_GameControllerGetButton(gamepads[i], SDL_CONTROLLER_BUTTON_START);
		}
	}

	for (int i = 0; i < MAX_BUTTONS; ++i)
	{
		if (controller_state[i] == 1) {
			if (controller[i] == KEY_IDLE)
				controller[i] = KEY_DOWN;
			else
				controller[i] = KEY_REPEAT;
		}
		else
		{
			if (controller[i] == KEY_REPEAT || controller[i] == KEY_DOWN)
				controller[i] = KEY_UP;
			else
				controller[i] = KEY_IDLE;
		}
	}
	


	if (ev.type == SDL_CONTROLLERDEVICEADDED)
	{
		if (ev.cdevice.which > MAX_GAMEPADS - 1)
		{
			LOG("Maximum number of gamepads reached, you cannot connect more...");

		}

		else if (SDL_IsGameController(ev.cdevice.which))
		{
			gamepads[ev.cdevice.which] = SDL_GameControllerOpen(ev.cdevice.which);
			LOG("Controller added: %d", ev.cdevice.which);
		}

	}

	// Controller inputs: Axis
	for (int i = 0; i < MAX_GAMEPADS; ++i)
	{
		if (gamepads[i] != nullptr)
		{
			GamepadDir[i].axisX = SDL_GameControllerGetAxis(gamepads[i], SDL_CONTROLLER_AXIS_LEFTX);
			GamepadDir[i].axisY = SDL_GameControllerGetAxis(gamepads[i], SDL_CONTROLLER_AXIS_LEFTY);
		}
	}


	if (GamepadDir[0].axisX > GamepadDir[0].deadzone)
	{
		keyboard[SDL_SCANCODE_D] = KEY_REPEAT;
	}

	else if (GamepadDir[0].axisX < -GamepadDir[0].deadzone)
	{
		keyboard[SDL_SCANCODE_A] = KEY_REPEAT;
	}


	if (GamepadDir[0].axisY < -GamepadDir[0].deadzone)
	{
		keyboard[SDL_SCANCODE_W] = KEY_REPEAT;
	}

	else if (GamepadDir[0].axisY > GamepadDir[0].deadzone)
	{
		keyboard[SDL_SCANCODE_S] = KEY_REPEAT;
	}

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);

	LOG("Quitting controllers");
	for (int i = 0; i < MAX_GAMEPADS; ++i)
	{
		if (gamepads[i] != nullptr)
			SDL_GameControllerClose(gamepads[i]);
		gamepads[i] = nullptr;
	}

	return true;
}