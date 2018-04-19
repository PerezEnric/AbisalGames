#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePowerUp.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "PowerUp.h"


#define SPAWN_MARGIN 50

ModulePowerUp::ModulePowerUp()
{
	for (uint i = 0; i < MAX_POWERUPS; ++i)
		powerup[i] = nullptr;
}

// Destructor
ModulePowerUp::~ModulePowerUp()
{
}

bool ModulePowerUp::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	sprites = App->textures->Load("Sprites_Assets/PowerUp.png");

	return true;
}

update_status ModulePowerUp::PreUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (queue[i].type != POWERUP_TYPES::NO_TYP)
		{
			if (queue[i].x * SCREEN_SIZE > App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				SpawnPowerUp(queue[i]);
				queue[i].type = POWERUP_TYPES::NO_TYP;
				LOG("Spawning power up at %d", queue[i].x * SCREEN_SIZE);
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModulePowerUp::Update()
{
	for (uint i = 0; i < MAX_POWERUPS; ++i)
		if (powerup[i] != nullptr) powerup[i]->Move();

	for (uint i = 0; i < MAX_POWERUPS; ++i)
		if (powerup[i] != nullptr) powerup[i]->Draw(sprites);

	return UPDATE_CONTINUE;
}

update_status ModulePowerUp::PostUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (powerup[i] != nullptr)
		{
			if (powerup[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
			{
				LOG("DeSpawning power up at %d", powerup[i]->position.x * SCREEN_SIZE);
				delete powerup[i];
				powerup[i] = nullptr;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModulePowerUp::CleanUp()
{
	LOG("Freeing all power ups");

	App->textures->Unload(sprites);

	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (powerup[i] != nullptr)
		{
			delete powerup[i];
			powerup[i] = nullptr;
		}
	}

	return true;
}

bool ModulePowerUp::AddPowerUp(POWERUP_TYPES type, int x, int y)
{
	bool ret = false;

	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (queue[i].type == POWERUP_TYPES::NO_TYP)
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

void ModulePowerUp::SpawnPowerUp(const PowerUpInfo& info)
{
	// find room for the new enemy
	uint i = 0;
	for (; powerup[i] != nullptr && i < MAX_POWERUPS; ++i);

	if (i != MAX_POWERUPS)
	{
		switch (info.type)
		{
		case POWERUP_TYPES::SPEEDUP:
			powerup[i] = new PowerUp_SpeedUp(info.x, info.y);
			break;
		}
	}
}

void ModulePowerUp::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (powerup[i] != nullptr && powerup[i]->GetCollider() == c1)
		{
			powerup[i]->OnCollision(c2);
			delete powerup[i];
			powerup[i] = nullptr;
			break;
		}
	}
}