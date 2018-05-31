#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "Enemy.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"


#define SPAWN_MARGIN 500

ModuleEnemies::ModuleEnemies()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;
}

// Destructor
ModuleEnemies::~ModuleEnemies()
{
}

bool ModuleEnemies::Start()
{
	bool lets = false;
	bool letb = false;
	bool lett = false;
	
	sprites = App->textures->Load("Sprites_Assets/all_enemies.png");
	return true;
}

update_status ModuleEnemies::PreUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type != ENEMY_TYPES::NO_TYPE)
		{
			if (queue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				SpawnEnemy(queue[i]);
				queue[i].type = ENEMY_TYPES::NO_TYPE;
				LOG("Spawning enemy at %d", queue[i].x * SCREEN_SIZE);
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleEnemies::Update()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr)
			enemies[i]->Move();

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) enemies[i]->Draw(sprites);

	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			if (enemies[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
			{
				LOG("DeSpawning enemy at %d", enemies[i]->position.x * SCREEN_SIZE);
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");

	App->textures->Unload(sprites);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}


	return true;
}

bool ModuleEnemies::AddEnemy(ENEMY_TYPES type, int x, int y)
{
	bool ret = false;

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type == ENEMY_TYPES::NO_TYPE)
		{
			queue[i].type = type;
			queue[i].x = x;
			queue[i].y = y;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleEnemies::SpawnEnemy(const EnemyInfo& info)
{
	// find room for the new enemy
	uint i = 0;
	for (; enemies[i] != nullptr && i < MAX_ENEMIES; ++i);

	if (i != MAX_ENEMIES)
	{
		switch (info.type)
		{
			case ENEMY_TYPES::LEFTDORSAL:
				enemies[i] = new EnemyLeftDorsal(info.x, info.y);
				queue[i].enemy_life = 5;
				break;
			case ENEMY_TYPES::LEFTLITTLEDORSAL:
				enemies[i] = new EnemyLeftLittleDorsal(info.x, info.y);
				queue[i].enemy_life = 10;
				break;
			case ENEMY_TYPES::MIDDLEDORSAL:
				enemies[i] = new EnemyMiddleDorsal(info.x, info.y);
				queue[i].enemy_life = 5;
				break;
			case ENEMY_TYPES::MIDDLELITTLEDORSAL:
				enemies[i] = new EnemyMiddleLittleDorsal(info.x, info.y);
				queue[i].enemy_life = 10;
				break;
			case ENEMY_TYPES::RIGHTDORSAL:
				enemies[i] = new EnemyRightDorsal(info.x, info.y);
				queue[i].enemy_life = 5;
				break;
			case ENEMY_TYPES::RIGHTLITTLEDORSAL:
				enemies[i] = new EnemyRightLittleDorsal(info.x, info.y);
				queue[i].enemy_life = 10;
				break;
			case ENEMY_TYPES::MASK:
				enemies[i] = new Enemy_Mask(info.x, info.y);
				queue[i].enemy_life = 20;
				break;
			case ENEMY_TYPES::SPAWN:
				enemies[i] = new Enemy_SpawnWorms(info.x, info.y);
				queue[i].enemy_life = 12;
				break;
			case ENEMY_TYPES::TAIL:
				enemies[i] = new Enemy_Tail(info.x, info.y);
				queue[i].enemy_life = 30;
				break;
			case ENEMY_TYPES::LATERALFIN:
				enemies[i] = new Enemy_LateralFin(info.x, info.y);
				queue[i].enemy_life = 16;
				break;
			case ENEMY_TYPES::SHRIMP:
				enemies[i] = new Enemy_LittleShrimp(info.x, info.y);
				queue[i].enemy_life = 1;
				break;
			case ENEMY_TYPES::GWORM:
				enemies[i] = new Enemy_GWorm(info.x, info.y);
				queue[i].enemy_life = 1;
				break;
			case ENEMY_TYPES::BLUE_JUMPING:
				enemies[i] = new Enemy_BlueJumping(info.x, info.y);
				queue[i].enemy_life = 3;
				break;
			case ENEMY_TYPES::PU:
				enemies[i] = new Enemy_PU(info.x, info.y);
				queue[i].enemy_life = 1;
				break;
			case ENEMY_TYPES::SPEEDUP:
				enemies[i] = new PowerUp_SpeedUp(info.x, info.y);
				break;
			case ENEMY_TYPES::TENTACLES:
				enemies[i] = new Tentacles_PowerUp(info.x, info.y);
				break;

			case ENEMY_TYPES::WAVES:
				enemies[i] = new Waves_PowerUp(info.x, info.y);
				break;
			case ENEMY_TYPES::BOMB:
				enemies[i] = new Bomb_PowerUp(info.x, info.y);
				break;
		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1)
		{
			if (queue[i].enemy_life > 0)
				queue[i].enemy_life--;

			if (queue[i].enemy_life == 0)
			{
				enemies[i]->OnCollision(c2);
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}

	}
}