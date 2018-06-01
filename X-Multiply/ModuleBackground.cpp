#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModuleBackground.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleTentacles.h"
#include "ModuleUI.h"




ModuleBackground::ModuleBackground()
{
	// Black background
	background.x = 0;
	background.y = 0;
	background.w = 2048;
	background.h = 768;

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

	// Sprite of enemy right dorsal
	parts.x = 282;
	parts.y = 411;
	parts.w = 109;
	parts.h = 108;

	// Sprite of enemy monster eye
	parts.x = 310;
	parts.y = 195;
	parts.w = 86;
	parts.h = 69;

	// Sprite of Green Worm Spawn
	parts.x = 173;
	parts.y = 313;
	parts.w = 99;
	parts.h = 45;

	// Sprite of enemy Monster Tail
	tail2.x = 426;
	tail2.y = 65;
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
	black_background = App->textures->Load("Sprites_Assets/background2.png");
	// Loading Monster's Head
	monster_head = App->textures->Load("Sprites_Assets/head.png");
	// Loading Monster's Body
	monster_body = App->textures->Load("Sprites_Assets/body.png");
	// Loading Monster's Tail
	monster_tail = App->textures->Load("Sprites_Assets/tail.png");
	// Loading Monster's right dorsal && Loading Green Worm Spawn && Loading Monster's mini boss eye
	enemy_parts = App->textures->Load("Sprites_Assets/all_enemies.png");
	//Loading Level Music
	//lvl2_music = App->audio->LoadMusic("Audio_Assets/Stage_2_Music.ogg");

	//App->audio->PlayMusic(lvl2_music);

	tailpositionx = 1022;
	tailpositiony = 270;
	taildown = false;

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

	App->collision->AddCollider({ 340, 287, 35, 10 }, COLLIDER_WALL); // down body
	App->collision->AddCollider({ 377, 292, 10, 15 }, COLLIDER_WALL); // down body
	App->collision->AddCollider({ 391, 306, 10, 18 }, COLLIDER_WALL); // down body
	App->collision->AddCollider({ 400, 315, 100, 10 }, COLLIDER_WALL); // down body
	App->collision->AddCollider({ 430, 322, 10, 10 }, COLLIDER_WALL); // down body
	App->collision->AddCollider({ 500, 310, 20, 10 }, COLLIDER_WALL); // down body
	App->collision->AddCollider({ 510, 304, 20, 10 }, COLLIDER_WALL); // down body
	App->collision->AddCollider({ 530, 298, 20, 10 }, COLLIDER_WALL); // down body
	App->collision->AddCollider({ 550, 305, 50, 10 }, COLLIDER_WALL); // down body
	App->collision->AddCollider({ 560, 305, 20, 17 }, COLLIDER_WALL); // down body
	App->collision->AddCollider({ 600, 310, 20, 9 }, COLLIDER_WALL); // down body
	App->collision->AddCollider({ 632, 315, 46, 11 }, COLLIDER_WALL); // down body
	App->collision->AddCollider({ 675, 310, 46, 11 }, COLLIDER_WALL); // down body
	App->collision->AddCollider({ 717, 315, 30, 11 }, COLLIDER_WALL); // down body



	App->collision->AddCollider({ 735, 200, 12, 20 }, COLLIDER_ENEMY); // monster eye
	App->collision->AddCollider({ 738, 185, 12, 12 }, COLLIDER_ENEMY); // monster eye
	App->collision->AddCollider({ 741, 170, 24, 24 }, COLLIDER_ENEMY); // monster eye
	App->collision->AddCollider({ 747, 165, 24, 10 }, COLLIDER_ENEMY); // monster eye
	App->collision->AddCollider({ 760, 162, 24, 10 }, COLLIDER_ENEMY); // monster eye


	//Dorsal Fin colliders

	//App->collision->AddCollider({ 452, 124, 63, 50 }, COLLIDER_ENEMY); // left dorsal collider
	//App->collision->AddCollider({ 515, 115, 10, 30 }, COLLIDER_ENEMY); // middle dorsal collider
	//App->collision->AddCollider({ 515, 138, 50, 90 }, COLLIDER_ENEMY); // middle dorsal collider
	//App->collision->AddCollider({ 560, 130, 80, 108 }, COLLIDER_ENEMY); // right dorsal collider

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

	App->collision->AddCollider({ 750, 310, 30, 11 }, COLLIDER_WALL); // down tail
	App->collision->AddCollider({ 775, 312, 20, 14 }, COLLIDER_WALL); // down tail
	App->collision->AddCollider({ 782, 315, 20, 14 }, COLLIDER_WALL); // down tail
	App->collision->AddCollider({ 795, 325, 20, 10 }, COLLIDER_WALL); // down tail
	App->collision->AddCollider({ 815, 327, 33, 10 }, COLLIDER_WALL); // down tail
	App->collision->AddCollider({ 860, 333, 33, 6 }, COLLIDER_WALL); // down tail
	App->collision->AddCollider({ 892, 337, 53, 6 }, COLLIDER_WALL); // down tail
	App->collision->AddCollider({ 942, 330, 20, 10 }, COLLIDER_WALL); // down tail
	App->collision->AddCollider({ 950, 328, 30, 6 }, COLLIDER_WALL); // down tail
	App->collision->AddCollider({ 980, 326, 60, 6 }, COLLIDER_WALL); // down tail
	App->collision->AddCollider({ 1040, 325, 60, 6 }, COLLIDER_WALL); // down tail

	App->collision->AddCollider({997, 252, 9, 10 }, COLLIDER_ENEMY); // monster house
	App->collision->AddCollider({ 1006, 250, 9, 10 }, COLLIDER_ENEMY); // monster house
	App->collision->AddCollider({ 1015, 255, 35, 10 }, COLLIDER_ENEMY); // monster house

	App->collision->AddCollider({ 1055, 263, 20, 10 }, COLLIDER_ENEMY); // monster tail
	App->collision->AddCollider({ 1072, 269, 20, 10 }, COLLIDER_ENEMY); // monster tail
	App->collision->AddCollider({ 1090, 275, 20, 10 }, COLLIDER_ENEMY); // monster tail
	App->collision->AddCollider({ 1110, 275, 16, 10 }, COLLIDER_WALL); // monster tail
	App->collision->AddCollider({ 1128, 280, 55, 10 }, COLLIDER_WALL); // monster tail
	App->collision->AddCollider({ 1180, 285, 30, 10 }, COLLIDER_WALL); // monster tail
	App->collision->AddCollider({ 1210, 278, 10, 10 }, COLLIDER_WALL); // monster tail

	//Enemies

	App->enemies->AddEnemy(ENEMY_TYPES::SHRIMP, 500, 40);
	App->enemies->AddEnemy(ENEMY_TYPES::TAIL, 1022, 270);
	App->enemies->AddEnemy(ENEMY_TYPES::LATERALFIN, 770, 290);
	App->enemies->AddEnemy(ENEMY_TYPES::LATERALFIN, 530, 270);
	App->enemies->AddEnemy(ENEMY_TYPES::LEFTLITTLEDORSAL, 452, 124);
	App->enemies->AddEnemy(ENEMY_TYPES::LEFTDORSAL, 452, 124);
	App->enemies->AddEnemy(ENEMY_TYPES::MIDDLELITTLEDORSAL, 510, 115);
	App->enemies->AddEnemy(ENEMY_TYPES::MIDDLEDORSAL, 510, 115);
	App->enemies->AddEnemy(ENEMY_TYPES::RIGHTLITTLEDORSAL, 530, 130);
	App->enemies->AddEnemy(ENEMY_TYPES::RIGHTDORSAL, 530, 130);
	App->enemies->AddEnemy(ENEMY_TYPES::MASK, 731, 160);
	App->enemies->AddEnemy(ENEMY_TYPES::SPAWN, 992, 252);
	App->enemies->AddEnemy(ENEMY_TYPES::BLUE_JUMPING, 100, -50);
	App->enemies->AddEnemy(ENEMY_TYPES::PU, 200, 30);
	App->enemies->AddEnemy(ENEMY_TYPES::GWORM, 300, 30);
	App->enemies->AddEnemy(ENEMY_TYPES::BWORM, 400, 30);

	//Power Ups
	App->enemies->AddEnemy(ENEMY_TYPES::SPEEDUP, 300, 50);
	App->enemies->AddEnemy(ENEMY_TYPES::TENTACLES, 250, 50);
	App->enemies->AddEnemy(ENEMY_TYPES::WAVES, 320, 50);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMB, 360, 50);

	//Camera
	App->render->camera.x += 201;//inical camera position
	App->render->camera.y += 30;
	App->render->back_limit -= 201;//inicial limit position
	App->render->up_limit -= 30;
	App->player->position.x -= 201;// inicial player position

	return ret;
}
bool ModuleBackground::CleanUp()
{
	LOG("Unloading second level scene");
	bool ret = true;

	App->textures->Unload(black_background);
	black_background = nullptr;
	App->textures->Unload(monster_head);
	monster_head = nullptr;
	App->textures->Unload(monster_body);
	monster_body = nullptr;
	App->textures->Unload(monster_tail);
	monster_tail = nullptr;
	/*App->audio->UnloadMusic(lvl2_music);
	lvl2_music = nullptr;*/

	return ret;
}
// Update: draw background
update_status ModuleBackground::Update()
{
	// Draw everything --------------------------------------
	
	App->render->Blit(black_background, -201, 0, &background); // background
	App->render->Blit(monster_head, 180, 150, &head); // head
	App->render->Blit(monster_body, 241, 119, &body); // body
	App->render->Blit(monster_tail, 753, 160, &tail); // tail
	App->render->Blit(enemy_parts, tailpositionx, tailpositiony, &tail2);
	
	//App->render->Blit(enemy_parts, 992, 252, &parts); //green worm spawn
	
	if (taildown == true)
		tailpositiony += 1;

	camera();
	cameralimit();

	return UPDATE_CONTINUE;
}


//camera move
void ModuleBackground::camera()
{
	if (!go_back)
	{
		if (App->render->camera.x <= 250 && App->render->camera.x > -380)
		{
			App->render->move_front = !App->render->move_front;
		}
		if (App->render->camera.x <= -220 && App->render->camera.x > -320)
		{
			App->render->move_down = !App->render->move_down;
		}
		if (App->render->camera.x <= -320 && App->render->camera.x > -380)
		{
			App->render->move_down = false;
			App->render->move_up = !App->render->move_up;
		}

		if (App->render->camera.x == -380)
		{
			App->render->move_front = false;

			if (App->render->camera.y == -5)
			{
				App->render->change_move = true;
				move_cont++;
			}

			if ((App->render->camera.y == -65 && move_cont % 2 == 1)
				|| (App->render->camera.y == -85 && move_cont % 2 == 0))
				App->render->change_move = false;

			if (move_cont == 4)
			{
				App->render->move_front = !App->render->move_front;
				App->render->move_up = false;
				App->render->move_down = false;
			}

			else if (App->render->change_move == true)
			{
				App->render->move_up = false;
				App->render->move_down = !App->render->move_down;
			}
			else if (App->render->change_move == false && move_cont % 2 == 1)
			{
				App->render->move_up = !App->render->move_up;
				App->render->move_down = false;
			}

			else if (App->render->change_move == false && move_cont % 2 == 0)
			{
				App->render->move_up = !App->render->move_up;
				App->render->move_down = false;
			}

		}

		if (App->render->camera.x <= -381 && App->render->camera.x > -430)
		{
			App->render->move_front = !App->render->move_front;
		}

		if (App->render->camera.x <= -430 && App->render->camera.x > -570)
		{
			App->render->move_down = !App->render->move_down;
			App->render->move_front = true;

		}

		if (App->render->camera.x <= -570 && App->render->camera.x > -720)
		{
			App->render->move_front = !App->render->move_front;
		}

		if (App->render->camera.x <= -720 && App->render->camera.x > -870)
		{
			App->render->move_down = !App->render->move_down;
			App->render->move_front = !App->render->move_front;
		}

		if (App->render->camera.x == -870)
		{
			App->render->move_down = false;
			App->render->move_front = false;
			go_back = true;
		}
	}
	//back move
	else
	{
		if (App->render->camera.x < -830)
		{
			App->render->move_up = false;
			App->render->move_down = false;
			App->render->move_front = false;
			App->render->move_back = true;
		}
		else if (App->render->camera.x < -740)
		{
			App->render->move_back = !App->render->move_back;
			App->render->move_up = !App->render->move_up;
		}
		else if(App->render->camera.x < -680)
		{
			App->render->move_up = false;
			App->render->move_back = !App->render->move_back;
			App->render->move_down = !App->render->move_down;
		}
		else if(App->render->camera.x < -540)
		{
			App->render->move_back = !App->render->move_back;
			App->render->move_down = false;
		}
		else if (App->render->camera.x < -450)
		{
			App->render->move_back = true;
			App->render->move_up = true;
		}

		else if (App->render->camera.x < -310)
		{
			App->render->move_back = !App->render->move_back;
			App->render->move_up = false;
		}

		else if (App->render->camera.x < -220)
		{
			App->render->move_back = !App->render->move_back;
			App->render->move_down = !App->render->move_down;
		}

		else if (App->render->camera.x < -180)
		{
			App->render->move_down = false;
			App->render->move_back = !App->render->move_back;
			App->render->move_up = !App->render->move_up;
		}

		else
		{
			App->render->move_back = false;
			App->render->move_up = false;
			App->render->move_down = false;
			App->render->move_front = false;
		}
	}
}

void ModuleBackground::cameralimit()
{
	//back limit
	if (App->render->back_limit > App->player->position.x)
	{
		App->player->position.x = App->render->back_limit;
	}
	//front limit
	if (App->render->back_limit + App->render->camera.w - 35 < App->player->position.x)
	{
		App->player->position.x = App->render->back_limit + App->render->camera.w - 35;
	}
	//up limit
	if (App->render->up_limit > App->player->position.y)
	{
		App->player->position.y = App->render->up_limit;
	}
	//down limit
	if (App->render->up_limit + App->render->camera.h - 14 < App->player->position.y)
	{
		App->player->position.y = App->render->up_limit + App->render->camera.h - 14;
	}
}