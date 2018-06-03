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
	screen_pick = { 0,0,384,250 };

	positions.x = SCREEN_WIDTH / 2;
	positions.y = SCREEN_HEIGHT / 2;

	//Letters
	P = { 240, 428, 16, 16 };
	U = { 319, 446, 16, 16 };
	S = { 290, 451, 16, 16 };
	H = { 111, 451, 16, 16 };
	T = { 304, 428, 16, 16 };
	A = { 0, 428, 16, 16 };
	R = { 272, 428, 16, 16 };
	B = { 16, 453, 16, 16 };
	O = { 225, 455, 16, 16 };
	N = { 208, 428, 16, 16 };
	ONE = { 20, 411, 8, 16 };
	L = { 176, 428, 16, 16 };
	Y = { 385, 452, 16, 16 };
	E = { 63, 446, 16, 16 };
	C = { 35, 452, 16, 16 };
	D = { 48, 428, 16, 16 };
	I = { 134, 428, 4, 16 };
	TWO = {30, 411, 16,16};
	THREE = {48,403,16,16};
	FOUR = {68,409,16,16};
	FIVE = {86,409,16,16};
}

ModuleIntroScene::~ModuleIntroScene()
{}

// Load assets
bool ModuleIntroScene::Start()
{
	LOG("Loading space scene");

	introBackground = App->textures->Load("Sprites_Assets/UI_2.png");
	intro_music = App->audio->LoadMusic("Audio_Assets/X-Multiply_Title.ogg");
	pickback = App->textures->Load("Sprites_Assets/Background2.png");
	coins = App->audio->LoadSoundEffect("Audio_Assets/coin_sound.wav");
	App->audio->PlayMusic(intro_music);
	/*App->win_lose->Disable();*/
	App->enemies->Disable();
	App->background->Disable();
	App->player->Disable();
	App->win_lose->Disable();
	App->ui->Disable();
	pick = true;
	conta = 0;
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
	if (pick == true)
	{
		App->render->Blit(introBackground, 0, 0, NULL);
		App->render->Blit(introBackground, 0, 0, &game_title);
		App->render->Blit(introBackground, 116, 183, &game_company);
	}
	

	if (App->input->keyboard[SDL_SCANCODE_SPACE] || App->input->controller[BUTTON_START] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, App->background, 2.0f);
		flag = true;
	}

	if (App->input->keyboard[SDL_SCANCODE_5] || App->input->controller[BUTTON_Y] == KEY_STATE::KEY_DOWN)
	{
		App->audio->UnloadMusic(intro_music);
		App->render->Blit(pickback, 0, 0, &screen_pick);
		//App->audio->PlaySoundEffect(coins);
		//conta++;
		pick = false;

		

		
	}
	if (pick == false)
	{
		App->render->Blit(introBackground, 49, SCREEN_HEIGHT / 2 - 70, &P);
		App->render->Blit(introBackground, 65, SCREEN_HEIGHT / 2 - 70, &U);
		App->render->Blit(introBackground, 81, SCREEN_HEIGHT / 2 - 70, &S);
		App->render->Blit(introBackground, 97, SCREEN_HEIGHT / 2 - 70, &H);
		App->render->Blit(introBackground, 121, SCREEN_HEIGHT / 2 - 70, &S);
		App->render->Blit(introBackground, 137, SCREEN_HEIGHT / 2 - 70, &T);
		App->render->Blit(introBackground, 153, SCREEN_HEIGHT / 2 - 70, &A);
		App->render->Blit(introBackground, 169, SCREEN_HEIGHT / 2 - 70, &R);
		App->render->Blit(introBackground, 185, SCREEN_HEIGHT / 2 - 70, &T);
		App->render->Blit(introBackground, 209, SCREEN_HEIGHT / 2 - 70, &B);
		App->render->Blit(introBackground, 225, SCREEN_HEIGHT / 2 - 70, &U);
		App->render->Blit(introBackground, 241, SCREEN_HEIGHT / 2 - 70, &T);
		App->render->Blit(introBackground, 257, SCREEN_HEIGHT / 2 - 70, &T);
		App->render->Blit(introBackground, 273, SCREEN_HEIGHT / 2 - 70, &O);
		App->render->Blit(introBackground, 289, SCREEN_HEIGHT / 2 - 70, &N);

		if (conta == 1 && pick == false)
		{
			App->render->Blit(introBackground, 72, SCREEN_HEIGHT / 2 - 10, &ONE);
			App->render->Blit(introBackground, 96, SCREEN_HEIGHT / 2 - 10, &P);
			App->render->Blit(introBackground, 112, SCREEN_HEIGHT / 2 - 10, &L);
			App->render->Blit(introBackground, 128, SCREEN_HEIGHT / 2 - 10, &A);
			App->render->Blit(introBackground, 144, SCREEN_HEIGHT / 2 - 10, &Y);
			App->render->Blit(introBackground, 160, SCREEN_HEIGHT / 2 - 10, &E);
			App->render->Blit(introBackground, 176, SCREEN_HEIGHT / 2 - 10, &R);
			App->render->Blit(introBackground, 200, SCREEN_HEIGHT / 2 - 10, &O);
			App->render->Blit(introBackground, 216, SCREEN_HEIGHT / 2 - 10, &N);
			App->render->Blit(introBackground, 232, SCREEN_HEIGHT / 2 - 10, &L);
			App->render->Blit(introBackground, 248, SCREEN_HEIGHT / 2 - 10, &Y);

			App->render->Blit(introBackground, 104, SCREEN_HEIGHT / 2 + 40, &C);
			App->render->Blit(introBackground, 121, SCREEN_HEIGHT / 2 + 40, &R);
			App->render->Blit(introBackground, 137, SCREEN_HEIGHT / 2 + 40, &E);
			App->render->Blit(introBackground, 153, SCREEN_HEIGHT / 2 + 40, &D);
			App->render->Blit(introBackground, 169, SCREEN_HEIGHT / 2 + 40, &I);
			App->render->Blit(introBackground, 173, SCREEN_HEIGHT / 2 + 40, &T);
			App->render->Blit(introBackground, 197, SCREEN_HEIGHT / 2 + 40, &ONE);
		}
		else if (conta == 2)
		{
			App->render->Blit(introBackground, 8, SCREEN_HEIGHT / 2 - 10, &ONE);
			App->render->Blit(introBackground, 32, SCREEN_HEIGHT / 2 - 10, &O);
			App->render->Blit(introBackground, 48, SCREEN_HEIGHT / 2 - 10, &R);
			App->render->Blit(introBackground, 72, SCREEN_HEIGHT / 2 - 10, &TWO);
			App->render->Blit(introBackground, 96, SCREEN_HEIGHT / 2 - 10, &P);
			App->render->Blit(introBackground, 112, SCREEN_HEIGHT / 2 - 10, &L);
			App->render->Blit(introBackground, 128, SCREEN_HEIGHT / 2 - 10, &A);
			App->render->Blit(introBackground, 144, SCREEN_HEIGHT / 2 - 10, &Y);
			App->render->Blit(introBackground, 160, SCREEN_HEIGHT / 2 - 10, &E);
			App->render->Blit(introBackground, 176, SCREEN_HEIGHT / 2 - 10, &R);
			App->render->Blit(introBackground, 72, SCREEN_HEIGHT / 2 - 10, &S);
			App->render->Blit(introBackground, 200, SCREEN_HEIGHT / 2 - 10, &O);
			App->render->Blit(introBackground, 216, SCREEN_HEIGHT / 2 - 10, &N);
			App->render->Blit(introBackground, 232, SCREEN_HEIGHT / 2 - 10, &L);
			App->render->Blit(introBackground, 248, SCREEN_HEIGHT / 2 - 10, &Y);

			App->render->Blit(introBackground, 104, SCREEN_HEIGHT / 2 + 40, &C);
			App->render->Blit(introBackground, 121, SCREEN_HEIGHT / 2 + 40, &R);
			App->render->Blit(introBackground, 137, SCREEN_HEIGHT / 2 + 40, &E);
			App->render->Blit(introBackground, 153, SCREEN_HEIGHT / 2 + 40, &D);
			App->render->Blit(introBackground, 169, SCREEN_HEIGHT / 2 + 40, &I);
			App->render->Blit(introBackground, 173, SCREEN_HEIGHT / 2 + 40, &T);
			App->render->Blit(introBackground, 197, SCREEN_HEIGHT / 2 + 40, &TWO);
		}
		else if (conta == 3)
		{
			App->render->Blit(introBackground, 72, SCREEN_HEIGHT / 2 - 10, &ONE);
			App->render->Blit(introBackground, 96, SCREEN_HEIGHT / 2 - 10, &P);
			App->render->Blit(introBackground, 112, SCREEN_HEIGHT / 2 - 10, &L);
			App->render->Blit(introBackground, 128, SCREEN_HEIGHT / 2 - 10, &A);
			App->render->Blit(introBackground, 144, SCREEN_HEIGHT / 2 - 10, &Y);
			App->render->Blit(introBackground, 160, SCREEN_HEIGHT / 2 - 10, &E);
			App->render->Blit(introBackground, 176, SCREEN_HEIGHT / 2 - 10, &R);
			App->render->Blit(introBackground, 200, SCREEN_HEIGHT / 2 - 10, &O);
			App->render->Blit(introBackground, 216, SCREEN_HEIGHT / 2 - 10, &N);
			App->render->Blit(introBackground, 232, SCREEN_HEIGHT / 2 - 10, &L);
			App->render->Blit(introBackground, 248, SCREEN_HEIGHT / 2 - 10, &Y);

			App->render->Blit(introBackground, 104, SCREEN_HEIGHT / 2 + 40, &C);
			App->render->Blit(introBackground, 121, SCREEN_HEIGHT / 2 + 40, &R);
			App->render->Blit(introBackground, 137, SCREEN_HEIGHT / 2 + 40, &E);
			App->render->Blit(introBackground, 153, SCREEN_HEIGHT / 2 + 40, &D);
			App->render->Blit(introBackground, 169, SCREEN_HEIGHT / 2 + 40, &I);
			App->render->Blit(introBackground, 173, SCREEN_HEIGHT / 2 + 40, &T);
			App->render->Blit(introBackground, 197, SCREEN_HEIGHT / 2 + 40, &THREE);
		}
		else if (conta == 4)
		{
			App->render->Blit(introBackground, 72, SCREEN_HEIGHT / 2 - 10, &ONE);
			App->render->Blit(introBackground, 96, SCREEN_HEIGHT / 2 - 10, &P);
			App->render->Blit(introBackground, 112, SCREEN_HEIGHT / 2 - 10, &L);
			App->render->Blit(introBackground, 128, SCREEN_HEIGHT / 2 - 10, &A);
			App->render->Blit(introBackground, 144, SCREEN_HEIGHT / 2 - 10, &Y);
			App->render->Blit(introBackground, 160, SCREEN_HEIGHT / 2 - 10, &E);
			App->render->Blit(introBackground, 176, SCREEN_HEIGHT / 2 - 10, &R);
			App->render->Blit(introBackground, 200, SCREEN_HEIGHT / 2 - 10, &O);
			App->render->Blit(introBackground, 216, SCREEN_HEIGHT / 2 - 10, &N);
			App->render->Blit(introBackground, 232, SCREEN_HEIGHT / 2 - 10, &L);
			App->render->Blit(introBackground, 248, SCREEN_HEIGHT / 2 - 10, &Y);

			App->render->Blit(introBackground, 104, SCREEN_HEIGHT / 2 + 40, &C);
			App->render->Blit(introBackground, 121, SCREEN_HEIGHT / 2 + 40, &R);
			App->render->Blit(introBackground, 137, SCREEN_HEIGHT / 2 + 40, &E);
			App->render->Blit(introBackground, 153, SCREEN_HEIGHT / 2 + 40, &D);
			App->render->Blit(introBackground, 169, SCREEN_HEIGHT / 2 + 40, &I);
			App->render->Blit(introBackground, 173, SCREEN_HEIGHT / 2 + 40, &T);
			App->render->Blit(introBackground, 197, SCREEN_HEIGHT / 2 + 40, &FOUR);
		}
		else if (conta == 5)
		{
			App->render->Blit(introBackground, 72, SCREEN_HEIGHT / 2 - 10, &ONE);
			App->render->Blit(introBackground, 96, SCREEN_HEIGHT / 2 - 10, &P);
			App->render->Blit(introBackground, 112, SCREEN_HEIGHT / 2 - 10, &L);
			App->render->Blit(introBackground, 128, SCREEN_HEIGHT / 2 - 10, &A);
			App->render->Blit(introBackground, 144, SCREEN_HEIGHT / 2 - 10, &Y);
			App->render->Blit(introBackground, 160, SCREEN_HEIGHT / 2 - 10, &E);
			App->render->Blit(introBackground, 176, SCREEN_HEIGHT / 2 - 10, &R);
			App->render->Blit(introBackground, 200, SCREEN_HEIGHT / 2 - 10, &O);
			App->render->Blit(introBackground, 216, SCREEN_HEIGHT / 2 - 10, &N);
			App->render->Blit(introBackground, 232, SCREEN_HEIGHT / 2 - 10, &L);
			App->render->Blit(introBackground, 248, SCREEN_HEIGHT / 2 - 10, &Y);

			App->render->Blit(introBackground, 104, SCREEN_HEIGHT / 2 + 40, &C);
			App->render->Blit(introBackground, 121, SCREEN_HEIGHT / 2 + 40, &R);
			App->render->Blit(introBackground, 137, SCREEN_HEIGHT / 2 + 40, &E);
			App->render->Blit(introBackground, 153, SCREEN_HEIGHT / 2 + 40, &D);
			App->render->Blit(introBackground, 169, SCREEN_HEIGHT / 2 + 40, &I);
			App->render->Blit(introBackground, 173, SCREEN_HEIGHT / 2 + 40, &T);
			App->render->Blit(introBackground, 197, SCREEN_HEIGHT / 2 + 40, &FIVE);
		}

	}
	
	return UPDATE_CONTINUE;
}
