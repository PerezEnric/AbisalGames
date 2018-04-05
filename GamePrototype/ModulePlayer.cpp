#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	position.x = 100;
	position.y = 220;

	// idle animation (arcade sprite sheet)
	idle.PushBack({90, 0, 50, 18});
	
	idle.speed = 0.2f;

	//forward animation

	forward.PushBack({ 90, 0, 50, 18 });
	forward.speed = 0.1f;

	//backward animation
	backward.PushBack({ 90, 0, 50, 18 });
	backward.speed = 0.1f;

	//upward animation

	up.PushBack({ 0, 0, 50, 18 });

	//downward animation
	

	down.PushBack({ 185, 0, 50, 18 });
	
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Player.png"); // arcade version
	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;

	int speed = 1;

	if(App->input->keyboard[SDL_SCANCODE_D] == 1)
	{
		current_animation = &forward;
		position.x += speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_W] == 1)
	{
		current_animation = &up;
	
		position.y -= speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_S] == 1)
	{
		current_animation = &down;
		position.y += speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_A] == 1)
	{
		current_animation = &backward;
		position.x -= speed;
	}

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);
	
	return UPDATE_CONTINUE;
}