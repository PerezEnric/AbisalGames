#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment(lib, "SDL_mixer/libx86/SDL2_mixer.lib")

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

public:
	Mix_Chunk* shot_particle = nullptr;
	SDL_Texture* graphics = nullptr;
	Animation idle;
	Animation* current_animation = nullptr;
	Animation up;
	Animation down;
	iPoint position;
	Collider* col;
	bool destroyed = false;
	int live = 3;
	int speed = 1;
	int cameraback = 0;
	bool turbo = false;
	bool bomb = false;
};

#endif