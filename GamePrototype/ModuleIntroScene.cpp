#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleIntroScene.h"



ModuleIntroScene::ModuleIntroScene()
{}

ModuleIntroScene::~ModuleIntroScene()
{}

// Load assets
bool ModuleIntroScene::Start()
{
	LOG("Loading space scene");

	introBackground = App->textures->Load("Ui_2.png");

	App->player->Disable();

	return true;
}

// UnLoad assets
bool ModuleIntroScene::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(introBackground);
	App->player->Enable();

	return true;
}

// Update: draw background
update_status ModuleIntroScene::Update()
{
	


	// Draw everything --------------------------------------
	App->render->Blit(introBackground, 0, 0, NULL);

	return UPDATE_CONTINUE;
}