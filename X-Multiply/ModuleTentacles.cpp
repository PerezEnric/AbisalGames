#include "ModuleTentacles.h"
#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"

ModuleTentacles::ModuleTentacles()
{
	//graphics = NULL;
	//current_animation = NULL;

	//position.x = 10;
	//position.y = 10;

	//// idle animation
	//idle.PushBack({ 101, 1, 35, 14 });

	//idle.speed = 0.2f;
	App->player->position.x += 1;
	App->player->position.x -= 1;
}

ModuleTentacles::~ModuleTentacles()
{}

bool ModuleTentacles::Start()
{
	return true;
}

bool ModuleTentacles::CleanUp()
{
	return true;
}

update_status ModuleTentacles::Update()
{
	return UPDATE_CONTINUE;
}