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
	void tentaclemove();

public:
	SDL_Texture* graphics = nullptr;
	Animation tentacl;
	Animation* current_animation = nullptr;
	iPoint position;
	
	Animation toptentacle;
	Animation* current_animationTentacle = nullptr;
	iPoint tentacleposition;
	Animation toptentaclefront;

	bool start = false;

};
#endif