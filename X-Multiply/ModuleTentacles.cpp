#include "ModuleTentacles.h"
#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"


ModuleTentacles::ModuleTentacles()
{
	graphics = nullptr;
	current_animation = nullptr;
	current_animationTentacle = nullptr;

	// idle animation
	tentacl.PushBack({ 218, 19, 19, 9 });
	tentacl.PushBack({ 122, 19, 19, 7 });
	tentacl.PushBack({ 154, 20, 19, 6 });
	tentacl.PushBack({ 186, 20, 19, 7 });
	tentacl.speed = 0.2f;

	toptentacle.PushBack({ 6,19,4,11 }); //vertical - 0
	toptentacle.PushBack({ 21,19,7,10 }); //1st front - 1 
	toptentacle.PushBack({ 36,20,9,8 });  //2nd front - 2
	toptentacle.PushBack({ 51,21,10,6 }); //3rd front - 3
	toptentacle.PushBack({ 67,22,11,4 }); //4th front - 4
	toptentacle.PushBack({ 215,37,10,6 }); //5st front - 5
	toptentacle.PushBack({ 200,36,9,8 }); //6st front - 6
	toptentacle.PushBack({ 186,35,7,10 }); //7st front - 7
	toptentacle.PushBack({ 241,53,7,10 }); //1st back - 8
	toptentacle.PushBack({ 224,54,9,8 }); //2nd back - 9
	toptentacle.PushBack({ 208,55,10,6 }); //3rd back - 10
	toptentacle.PushBack({ 212,96,11,4 }); //4th back - 11
	toptentacle.PushBack({ 211,77,10,6 }); //5st back - 12
	toptentacle.PushBack({ 227,76,9,8 }); //6st back - 13
	toptentacle.PushBack({ 243,75,7,10 }); //7st back - 14
	toptentacle.loop = false;
	toptentacle.speed = 0.2f;
}

ModuleTentacles::~ModuleTentacles()
{}

bool ModuleTentacles::Start()
{
	position.x = App->player->position.x + 10;
	position.y = App->player->position.y - 43;
	tentacleposition.x = position.x + 8;
	tentacleposition.y = position.y;
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

	current_animationTentacle = &toptentacle;
	limitTentacles();//tentacle limits
	tentaclemove();
	tentacleposition.y = position.y;

	App->render->Blit(graphics, tentacleposition.x, tentacleposition.y, &(current_animationTentacle->GetCurrentFrame()));

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

void ModuleTentacles::tentaclemove()
{
	if (tentacleposition.x > position.x && tentacleposition.x < position.x + 16)
	{
		toptentacle.current_frame = 0;
	}

	else if (tentacleposition.x >= position.x + 16 && tentacleposition.x < position.x + 24)
	{
		toptentacle.current_frame = 1;
	}
	else if (tentacleposition.x >= position.x -16 && tentacleposition.x < position.x)
	{
		toptentacle.current_frame = 8;
	}
	else
	{
		toptentacle.current_frame = 3;
	}
}