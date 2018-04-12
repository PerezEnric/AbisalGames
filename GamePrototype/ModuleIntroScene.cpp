#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleBackground.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleIntroScene.h"



ModuleIntroScene::ModuleIntroScene()
{}

ModuleIntroScene::~ModuleIntroScene()
{}

// Load assets
bool ModuleIntroScene::Start()
{
	LOG("Loading space scene");

	introBackground = App->textures->Load("Sprites_Assets/UI_2.png");

	intro_music = App->audio->LoadMusic("Audio_Assets/X-Multiply_Title.ogg");
	App->audio->PlayMusic(intro_music);
	App->player->Disable();
	App->background->Disable();

	return true;
}

// UnLoad assets
bool ModuleIntroScene::CleanUp()
{
	LOG("Unloading intro scene");

	App->textures->Unload(introBackground);
	introBackground = nullptr;
	App->audio->UnloadMusic(intro_music);
	intro_music = nullptr;
	return true;
}

// Update: draw background
update_status ModuleIntroScene::Update()
{
	// Draw everything --------------------------------------
	App->render->Blit(introBackground, 0, 0, NULL);
	if (App->input->keyboard[SDL_SCANCODE_Q])
	{
		App->audio->Disable();
		App->background->Enable();
		App->player->Enable();
		flag = true;
	}
	return UPDATE_CONTINUE;
}
