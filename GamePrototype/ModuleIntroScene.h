#ifndef __ModuleIntroScene_H__
#define __ModuleIntroScene_H__

#include "Module.h"

struct SDL_Texture;

class ModuleIntroScene : public Module
{
public:
	ModuleIntroScene();
	~ModuleIntroScene();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* introBackground = nullptr;

};
#endif