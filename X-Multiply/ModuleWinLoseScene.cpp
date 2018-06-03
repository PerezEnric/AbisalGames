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
#include "ModuleEnemies.h"
#include "ModuleUI.h"
#include "ModuleSceneScore.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleFonts.h"



ModuleWinLoseScene::ModuleWinLoseScene()
{
	position.x = SCREEN_WIDTH / 2;
	position.y = SCREEN_HEIGHT / 2;

	G = { 99, 73, 16, 16 };
	A = { 0, 73, 16, 16 };
	M = { 197, 71, 16, 16 };
	E = { 68, 73, 16, 16 };
	O = { 231, 71, 16, 16 };
	V = { 351, 71, 16, 16 };
	E2 = { 68, 73, 16, 16 };
	R = { 282, 71, 16, 16 };
	C = { 34, 73, 16, 16 };
	L = { 180, 71, 16, 16 };
	S = { 299, 71, 16, 16 };
	T = { 316, 71, 16, 16 };
	ONE = { 32, 123, 16, 16 };
	D = { 51, 73, 16, 16 };
	B = { 17, 73, 16, 16 };
	N = { 214, 71, 16, 16 };
	U = { 333, 71, 16, 16 };
	ZERO = { 0, 123, 16, 16 };
}

ModuleWinLoseScene::~ModuleWinLoseScene()
{}

// Load assets
bool ModuleWinLoseScene::Start()
{
	LOG("Loading losing scene");

	lose_screen = App->textures->Load("Sprites_Assets/UI_1.png");

	game_over_music = App->audio->LoadMusic("Audio_Assets/Game_Over.ogg");
	win_music = App->audio->LoadMusic("Audio_assets/Stage_Clear.ogg");

	if (!App->background->win)
		App->audio->PlayMusic(game_over_music);
	else
		App->audio->PlayMusic(win_music);
	App->particles->Disable();
	App->enemies->Disable();
	App->player->Disable();
	App->ui->Disable();

	return true;
}

// UnLoad assets
bool ModuleWinLoseScene::CleanUp()
{
	LOG("Unloading losing scene");
	App->audio->UnloadMusic(game_over_music);
	game_over_music = nullptr;
	App->audio->UnloadMusic(win_music);
	win_music = nullptr;
	App->textures->Unload(lose_screen);
	lose_screen = nullptr;
	return true;
}

// Update: draw background
update_status ModuleWinLoseScene::Update()
{
	if (App->background->win == false)
	{
		App->player->Disable();
		App->render->camera.x = App->render->camera.y = 0;
		// Draw everything --------------------------------------
		App->render->Blit(lose_screen, 140, SCREEN_HEIGHT / 2, &G);
		App->render->Blit(lose_screen, 156, SCREEN_HEIGHT / 2, &A);
		App->render->Blit(lose_screen, 172, SCREEN_HEIGHT / 2, &M);
		App->render->Blit(lose_screen, 188, SCREEN_HEIGHT / 2, &E);
		App->render->Blit(lose_screen, 216, SCREEN_HEIGHT / 2, &O);
		App->render->Blit(lose_screen, 232, SCREEN_HEIGHT / 2, &V);
		App->render->Blit(lose_screen, 248, SCREEN_HEIGHT / 2, &E);
		App->render->Blit(lose_screen, 264, SCREEN_HEIGHT / 2, &R);

		if (App->input->keyboard[SDL_SCANCODE_SPACE] || App->input->controller[BUTTON_START] == KEY_STATE::KEY_DOWN)
		{
			App->fade->FadeToBlack(this, App->scene_score, 2.0f);
		}
	}
	else if (App->background->win == true)
	{
		App->background->Disable();
		App->enemies->Disable();
		App->ui->Disable();
		//App->audio->PlayMusic(stage_clear_music);
		App->render->camera.x = App->render->camera.y = 0;
		// Draw everything --------------------------------------
		App->render->Blit(lose_screen, 80, SCREEN_HEIGHT / 2, &S);
		App->render->Blit(lose_screen, 96, SCREEN_HEIGHT / 2, &T);
		App->render->Blit(lose_screen, 112, SCREEN_HEIGHT / 2, &A);
		App->render->Blit(lose_screen, 128, SCREEN_HEIGHT / 2, &G);
		App->render->Blit(lose_screen, 144, SCREEN_HEIGHT / 2, &E);
		App->render->Blit(lose_screen, 176, SCREEN_HEIGHT / 2, &ONE);
		App->render->Blit(lose_screen, 224, SCREEN_HEIGHT / 2, &C);
		App->render->Blit(lose_screen, 240, SCREEN_HEIGHT / 2, &L);
		App->render->Blit(lose_screen, 256, SCREEN_HEIGHT / 2, &E);
		App->render->Blit(lose_screen, 272, SCREEN_HEIGHT / 2, &A);
		App->render->Blit(lose_screen, 288, SCREEN_HEIGHT / 2, &R);
		App->render->Blit(lose_screen, 304, SCREEN_HEIGHT / 2, &E);
		App->render->Blit(lose_screen, 320, SCREEN_HEIGHT / 2, &D);
		App->render->Blit(lose_screen, 48, SCREEN_HEIGHT / 2 + 16, &S);
		App->render->Blit(lose_screen, 64, SCREEN_HEIGHT / 2 + 16, &T);
		App->render->Blit(lose_screen, 80, SCREEN_HEIGHT / 2 + 16, &A);
		App->render->Blit(lose_screen, 96, SCREEN_HEIGHT / 2 + 16, &G);
		App->render->Blit(lose_screen, 112, SCREEN_HEIGHT / 2 + 16, &E);
		App->render->Blit(lose_screen, 144, SCREEN_HEIGHT / 2 + 16, &B);
		App->render->Blit(lose_screen, 160, SCREEN_HEIGHT / 2 + 16, &O);
		App->render->Blit(lose_screen, 176, SCREEN_HEIGHT / 2 + 16, &N);
		App->render->Blit(lose_screen, 192, SCREEN_HEIGHT / 2 + 16, &U);
		App->render->Blit(lose_screen, 208, SCREEN_HEIGHT / 2 + 16, &S);
		App->render->Blit(lose_screen, 240, SCREEN_HEIGHT / 2 + 16, &ONE);
		App->render->Blit(lose_screen, 256, SCREEN_HEIGHT / 2 + 16, &ZERO);
		App->render->Blit(lose_screen, 272, SCREEN_HEIGHT / 2 + 16, &ZERO);
		App->render->Blit(lose_screen, 288, SCREEN_HEIGHT / 2 + 16, &ZERO);
		App->render->Blit(lose_screen, 304, SCREEN_HEIGHT / 2 + 16, &ZERO);

		if (App->input->keyboard[SDL_SCANCODE_SPACE] || App->input->controller[BUTTON_START] == KEY_STATE::KEY_DOWN)
		{
			App->fade->FadeToBlack(this, App->scene_score, 2.0f);
		}
	}
	return UPDATE_CONTINUE;
}