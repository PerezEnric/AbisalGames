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
	Mix_Music* game_over_music = nullptr;
	Mix_Music* win_music = nullptr;


	SDL_Rect camera;
	iPoint position;
};

#endif