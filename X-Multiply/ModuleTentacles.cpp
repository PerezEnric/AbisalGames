#include "ModuleTentacles.h"
#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"


ModuleTentacles::ModuleTentacles()
{
	graphics = NULL;
	current_animation = NULL;


	// idle animation
	tentacl.PushBack({ 218, 19, 19, 9 });
	tentacl.PushBack({ 122, 19, 19, 7 });
	tentacl.PushBack({ 154, 20, 19, 6 });
	tentacl.PushBack({ 186, 20, 19, 7 });
	tentacl.speed = 0.2f;

}

ModuleTentacles::~ModuleTentacles()
{}

bool ModuleTentacles::Start()
{
	position.x = App->player->position.x + 10;
	position.y = App->player->position.y - 43;
	graphics = App->textures->Load("Sprites_Assets/Player.png");
	return true;
}

bool ModuleTentacles::CleanUp()
{
	graphics = nullptr;
	return true;
}

update_status ModuleTentacles::Update()
{
	limitTentacles();//tentacle limits

	current_animation = &tentacl;
	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
	return UPDATE_CONTINUE;
}

void ModuleTentacles::limitTentacles()
{
	int limit = 43;
	
	if (position.y > App->player->position.y)
	{
		position.y = App->player->position.y;
	}
	if (position.y < App->player->position.y - limit)
	{
		position.y = App->player->position.y - limit;
	}
	if (position.x < App->player->position.x - limit)
	{
		position.x = App->player->position.x - limit;
		
	}
	if (position.x > App->player->position.x + limit)
	{
		position.x = App->player->position.x + limit;
	}

	
}