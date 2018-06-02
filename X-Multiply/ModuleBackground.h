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
	bool CleanUp();
	void camera();
	void cameralimit();
	void bossexplosions();

public:
	
	SDL_Texture* black_background = nullptr;
	SDL_Rect background;
	SDL_Texture* monster_head = nullptr;
	SDL_Rect head;
	SDL_Texture* monster_body = nullptr;
	SDL_Rect body;
	SDL_Texture* monster_tail = nullptr;
	SDL_Rect tail;
	SDL_Texture* enemy_parts = nullptr;
	SDL_Rect parts;
	Mix_Music * lvl2_music = nullptr;


	//tail
	SDL_Rect tail2;
	int tailpositionx, tailpositiony;
	bool taildown;
	bool win;
	int move_cont = 0;
	bool go_back;
	int cont = 0;
	int bossy;
	int bossx;
	bool expboss, boss_wakeup = false;
};

#endif