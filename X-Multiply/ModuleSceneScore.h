#ifndef __ModuleSceneScore_H__
#define __ModuleSceneScore_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment(lib, "SDL_mixer/libx86/SDL2_mixer.lib")

struct SDL_Texture;

class ModuleSceneScore : public Module
{
public:
	ModuleSceneScore();
	~ModuleSceneScore();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background_score = nullptr;
	SDL_Texture* allscores = nullptr;
	SDL_Texture* infinit = nullptr;
	Mix_Music* score_music = nullptr;
	SDL_Rect infinitsprite;
	int infinitepos;
	char text1[10];
	//uint maxscore1 = 0;
	SDL_Rect camera;
	iPoint position;
};

#endif