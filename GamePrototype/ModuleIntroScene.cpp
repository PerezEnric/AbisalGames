#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleBackground.h"
#include "ModuleInput.h"
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
	App->background->Disable();

	return true;
}

// UnLoad assets
bool ModuleIntroScene::CleanUp()
{
	LOG("Unloading intro scene");

	App->textures->Unload(introBackground);

	return true;
}

// Update: draw background
update_status ModuleIntroScene::Update()
{
	// Draw everything --------------------------------------
	App->render->Blit(introBackground, 0, 0, NULL);
	if (App->input->keyboard[SDL_SCANCODE_Q])
	{
		App->player->Enable();
		App->background->Enable();
	}


	

	return UPDATE_CONTINUE;
}