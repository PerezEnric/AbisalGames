#ifndef __ModuleAudio_H__
#define __ModuleAudio_H__

#include "Module.h"
#include "Globals.h"


struct Mix_Music;

class ModuleAudio : public Module
{
public:
	ModuleAudio();
	~ModuleAudio();
	bool Init();
	bool Start();
	bool CleanUp();
	update_status Update();

public:
	Mix_Music* firstlvlmusic = nullptr;
};

#endif

