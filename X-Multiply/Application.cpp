#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleBackground.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleTentacles.h"
#include "ModuleFonts.h"
#include "ModuleUI.h"
#include "ModuleIntroScene.h"
#include "ModuleWinLoseScene.h"
#include "ModuleSceneScore.h"

Application::Application()
{
	modules[0] = window = new ModuleWindow();
	modules[1] = render = new ModuleRender();
	modules[2] = input = new ModuleInput();
	modules[3] = textures = new ModuleTextures();
	modules[4] = audio = new ModuleAudio();
	modules[5] = intro = new ModuleIntroScene();
	modules[6] = background = new ModuleBackground();
	modules[7] = win_lose = new ModuleWinLoseScene();
	modules[8] = tentacle = new ModuleTentacles();
	modules[9] = player = new ModulePlayer();
	modules[10] = particles = new ModuleParticles();
	modules[11] = collision = new ModuleCollision();
	modules[12] = enemies = new ModuleEnemies();
	modules[13] = fonts = new ModuleFonts();
	modules[14] = ui = new ModuleUI();
	modules[15] = fade = new ModuleFadeToBlack();
	modules[16] = scene_score = new ModuleSceneScore();
}	

Application::~Application()
{
	for(int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	// disable modules
	player->Disable();
	background->Disable();
	ui->Disable();
	win_lose->Disable();
	tentacle->Disable();
	scene_score->Disable();
	

	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;
	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;


	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for(int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->CleanUp();

	return ret;
}