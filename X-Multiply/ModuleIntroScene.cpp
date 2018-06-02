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
#include "ModuleEnemies.h"
#include "ModuleWinLoseScene.h"
#include "ModuleUI.h"



ModuleIntroScene::ModuleIntroScene()
{
	game_title = { 0, 270, 384, 61 };
	game_company = { 0, 359, 152, 38 };
	/*back = { 0,0,384,256 };*/
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
	/*App->win_lose->Disable();*/
	App->enemies->Disable();
	App->background->Disable();
	App->player->Disable();
	App->win_lose->Disable();
	App->ui->Disable();

	App->render->move_front= false;
	App->render->move_back = false;
	App->render->move_up = false;
	App->render->move_down = false;

	App->player->position.y = 103;
	App->player->position.x = 87;
	App->player->live = 3;
	App->player->points = 0;
	App->player->tentacles = false;
	App->player->bomb = false;
	App->player->wave = false;
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
	App->render->camera.x = App->render->camera.y = 0;
	// Draw everything --------------------------------------
	App->render->Blit(introBackground, 0, 0, NULL);
	App->render->Blit(introBackground, 0, 0, &game_title);
	App->render->Blit(introBackground, 116, 183, &game_company);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] || App->input->controller[BUTTON_START] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, App->background, 2.0f);
		flag = true;
	}
	return UPDATE_CONTINUE;
}
