#ifndef __ModuleTentacles_H__
#define __ModuleTentacles_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;

class ModuleTentacles : public Module
{
public:
	ModuleTentacles();
	~ModuleTentacles();


	bool Start();
	update_status Update();
	bool CleanUp();
	
public:
	SDL_Texture* graphics = nullptr;
	Animation tentacl;
	Animation* current_animation = nullptr;
	iPoint position;
	iPoint hand_down;

public:
	SDL_Rect arm0, arm1, arm2, arm3, arm4, arm5;
	SDL_Rect arm6, arm7, arm8, arm9, arm10, arm11, arm12, arm13, arm14,arm15;

public:
	void movetentacle();
	float cd = 0;
	iPoint posArm0, posArm1, posArm2, posArm3, posArm4;
	iPoint posArm10, posArm11, posArm12, posArm13, posArm14;

};
#endif