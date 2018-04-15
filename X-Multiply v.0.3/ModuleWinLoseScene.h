#ifndef __ModuleWinLoseScreen_H__
#define __ModuleWinLoseScreen_H__

#include "Module.h"
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment(lib, "SDL_mixer/libx86/SDL2_mixer.lib")

struct SDL_Texture;

class ModuleWinLoseScreen : public Module
{
public:
	ModuleWinLoseScreen();
	~ModuleWinLoseScreen();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Rect winimg;
	SDL_Rect loseimg;
};





#endif