#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleBackground.h"
#include "ModuleFonts.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "ModuleWinLoseScene.h"
#include "ModuleEnemies.h"
#include "ModuleTentacles.h"
//#include "ModuleFonts.h"
#include "ModuleTentacles.h"
#include <stdio.h>



ModulePlayer::ModulePlayer()
{
	graphics = NULL;
	current_animation = NULL;

	position.x = 10;
	position.y = 10;

	// idle animation
	idle.PushBack({ 828, 729, 35, 14 });

	idle.speed = 0.2f;

	//upwards animation
	up.PushBack({ 782, 730, 34, 11 });
	up.PushBack({ 733, 732, 35, 12 });
	up.loop = false;
	up.speed = 0.1f;

	//downwards animation

	down.PushBack({ 876, 731, 35, 12 });
	down.PushBack({ 924, 733, 35, 12 });
	down.loop = false;
	down.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	destroyed = false;
	graphics = App->textures->Load("Sprites_Assets/all_enemies.png"); // arcade version
	shot_particle = App->audio->LoadSoundEffect("Audio_Assets/shotp.wav");
	/*player_death = App->audio->LoadSoundEffect("Audio_Assets/player_death.wav");*/
	/*font_score = App->fonts->Load("Sprites_Assets/fonts.png", "0123456789ם.-=יט()ףעבת`´!?abcdefghijklmnopqrstuvwxyz", 2);*/
	col = App->collision->AddCollider({ position.x, position.y, 35, 14 }, COLLIDER_PLAYER, this);

	return ret;
}


bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	graphics = nullptr;

	App->audio->UnloadSoundEffect(shot_particle);
	shot_particle = nullptr;

	/*App->audio->UnloadSoundEffect(player_death);
	player_death = nullptr;*/

	if (col != nullptr)
	{
		col->to_delete = true;
		col = nullptr;
	}

	return true;
}


// Update: draw background
update_status ModulePlayer::Update()
{

	/*if (App->background->move)
		cameraback += speed;*/
	int tentacle_speed = 4;
	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		if (turbo == false)
		{
			position.x += (speed * 2);
		}
		else
		{
			position.x += 3;
		}
	}


	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		if (turbo == false)
		{
			position.y -= (speed * 2);
		}
		else
		{
			position.y -= 3;
		}
		

		if (current_animation != &up)
		{
			up.Reset();
			current_animation = &up;
		}


	}

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		if (turbo == false)
		{
			position.y += (speed * 2);

		}
		else
		{
			position.y += 3;
		}
		
		if (current_animation != &down)
		{
			down.Reset();
			current_animation = &down;
		}
		
	}
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		if (turbo == false)
		{
			position.x -= (speed * 2);
		}
		else
		{
			position.x -= 3;
		}

	}


	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || App->input->controller[BUTTON_A] == KEY_STATE::KEY_DOWN)
	{
		if (wave == false)
		{
			App->particles->AddParticle(App->particles->explosion_shot, position.x + 37, position.y + 1);
			App->particles->AddParticle(App->particles->laser, position.x + 38, position.y + 6, COLLIDER_PLAYER_SHOT);
			App->audio->PlaySoundEffect(shot_particle);
		}
		if (cd < 5)
		{
			cd++;
		}
		else
		{

			if (bomb)
			{
				App->particles->AddParticle(App->particles->bombPU, position.x, position.y + 7, COLLIDER_PLAYER_SHOT);
			}
			cd = 0;
		}
	}

	sprintf_s(text, 10, "%7d", score);

	App->fonts->BlitText(50, 235, font_score, text);
	App->fonts->BlitText(32, 150, font_score, "score");

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE)
		current_animation = &idle;

	if (App->input->keyboard[SDL_SCANCODE_F2] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->background, (Module*)App->win_lose);
		App->background->win = false;

	}
	if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->background, (Module*)App->win_lose);
		App->background->win = true;
	}
	//powerup
	if (App->input->keyboard[SDL_SCANCODE_F8] == KEY_STATE::KEY_DOWN)
	{
		tentacles = !tentacles;
		if (App->tentacle->IsEnabled())
			App->tentacle->Disable();
		else App->tentacle->Enable();
	}
	if (App->input->keyboard[SDL_SCANCODE_F6] == KEY_STATE::KEY_DOWN)
	{
		bomb = !bomb;
	}
	if (App->input->keyboard[SDL_SCANCODE_F7] == KEY_STATE::KEY_DOWN)
	{
		turbo = !turbo;
	}

	col->SetPos(position.x, position.y);
	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}

