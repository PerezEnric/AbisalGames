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
	
	Mix_Music* secondlvlmusic = nullptr;
	SDL_Texture* black_background = nullptr;
	SDL_Rect background;
	SDL_Texture* monster_head = nullptr;
	SDL_Rect head;
	SDL_Texture* monster_body = nullptr;
	SDL_Rect body;
	SDL_Texture* monster_tail = nullptr;
	SDL_Rect tail;
	SDL_Texture* enemy_left_dorsal = nullptr;
	SDL_Rect left_dorsal;
	SDL_Texture* enemy_middle_dorsal = nullptr;
	SDL_Rect middle_dorsal;
	SDL_Texture* enemy_right_dorsal = nullptr;
	SDL_Rect right_dorsal;
	SDL_Texture* monster_eye;
	SDL_Rect eye;

};

#endif