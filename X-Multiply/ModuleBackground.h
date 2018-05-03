#ifndef __ModuleBackground_H__
#define __ModuleBackground_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleBackground : public Module
{
public:
	ModuleBackground();
	~ModuleBackground();

	bool Start();
	update_status Update();

public:
	
	SDL_Texture* black_background = nullptr;
	SDL_Rect background;
	SDL_Texture* monster_head = nullptr;
	SDL_Rect head;
	SDL_Texture* monster_body = nullptr;
	SDL_Rect body;
	SDL_Texture* monster_tail = nullptr;
	SDL_Rect tail;


};

#endif