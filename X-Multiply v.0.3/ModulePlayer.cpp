#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleBackground.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "ModuleWinLoseScene.h"
#include "ModuleEnemies.h"



ModulePlayer::ModulePlayer()
{
	graphics = NULL;
	current_animation = NULL;

	position.x = 87;
	position.y = 103;

	// idle animation
	idle.PushBack({101, 1, 35, 14});
	
	idle.speed = 0.2f;

	//upwards animation
	up.PushBack({ 54, 2, 34, 11 });
	up.PushBack({ 6, 4, 35, 12 });
	up.loop = false;
	up.speed = 0.1f;

	//downwards animation
	
	down.PushBack({ 149, 3, 35, 12 });
	down.PushBack({ 197, 5, 35, 12 });
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
	graphics = App->textures->Load("Sprites_Assets/Player.png"); // arcade version
	shot_particle = App->audio->LoadSoundEffect("Audio_Assets/shotp.wav");

	col = App->collision->AddCollider({ position.x, position.y, 35, 14 }, COLLIDER_PLAYER, this);

	App->player->live = 3;

	return ret;
}


bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	if (col != nullptr)
		col->to_delete = true;

	return true;
}


// Update: draw background
update_status ModulePlayer::Update()
{

	position.x += speed;
	if (App->background->move)
		cameraback += speed;

	if(App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		if (turbo == false)
		{
			position.x += (speed * 2);
		}
		else
		{
			position.x += 6;
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
			position.y -= 6;
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
			position.y += 6;
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
			position.x -= 6;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->explosion_shot, position.x + 37, position.y + 1);
		App->particles->AddParticle(App->particles->laser, position.x + 38, position.y + 6, COLLIDER_PLAYER_SHOT);
		App->audio->PlaySoundEffect(shot_particle);
	}

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE)
		current_animation = &idle;

	if (App->input->keyboard[SDL_SCANCODE_F2] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->background, (Module*)App->win_lose);

	}

	col->SetPos(position.x, position.y);
	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));


	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	 
	if (c1 == col && destroyed == false && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack((Module*)App->background, (Module*)App->win_lose);
		App->particles->AddParticle(App->particles->explosion, position.x, position.y, COLLIDER_NONE, 150);
		App->particles->AddParticle(App->particles->explosion, position.x + 8, position.y + 11, COLLIDER_NONE, 220);
		App->particles->AddParticle(App->particles->explosion, position.x - 7, position.y + 12, COLLIDER_NONE, 670);
		App->particles->AddParticle(App->particles->explosion, position.x + 5, position.y - 5, COLLIDER_NONE, 480);
		App->particles->AddParticle(App->particles->explosion, position.x - 4, position.y - 4, COLLIDER_NONE, 350);
		Disable();
		turbo = false;
		
	}
}