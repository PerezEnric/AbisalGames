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
#include "ModuleParticles.h"
#include "Enemy_Boss.h"
#include "ModuleFadeToBlack.h"



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
	Enable();
	App->player->Enable();
	App->ui->Enable();
	App->enemies->Enable();
	App->particles->Enable();

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

	App->collision->AddCollider({ 460, 160, 50, 70 }, COLLIDER_WALL); // left dorsal collider
	App->collision->AddCollider({ 515, 160, 50, 70 }, COLLIDER_WALL); // middle dorsal collider
	App->collision->AddCollider({ 560, 170, 50, 65 }, COLLIDER_WALL); // right dorsal collider

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


	//Enemies

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
	
	App->enemies->AddEnemy(ENEMY_TYPES::BWORM, 750, 300);
	App->enemies->AddEnemy(ENEMY_TYPES::BWORM, 720, 300);
	App->enemies->AddEnemy(ENEMY_TYPES::BWORM, 690, 300);
	App->enemies->AddEnemy(ENEMY_TYPES::BWORM, 660, 310);
	App->enemies->AddEnemy(ENEMY_TYPES::BWORM, 630, 300);
	App->enemies->AddEnemy(ENEMY_TYPES::BWORM, 600, 310);
	App->enemies->AddEnemy(ENEMY_TYPES::BWORM, 490, 300);
	App->enemies->AddEnemy(ENEMY_TYPES::BWORM, 460, 300);
	App->enemies->AddEnemy(ENEMY_TYPES::BWORM, 430, 300);
	App->enemies->AddEnemy(ENEMY_TYPES::BWORM, 400, 300);

	// Enemy Boss
	App->enemies->AddEnemy(ENEMY_TYPES::BOSS, 260, 217);
	

	//Camera
	App->render->camera.x = 201;//inical camera position
	App->render->camera.y = 30;
	App->render->back_limit = -App->render->camera.x;//inicial limit position
	App->render->up_limit = -App->render->camera.y;
	App->player->position.x = -App->render->camera.x;// inicial player position

	boss_wakeup = false;
	go_back = false;
	cdenemys = 0;

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
	spawnenemies();
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
	if (expboss == true)
	{
		bossexplosions();
		win = true;
		App->fade->FadeToBlack((Module*)App->background, (Module*)App->win_lose);
	}

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
			App->render->move_back = false;
			App->render->move_up = false;
			App->render->move_down = false;
			
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

		if (App->render->camera.x <= -720 && App->render->camera.x > -890 && !tail_powerup)
		{
			App->render->move_down = !App->render->move_down;
			App->render->move_front = !App->render->move_front;
		}

		else if (App->render->camera.x <= -860 && tail_powerup)
		{
			App->render->move_down = false;
			App->render->move_front = false;
		}

		if (App->render->camera.x == -890)
		{
			App->render->move_down = true;
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
			App->render->move_down = !App->render->move_down;
			App->render->move_front = false;
			App->render->move_back = true;
		}
		else if (App->render->camera.x < -740)
		{
			App->render->move_back = !App->render->move_back;
			App->render->move_up = !App->render->move_up;
		}
		else if (App->render->camera.x < -680)
		{
			App->render->move_up = false;
			App->render->move_back = !App->render->move_back;
			App->render->move_down = !App->render->move_down;
		}
		else if (App->render->camera.x < -540)
		{
			App->render->move_back = !App->render->move_back;
			App->render->move_down = false;
		}
		else if (App->render->camera.x < -470)
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

		else if (App->render->camera.x < -160)
		{
			App->render->move_down = false;
			App->render->move_back = !App->render->move_back;
			App->render->move_up =true;
		}

		else if (App->render->camera.x < 0)
		{
			App->render->move_back = true;
			App->render->move_up = false;
			App->render->move_down = false;
			App->render->move_front = false;
		}

		else if (App->render->camera.x < 30)
		{
			boss_wakeup = true;
		}

		else if (App->render->camera.x < 80)
		{
			App->render->move_back = !App->render->move_back;
			App->render->move_up = false;
			App->render->move_down = true;
			App->render->move_front = false;
		}
		else if (App->render->camera.x < 160)
		{
			App->render->move_back = !App->render->move_back;
			App->render->move_up = true;
			App->render->move_down = false;
			App->render->move_front = false;
		}
		else if (App->render->camera.x < 220)
		{
			App->render->move_back = true;
			App->render->move_up = false;
			App->render->move_down = false;
			App->render->move_front = false;
		}
		else
		{
			App->render->move_back = false;
			App->render->move_up = false;
			App->render->move_down = false;
			App->render->move_front = false;
			fight_boss = true;
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
	if (App->render->up_limit + App->render->camera.h - 42 < App->player->position.y)
	{
		App->player->position.y = App->render->up_limit + App->render->camera.h - 42;
	}
}

void ModuleBackground::bossexplosions()
{
	if (cont == 0)
	{
		App->particles->AddParticle(App->particles->boss_explosion, bossx, bossy);
		App->particles->AddParticle(App->particles->boss_explosion, bossx + 40, bossy + 50);

	}
	if (cont == 20)
	{
		App->particles->AddParticle(App->particles->boss_explosion, bossx - 10, bossy + 20);
		App->particles->AddParticle(App->particles->boss_explosion, bossx + 30, bossy + 10);

	}
	if (cont == 30)
	{
		App->particles->AddParticle(App->particles->boss_explosion, bossx - 20, bossy + 30);
		App->particles->AddParticle(App->particles->boss_explosion, bossx + 5, bossy + 15);

	}
	if (cont == 40)
	{
		App->particles->AddParticle(App->particles->boss_explosion, bossx, bossy);
		App->particles->AddParticle(App->particles->boss_explosion, bossx + 40, bossy + 50);

	}
	if (cont == 50)
	{
		App->particles->AddParticle(App->particles->boss_explosion, bossx - 30, bossy);
		App->particles->AddParticle(App->particles->boss_explosion, bossx + 20, bossy + 60);
	}
	if (cont == 60)
	{
		App->particles->AddParticle(App->particles->boss_explosion, bossx + 3, bossy + 43);
		App->particles->AddParticle(App->particles->boss_explosion, bossx + 4, bossy - 30);
	}
	if (cont == 70)
	{
		App->particles->AddParticle(App->particles->boss_explosion, bossx + 17, bossy - 32);
		App->particles->AddParticle(App->particles->boss_explosion, bossx - 30, bossy - 12);
	}
	if (cont == 80)
	{
		App->particles->AddParticle(App->particles->boss_explosion, bossx + 13, bossy - 12);
		App->particles->AddParticle(App->particles->boss_explosion, bossx - 40, bossy + 10);
	}
	if (cont == 90)
	{
		App->particles->AddParticle(App->particles->boss_explosion, bossx + 15, bossy - 37);
		App->particles->AddParticle(App->particles->boss_explosion, bossx + 20, bossy - 50);
	}
	if (cont == 100)
	{
		App->particles->AddParticle(App->particles->boss_explosion, bossx + 18, bossy - 34);
		App->particles->AddParticle(App->particles->boss_explosion, bossx - 40, bossy + 25);
		expboss = false;
	}

	cont++;
}


void ModuleBackground::die()
{
	if (App->player->live > 0)
	{
		App->fade->FadeToBlack((Module*)App->background, (Module*)App->background);
		App->enemies->Disable();
		cdenemys = 0;
	}
	else if (App->player->live == 0)
	{
		win = false;
		App->fade->FadeToBlack((Module*)App->background, (Module*)App->win_lose);
		cdenemys = 0;
	}
	App->player->Disable();
	App->particles->Disable();
}

void ModuleBackground::spawnenemies()
{
	if (cdenemys == 50)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::PU2, 200, 10);
		App->enemies->AddEnemy(ENEMY_TYPES::SPEEDUP, 202, 25);
	}
	if (cdenemys == 430)
		App->enemies->AddEnemy(ENEMY_TYPES::BLUE_JUMPING, 300, -55);

	if (cdenemys == 450)
		App->enemies->AddEnemy(ENEMY_TYPES::BLUE_JUMPING, 330, -55);

	if (cdenemys == 700)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::PU2, 510, 100);
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB, 512, 115);
	}

	if (cdenemys == 900)
	{
		moredown = true;
		App->enemies->AddEnemy(ENEMY_TYPES::BLUE_JUMPING, 600, -10);
	}

	if (cdenemys == 1000)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::PU3, 660, 100);
		App->enemies->AddEnemy(ENEMY_TYPES::TENTACLES, 662, 115);
	}

	if (cdenemys == 1080)
		App->enemies->AddEnemy(ENEMY_TYPES::BLUE_JUMPING, 731, -10);

	if (cdenemys == 1780)
		App->enemies->AddEnemy(ENEMY_TYPES::SPAWN, 992, 252);

	if (cdenemys == 2100)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::SHRIMP, 1100, 180);
		App->enemies->AddEnemy(ENEMY_TYPES::SHRIMP, 1130, 140);
		App->enemies->AddEnemy(ENEMY_TYPES::SHRIMP, 1130, 160);
		App->enemies->AddEnemy(ENEMY_TYPES::SHRIMP, 1160, 140);
		App->enemies->AddEnemy(ENEMY_TYPES::SHRIMP, 1160, 160);

		App->enemies->AddEnemy(ENEMY_TYPES::SHRIMP, 1190,180);
		App->enemies->AddEnemy(ENEMY_TYPES::SHRIMP, 1220, 180);
		App->enemies->AddEnemy(ENEMY_TYPES::SHRIMP, 1260, 160);
		App->enemies->AddEnemy(ENEMY_TYPES::SHRIMP, 1260, 180);
		App->enemies->AddEnemy(ENEMY_TYPES::SHRIMP, 1280, 160);
		App->enemies->AddEnemy(ENEMY_TYPES::SHRIMP, 1280, 180);

	}

	if (cdenemys == 2500)
	{
		tail_powerup = true;
		App->enemies->AddEnemy(ENEMY_TYPES::PU3, 1190, 220);
		App->enemies->AddEnemy(ENEMY_TYPES::SPEEDUP, 1190, 235);

		App->enemies->AddEnemy(ENEMY_TYPES::PU, 1230, 220);
		App->enemies->AddEnemy(ENEMY_TYPES::TENTACLES, 1230, 235);

		App->enemies->AddEnemy(ENEMY_TYPES::PU4, 1260, 220);
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB, 1260, 235);

		App->enemies->AddEnemy(ENEMY_TYPES::PU4, 1290, 220);
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB, 1290, 235);
	}

	if (cdenemys == 3000)
	{
		tail_powerup = false;
	}
	cdenemys++;
}