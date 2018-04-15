#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleBackground.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleIntroScene.h"
#include "ModuleFadeToBlack.h"



ModuleIntroScene::ModuleIntroScene()
{
	game_title = { 0, 270, 384, 51 };
	game_company = { 0, 359, 152, 38 };

}

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
	App->render->Blit(introBackground, 0, 0, &game_title);
	App->render->Blit(introBackground, 116, 183, &game_company);

	if (App->input->keyboard[SDL_SCANCODE_Q])
	{
		App->fade->FadeToBlack(this, App->background, 2.0f);
		App->background->Enable();
		flag = true;
	}
	return UPDATE_CONTINUE;
}
