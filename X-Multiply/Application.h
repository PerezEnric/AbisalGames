#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 17

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleBackground;
class ModulePlayer;
class ModuleTentacles;
class ModuleParticles;
class ModuleFadeToBlack;
class ModuleCollision;
class ModuleEnemies;
class ModuleAudio;
class Module;
class ModuleUI;
class ModuleFonts;
class ModuleIntroScene;
class ModuleWinLoseScene;
class ModuleSceneScore;

class Application
{
public:

	Module * modules[NUM_MODULES] = { nullptr };
	ModuleWindow* window = nullptr;
	ModuleRender* render = nullptr;
	ModuleInput* input = nullptr;
	ModuleTextures* textures = nullptr;
	ModuleBackground* background = nullptr;
	ModulePlayer* player = nullptr;
	ModuleTentacles* tentacle = nullptr;
	ModuleParticles* particles = nullptr;
	ModuleFadeToBlack* fade = nullptr;
	ModuleCollision* collision = nullptr;
	ModuleEnemies* enemies = nullptr;
	ModuleAudio* audio = nullptr;
	ModuleUI* ui = nullptr;
	ModuleFonts* fonts = nullptr;
	ModuleIntroScene* intro = nullptr;
	ModuleWinLoseScene* win_lose = nullptr;
	ModuleSceneScore* scene_score = nullptr;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__