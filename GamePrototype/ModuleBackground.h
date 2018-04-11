#ifndef __ModuleBackground_H__
#define __ModuleBackground_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment(lib, "SDL_mixer/libx86/SDL2_mixer.lib")
struct SDL_Texture;

class ModuleBackground : public Module
{
public:
	ModuleBackground();
	~ModuleBackground();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	
	Mix_Music* firstlvlmusic = nullptr;
	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphicswall = nullptr;
	SDL_Texture* graphicswall2 = nullptr;
	Animation back;
	SDL_Rect wall;
	SDL_Rect background;
	SDL_Rect background2;
	
};

#endif