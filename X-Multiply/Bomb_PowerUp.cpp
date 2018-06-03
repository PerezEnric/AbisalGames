#include "Application.h"
#include "Bomb_PowerUp.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleBackground.h"


Bomb_PowerUp::Bomb_PowerUp(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 245, 100, 18,15 });
	fly.speed = 0.1f;
	animation = &fly;
	collider = App->collision->AddCollider({ 0, 0, 21, 16 }, COLLIDER_TYPE::COLLIDER_POWER_UP, (Module*)App->enemies);
	original_y = y;
	new_weapon = App->audio->LoadSoundEffect("Audio_Assets/power_up2.wav");
}


void Bomb_PowerUp::OnCollision(Collider* collider)
{
	App->player->bomb = true;
	App->audio->PlaySoundEffect(new_weapon);
}

void Bomb_PowerUp::Move()
{
	if (App->background->tail_powerup)
	{
		if (flying == true)
		{
			position.x -= 1;
			cd++;
			if (cd >= 190)
			{
				landing = true;
				flying = false;
			}
		}

		//Landing movement
		else if (landing == true && flying == false && walking == false)
		{
			position.y += 1;
			position.x -= 0;
			cd2++;
			if (cd2 == 1)
			{
				position.y -= 15;
				position.x += 20;
			}

			if (cd2 > 30)
			{
				walking = true;
				landing = false;
			}
		}

		//Walking movement
		else if (walking == true && landing == false && flying == false)
		{
			//Right walking movement
			if (right == true && left == false)
			{
				position.x += 1;
				cd3++;

				if (cd3 > 20)
				{
					walking = false;
					landing = false;
					flying = false;
					cd3 = 0;
				}
			}
		}
		else if (walking == false && landing == false && flying == false)
		{
			position.y += 1;

		}
		else if (cd3 > 0)
		{
			position.y += 1;
		}
	}
	else
		position.x -= 1;
}

bool  Bomb_PowerUp::CleanUp()
{
	LOG("Unload power up audio");
	App->audio->UnloadSoundEffect(new_weapon);
	new_weapon = nullptr;
	return true;
}