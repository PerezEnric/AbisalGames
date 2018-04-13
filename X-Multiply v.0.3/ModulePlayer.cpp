#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleBackground.h"


ModulePlayer::ModulePlayer()
{
	graphics = NULL;
	current_animation = NULL;

	position.x = 100;
	position.y = 100;

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
	graphics = App->textures->Load("Sprites_Assets/Player.png"); // arcade version
	return ret;
}


bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}


// Update: draw background
update_status ModulePlayer::Update()
{

	int speed = 1;

	position.x += speed;


	if(App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		position.x += (speed * 2);
		App->background->move = true;
	}

	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= (speed * 2);

		if (current_animation != &up)
		{
			up.Reset();
			current_animation = &up;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		position.y += (speed * 2);
		if (current_animation != &down)
		{
			down.Reset();
			current_animation = &down;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		
		position.x -= (speed * 2);
	}

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->explosion_shot, position.x + 37, position.y + 1);
		App->particles->AddParticle(App->particles->laser, position.x + 38, position.y + 6);
	}

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE)
		current_animation = &idle;

	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
	
	return UPDATE_CONTINUE;
}