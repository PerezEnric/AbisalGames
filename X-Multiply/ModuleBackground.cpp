#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModuleBackground.h"
#include "ModulePlayer.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleBackground::ModuleBackground()
{
	// Black background
	background.x = 0;
	background.y = 128;
	background.w = 512;
	background.h = 256;

	// Sprite of Monster's Head
	head.x = 96;
	head.y = 98;
	head.w = 61;
	head.h = 64;

	// Sprite of Monster's body
	body.x = 0;
	body.y = 148;
	body.w = 512;
	body.h = 216;

	// Sprite of Monster's Tail
	tail.x = 77;
	tail.y = 69;
	tail.w = 364;
	tail.h = 186;

	// Sprite of enemy left dorsal
	left_dorsal.x = 22;
	left_dorsal.y = 21;
	left_dorsal.w = 63;
	left_dorsal.h = 99;

	// Sprite of enemy middle dorsal
	middle_dorsal.x = 143;
	middle_dorsal.y = 11;
	middle_dorsal.w = 70;
	middle_dorsal.h = 110;

	// Sprite of enemy right dorsal
	right_dorsal.x = 257;
	right_dorsal.y = 9;
	right_dorsal.w = 109;
	right_dorsal.h = 108;

	// Sprite of enemy monster eye
	eye.x = 138;
	eye.y = 24;
	eye.w = 86;
	eye.h = 69;

	// Sprite of Green Worm Spawn
	spawn.x = 14;
	spawn.y = 10;
	spawn.w = 99;
	spawn.h = 45;

	// Sprite of enemy Monster Tail
	tail2.x = 34;
	tail2.y = 13;
	tail2.w = 219;
	tail2.h = 57;
}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	// Loading black background
	black_background = App->textures->Load("Sprites_Assets/Background2.png");
	// Loading Monster's Head
	monster_head = App->textures->Load("Sprites_Assets/head.png");
	// Loading Monster's Body
	monster_body = App->textures->Load("Sprites_Assets/body.png");
	// Loading Monster's Tail
	monster_tail = App->textures->Load("Sprites_Assets/tail.png");
	// Loading Monster's left dorsal
	enemy_left_dorsal = App->textures->Load("Sprites_Assets/Enemies/dorsal.png");
	// Loading Monster's middle dorsal
	enemy_middle_dorsal = App->textures->Load("Sprites_Assets/Enemies/dorsal.png");
	// Loading Monster's right dorsal
	enemy_right_dorsal = App->textures->Load("Sprites_Assets/Enemies/dorsal.png");
	// Loading Monster's mini boss eye
	monster_eye = App->textures->Load("Sprites_Assets/Enemies/monstereye.png");
	// Loading Green Worm Spawn
	greenworm_spawn = App->textures->Load("Sprites_Assets/Enemies/monsterhouse.png");
	// Loading Monster's Tail
	monster_tail2 = App->textures->Load("Sprites_Assets/Enemies/tail.png");
	// Loading second level music
	//secondlvlmusic = App->audio->LoadMusic("Audio_Assets/Stage_2_Music.ogg");
	// Playing second level music
	//App->audio->PlayMusic(secondlvlmusic);

	// Head colliders
	App->collision->AddCollider({ 182, 157, 30, 30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 242, 148, 12, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 256, 142, 30, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 275, 139, 10, 5 }, COLLIDER_WALL);
	App->collision->AddCollider({ 285, 135, 20, 5 }, COLLIDER_WALL); //fin
	App->collision->AddCollider({ 295, 130, 20, 5 }, COLLIDER_WALL); // fin
	App->collision->AddCollider({ 307, 123, 20, 5 }, COLLIDER_WALL); // fin
	App->collision->AddCollider({ 296, 142, 50, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 347, 145, 10, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 188, 180, 31, 20 }, COLLIDER_WALL);
	App->collision->AddCollider({ 214, 197, 61, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 203, 152, 40, 15 }, COLLIDER_WALL);
	App->collision->AddCollider({ 260, 201, 35, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 290, 210, 35, 10 }, COLLIDER_WALL);

	// Body colliders
	App->collision->AddCollider({370, 147, 15, 10}, COLLIDER_WALL); // top body
	App->collision->AddCollider({ 390, 143, 40, 10 }, COLLIDER_WALL); // top body
	App->collision->AddCollider({ 430, 146, 12, 10 }, COLLIDER_WALL); // top body
	App->collision->AddCollider({ 442, 149, 12, 10 }, COLLIDER_WALL); // top body
	App->collision->AddCollider({ 640, 238, 100, 10 }, COLLIDER_WALL); // top body
	App->collision->AddCollider({ 730, 219, 12, 30 }, COLLIDER_WALL); // top body

	App->collision->AddCollider({ 735, 200, 12, 20 }, COLLIDER_ENEMY); // monster eye
	App->collision->AddCollider({ 738, 185, 12, 12 }, COLLIDER_ENEMY); // monster eye
	App->collision->AddCollider({ 741, 170, 24, 24 }, COLLIDER_ENEMY); // monster eye
	App->collision->AddCollider({ 747, 165, 24, 10 }, COLLIDER_ENEMY); // monster eye
	App->collision->AddCollider({ 760, 162, 24, 10 }, COLLIDER_ENEMY); // monster eye

	// Dorsal fin colliders
	App->collision->AddCollider({ 452, 124, 63, 50 }, COLLIDER_ENEMY); // left dorsal collider
	App->collision->AddCollider({ 515, 115, 10, 30 }, COLLIDER_ENEMY); // middle dorsal collider
	App->collision->AddCollider({ 515, 138, 50, 90 }, COLLIDER_ENEMY); // middle dorsal collider
	App->collision->AddCollider({ 560, 130, 80, 108 }, COLLIDER_ENEMY); // right dorsal collider

	// Tail colliders
	App->collision->AddCollider({ 785, 162, 48, 10 }, COLLIDER_WALL); // top tail
	App->collision->AddCollider({ 835, 167, 15, 10 }, COLLIDER_WALL); // top tail
	App->collision->AddCollider({ 850, 169, 18, 10 }, COLLIDER_WALL); // top tail
	App->collision->AddCollider({ 870, 174, 15, 10 }, COLLIDER_WALL); // top tail
	App->collision->AddCollider({ 885, 178, 12, 10 }, COLLIDER_WALL); // top tail
	App->collision->AddCollider({ 892, 188, 14, 10 }, COLLIDER_WALL); // top tail
	App->collision->AddCollider({ 900, 192, 9, 10 }, COLLIDER_WALL); // top tail
	App->collision->AddCollider({ 907, 197, 9, 10 }, COLLIDER_WALL); // top tail
	App->collision->AddCollider({ 909, 207, 9, 10 }, COLLIDER_WALL); // top tail
	App->collision->AddCollider({ 918, 215, 9, 10 }, COLLIDER_WALL); // top tail
	App->collision->AddCollider({ 921, 221, 9, 10 }, COLLIDER_WALL); // top tail
	App->collision->AddCollider({ 925, 225, 9, 10 }, COLLIDER_WALL); // top tail
	App->collision->AddCollider({ 927, 233, 9, 10 }, COLLIDER_WALL); // top tail
	App->collision->AddCollider({ 935, 236, 9, 10 }, COLLIDER_WALL); // top tail
	App->collision->AddCollider({ 940, 243, 9, 10 }, COLLIDER_WALL); // top tail
	App->collision->AddCollider({ 944, 250, 9, 10 }, COLLIDER_WALL); // top tail
	App->collision->AddCollider({ 955, 258, 50, 10 }, COLLIDER_WALL); // top tail
	App->collision->AddCollider({997, 252, 9, 10 }, COLLIDER_ENEMY); // monster house
	App->collision->AddCollider({ 1006, 250, 9, 10 }, COLLIDER_ENEMY); // monster house
	App->collision->AddCollider({ 1015, 255, 35, 10 }, COLLIDER_ENEMY); // monster house

	
	App->render->camera.x += 201;//inical camera posicion
	App->render->camera.y += 30;
	App->player->position.x -= 201;// inicial player position

	return ret;
}

// Update: draw background
update_status ModuleBackground::Update()
{
	// Draw everything --------------------------------------
	
	App->render->Blit(black_background, 0, 0, &background); // background
	App->render->Blit(monster_head, 180, 150, &head); // head
	App->render->Blit(monster_body, 241, 119, &body); // body
	App->render->Blit(monster_tail, 753, 160, &tail); // tail
	App->render->Blit(enemy_left_dorsal, 452, 124, &left_dorsal); // left dorsal
	App->render->Blit(enemy_middle_dorsal, 510, 115, &middle_dorsal); // middle dorsal
	App->render->Blit(enemy_right_dorsal, 531, 130, &right_dorsal); // right dorsal
	App->render->Blit(monster_eye, 730, 160, &eye); // monster eye mini boss
	App->render->Blit(monster_tail2, 1000, 270, &tail2); // monster tail
	App->render->Blit(greenworm_spawn, 992, 252, &spawn); //green worm spawn
	

	//camera();

	return UPDATE_CONTINUE;
}


//camera move
//void ModuleBackground::camera()
//{
//	if (!go_back)
//	{
//		if (App->render->camera.x <= 250 && App->render->camera.x > -380)
//		{
//			App->render->move_front = !App->render->move_front;
//		}
//		if (App->render->camera.x <= -220 && App->render->camera.x > -320)
//		{
//			App->render->move_down = !App->render->move_down;
//		}
//		if (App->render->camera.x <= -320 && App->render->camera.x > -380)
//		{
//			App->render->move_down = false;
//			App->render->move_up = !App->render->move_up;
//		}
//
//		if (App->render->camera.x == -380)
//		{
//			App->render->move_front = false;
//
//			if (App->render->camera.y == -5)
//			{
//				App->render->change_move = true;
//				move_cont++;
//			}
//
//			if ((App->render->camera.y == -65 && move_cont % 2 == 1)
//				|| (App->render->camera.y == -85 && move_cont % 2 == 0))
//				App->render->change_move = false;
//
//			if (move_cont == 4)
//			{
//				App->render->move_front = !App->render->move_front;
//				App->render->move_up = false;
//				App->render->move_down = false;
//			}
//
//			else if (App->render->change_move == true)
//			{
//				App->render->move_up = false;
//				App->render->move_down = !App->render->move_down;
//			}
//			else if (App->render->change_move == false && move_cont % 2 == 1)
//			{
//				App->render->move_up = !App->render->move_up;
//				App->render->move_down = false;
//			}
//
//			else if (App->render->change_move == false && move_cont % 2 == 0)
//			{
//				App->render->move_up = !App->render->move_up;
//				App->render->move_down = false;
//			}
//
//		}
//
//		if (App->render->camera.x <= -381 && App->render->camera.x > -430)
//		{
//			App->render->move_front = !App->render->move_front;
//		}
//
//		if (App->render->camera.x <= -430 && App->render->camera.x > -570)
//		{
//			App->render->move_down = !App->render->move_down;
//			App->render->move_front = true;
//
//		}
//
//		if (App->render->camera.x <= -570 && App->render->camera.x > -720)
//		{
//			App->render->move_front = !App->render->move_front;
//		}
//
//		if (App->render->camera.x <= -720 && App->render->camera.x > -870)
//		{
//			App->render->move_down = !App->render->move_down;
//			App->render->move_front = !App->render->move_front;
//		}
//
//		if (App->render->camera.x == -870)
//		{
//			App->render->move_down = false;
//			App->render->move_front = false;
//			go_back = true;
//		}
//	}
//	//back move
//	else
//	{
//		if (App->render->camera.x < -830)
//		{
//			App->render->move_up = false;
//			App->render->move_down = false;
//			App->render->move_front = false;
//			App->render->move_back = true;
//		}
//		else if (App->render->camera.x < -740)
//		{
//			App->render->move_back = !App->render->move_back;
//			App->render->move_up = !App->render->move_up;
//		}
//		else if(App->render->camera.x < -680)
//		{
//			App->render->move_up = false;
//			App->render->move_back = !App->render->move_back;
//			App->render->move_down = !App->render->move_down;
//		}
//		else if(App->render->camera.x < -540)
//		{
//			App->render->move_back = !App->render->move_back;
//			App->render->move_down = false;
//		}
//		else if (App->render->camera.x < -450)
//		{
//			App->render->move_back = true;
//			App->render->move_up = true;
//		}
//
//		else if (App->render->camera.x < -310)
//		{
//			App->render->move_back = !App->render->move_back;
//			App->render->move_up = false;
//		}
//
//		else if (App->render->camera.x < -220)
//		{
//			App->render->move_back = !App->render->move_back;
//			App->render->move_down = !App->render->move_down;
//		}
//
//		else if (App->render->camera.x < -180)
//		{
//			App->render->move_down = false;
//			App->render->move_back = !App->render->move_back;
//			App->render->move_up = !App->render->move_up;
//		}
//
//		else
//		{
//			App->render->move_back = false;
//			App->render->move_up = false;
//			App->render->move_down = false;
//			App->render->move_front = false;
//		}
//	}
//}