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
	tentacl.PushBack({ 817, 746, 19, 9 });
	tentacl.PushBack({ 849, 747, 19, 7 });
	tentacl.PushBack({ 881, 748, 19, 6 });
	tentacl.PushBack({ 913, 748, 19, 7 });
	tentacl.speed = 0.2f;

	toptentacle.PushBack({ 733,747,4,11 }); //vertical - 0
	toptentacle.PushBack({ 748,747,7,10 }); //1st front - 1 
	toptentacle.PushBack({ 763,748,9,8 });  //2nd front - 2
	toptentacle.PushBack({ 778,749,10,6 }); //3rd front - 3
	toptentacle.PushBack({ 794, 750,11,4 }); //horitzontal front - 4
	toptentacle.loop = false;
	toptentacle.speed = 0.2f;
	//toptentacle.PushBack({ 215,37,10,6 }); //5st front down - 5
	//toptentacle.PushBack({ 200,36,9,8 }); //6st front - 6
	//toptentacle.PushBack({ 186,35,7,10 }); //7st front - 7
	toptentacleback.PushBack({ 913,763,7,10 }); //1st back - 8
	toptentacleback.PushBack({ 927,764,9,8 }); //2nd back - 9
	toptentacleback.PushBack({ 942,765,10,6 }); //3rd back - 10
	toptentacleback.PushBack({ 939,824,11,4 }); //horitzontal back - 11
	toptentacleback.loop = false;
	toptentacleback.speed = 0.2f;
	//toptentacle.PushBack({ 211,77,10,6 }); //5st back - 12
	//toptentacle.PushBack({ 227,76,9,8 }); //6st back - 13
	//toptentacle.PushBack({ 243,75,7,10 }); //7st back - 14
	
}

ModuleTentacles::~ModuleTentacles()
{}

bool ModuleTentacles::Start()
{
	position.x = App->player->position.x + 10;
	position.y = App->player->position.y - 43;
	hand_down.x = position.x;
	hand_down.y = App->player->position.y + 57;
	tentacleposition.x = position.x + 7;
	tentacleposition.y = position.y + 10;
	graphics = App->textures->Load("Sprites_Assets/all_enemies.png");
	return true;
}

bool ModuleTentacles::CleanUp()
{
	graphics = nullptr;
	return true;
}

update_status ModuleTentacles::Update()
{
	hand_down.x = position.x;
	
	limitTentacles();//tentacle limits
	/*tentaclemove();*/
	limitArm(position);
	/*current_animationTentacle = &toptentacle;

	if (gofront == true)
	{
		current_animationTentacle = &toptentacle;
	}

	if (goback == true)
		current_animationTentacle = &toptentacleback;

	App->render->Blit(graphics, tentacleposition.x, tentacleposition.y, &(current_animationTentacle->GetCurrentFrame()));*/
	
	current_animation = &tentacl;
	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
	App->render->Blit(graphics, hand_down.x, hand_down.y, &(current_animation->GetCurrentFrame()));
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

	if (hand_down.y < App->player->position.y)
	{
		hand_down.y = App->player->position.y;
	}
	if (hand_down.y > App->player->position.y + limit)
	{
		hand_down.y = App->player->position.y + limit;
	}
	if (hand_down.x < App->player->position.x - limit)
	{
		hand_down.x = App->player->position.x - limit;

	}
	if (hand_down.x > App->player->position.x + limit)
	{
		hand_down.x = App->player->position.x + limit;
	}
}

//void ModuleTentacles::tentaclemove()
//{
//	if (tentacleposition.y >= position.y)
//	{
//		if (tentacleposition.x == position.x + 1 && tentacleposition.x == position.x)
//		{
//			toptentacle.current_frame = 4;
//			tentacleposition.y = position.y - 4;
//		}
//
//		if (tentacleposition.x == position.x + 2)
//		{
//			toptentacle.current_frame = 5;
//			tentacleposition.y = position.y - 4;
//		}
//
//		if (tentacleposition.x == position.x + 3 || tentacleposition.x == position.x + 4)
//		{
//			toptentacle.current_frame = 6;
//			tentacleposition.y = position.y - 4;
//		}
//
//		if (tentacleposition.x == position.x + 5 || tentacleposition.x == position.x + 6)
//		{
//			toptentacle.current_frame = 7;
//			tentacleposition.y = position.y - 4;
//		}
//
//		if (tentacleposition.x == position.x + 7 || tentacleposition.x == position.x + 8)
//		{
//			toptentacle.current_frame = 0;
//			tentacleposition.y = position.y - 10;
//		}
//
//		if (tentacleposition.x == position.x + 9)
//		{
//			toptentacle.current_frame = 14;
//			tentacleposition.y = position.y - 4;
//		}
//
//		if (tentacleposition.x == position.x + 10 || tentacleposition.x == position.x + 11)
//		{
//			toptentacle.current_frame = 13;
//			tentacleposition.y = position.y - 4;
//		}
//
//		if (tentacleposition.x == position.x + 12)
//		{
//			toptentacle.current_frame = 12;
//			tentacleposition.y = position.y - 4;
//		}
//
//		if (tentacleposition.x == position.x + 13 && tentacleposition.x == position.x + 14)
//		{
//			toptentacle.current_frame = 11;
//			tentacleposition.y = position.y - 4;
//		}
//	}
//
//	else
//	{
//		if (tentacleposition.x == position.x + 1 && tentacleposition.x == position.x)
//		{
//			toptentacle.current_frame = 11;
//			tentacleposition.y = position.y - 4;
//		}
//
//		if (tentacleposition.x == position.x + 2)
//		{
//			toptentacle.current_frame = 10;
//			tentacleposition.y = position.y - 4;
//		}
//
//		if (tentacleposition.x == position.x + 3 || tentacleposition.x == position.x + 4)
//		{
//			toptentacle.current_frame = 9;
//			tentacleposition.y = position.y - 4;
//		}
//
//		if (tentacleposition.x == position.x + 5 || tentacleposition.x == position.x + 6)
//		{
//			toptentacle.current_frame = 8;
//			tentacleposition.y = position.y - 4;
//		}
//
//		if (tentacleposition.x == position.x + 7)
//		{
//			toptentacle.current_frame = 0;
//			tentacleposition.y = position.y - 10;
//		}
//
//		if (tentacleposition.x == position.x + 8 || tentacleposition.x == position.x + 9)
//		{
//			toptentacle.current_frame = 7;
//			tentacleposition.y = position.y - 4;
//		}
//
//		if (tentacleposition.x == position.x + 10 || tentacleposition.x == position.x + 11)
//		{
//			toptentacle.current_frame = 6;
//			tentacleposition.y = position.y - 4;
//		}
//
//		if (tentacleposition.x == position.x + 12)
//		{
//			toptentacle.current_frame = 5;
//			tentacleposition.y = position.y - 4;
//		}
//
//		if (tentacleposition.x == position.x + 13 && tentacleposition.x == position.x + 14)
//		{
//			toptentacle.current_frame = 4;
//			tentacleposition.y = position.y - 4;
//		}
//	}
//}

void ModuleTentacles::limitArm(iPoint pos)
{
	if (tentacleposition.x > pos.x + 12 || pos.x < App->player->position.x)
	{
		tentacleposition.x = pos.x + 12;
	}

	if (tentacleposition.x < pos.x + 3 || pos.x > App->player->position.x)
	{
		tentacleposition.x = pos.x + 3;
	}

	if (tentacleposition.y < pos.y - 4)
	{
		tentacleposition.y = pos.y - 4;
	}

	if (tentacleposition.y > pos.y + 3)
	{
		tentacleposition.y = pos.y + 3;
	}
}