#ifndef __ModuleIntroScene_H__
#define __ModuleIntroScene_H__

#include "Module.h"
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment(lib, "SDL_mixer/libx86/SDL2_mixer.lib")

struct SDL_Texture;

class ModuleIntroScene : public Module
{
public:
	ModuleIntroScene();
	~ModuleIntroScene();

	bool Start();
	update_status Update();
	bool CleanUp();
	void ready();
public:
	bool flag = false;
	bool pick;
	SDL_Texture* introBackground = nullptr;
	Mix_Music* intro_music = nullptr;
	Mix_Chunk* coins = nullptr;
	SDL_Rect game_title;
	SDL_Rect game_company;
	SDL_Texture* pickback;
	SDL_Rect screen_pick;

	//Letters
	SDL_Rect P;
	SDL_Rect U;
	SDL_Rect S;
	SDL_Rect H;
	SDL_Rect T;
	SDL_Rect A;
	SDL_Rect R;
	SDL_Rect B;
	SDL_Rect O;
	SDL_Rect N;
	SDL_Rect ONE;
	SDL_Rect TWO;
	SDL_Rect THREE;
	SDL_Rect FOUR;
	SDL_Rect FIVE;
	SDL_Rect L;
	SDL_Rect Y;
	SDL_Rect E;
	SDL_Rect C;
	SDL_Rect D;
	SDL_Rect I;
	iPoint positions;
	int credits;
	//SDL_Rect back;
};
#endif
