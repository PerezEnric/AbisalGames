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
	void limitTentacles();

public:
	SDL_Texture* graphics = nullptr;
	Animation tentacl;
	Animation* current_animation = nullptr;
	iPoint position;
	

};
#endif