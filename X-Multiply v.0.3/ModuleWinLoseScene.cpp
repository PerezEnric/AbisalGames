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
#include "ModuleWinLoseScene.h"



ModuleWinLoseScene::ModuleWinLoseScene()
{
	position.x = SCREEN_WIDTH / 2;
	position.y = SCREEN_HEIGHT / 2;

	G ={ 99, 23, 16, 16 };
	A = { 0, 23, 16, 16 };
	M = { 197, 23, 16, 16 };
	E = { 68, 23, 16, 16 };
	O = { 231, 21, 18, 16 };
	V = { 351, 21, 18, 16 };
	E2 = { 68, 23, 16, 16 };
	R = { 282, 23, 16, 16 };
}

ModuleWinLoseScene::~ModuleWinLoseScene()
{}

// Load assets
bool ModuleWinLoseScene::Start()
{
	LOG("Loading losing scene");

	lose_screen = App->textures->Load("Sprites_Assets/Alphabet.png");

	game_over_music = App->audio->LoadMusic("Audio_Assets/Game_Over.ogg");
	App->audio->PlayMusic(game_over_music);

	
	return true;
}

// UnLoad assets
bool ModuleWinLoseScene::CleanUp()
{
	LOG("Unloading losing scene");

	App->textures->Unload(lose_screen);
	lose_screen = nullptr;
	return true;
}

// Update: draw background
update_status ModuleWinLoseScene::Update()
{
	App->render->camera.x = App->render->camera.y = 0;
	// Draw everything --------------------------------------
	App->render->Blit(lose_screen, 160, SCREEN_HEIGHT / 2, &G);
	App->render->Blit(lose_screen, 176, SCREEN_HEIGHT / 2, &A);
	App->render->Blit(lose_screen, 192, SCREEN_HEIGHT / 2, &M);
	App->render->Blit(lose_screen, 208, SCREEN_HEIGHT / 2, &E);
	App->render->Blit(lose_screen, 224, SCREEN_HEIGHT / 2, &O);
	App->render->Blit(lose_screen, 240, SCREEN_HEIGHT / 2, &V);
	App->render->Blit(lose_screen, 256, SCREEN_HEIGHT / 2, &E2);
	App->render->Blit(lose_screen, 272, SCREEN_HEIGHT / 2, &R);

	if (App->input->keyboard[SDL_SCANCODE_SPACE])
	{
		App->fade->FadeToBlack(this, App->intro, 2.0f);
	}
	return UPDATE_CONTINUE;
}
