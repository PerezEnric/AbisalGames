#include "Application.h"
#include "PowerUp_SpeedUp.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleBackground.h"


PowerUp_SpeedUp::PowerUp_SpeedUp(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 123, 96, 24,13 });
	fly.speed = 0.1f;
	animation = &fly;
	collider = App->collision->AddCollider({ 0, 0, 24, 13 }, COLLIDER_TYPE::COLLIDER_POWER_UP, (Module*)App->enemies);
	original_y = y;
	boost_sound = App->audio->LoadSoundEffect("Audio_Assets/power_up.wav");
	flying = true;
}
void PowerUp_SpeedUp::Move()
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
				cd2 = 0;
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

				if (cd3 == 1)
				{
					position.x -= 30;
				}

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

			if (position.y <= original_y || left)
			{

				if (position.y == original_y && !left)
				{
					position.x -= 30;
				}
				position.x += 1;
				left = true;
			}
			else
			{
				position.y -= 1;
			}

			if (cd3 == 1)
			{
				position.x += 30;
			}
			cd3++;
		}
	}

	else
	{
		position.y = int(float(original_y));
		if (App->enemies->lets == false)
		{
			position.x -= 1;
		}
		else
		{
			position.x -= 0;
		}

	}
}

void PowerUp_SpeedUp::OnCollision(Collider* collider)
{
	App->audio->PlaySoundEffect(boost_sound);
	App->player->turbo = true;

	App->particles->boost = true;
}

bool  PowerUp_SpeedUp::CleanUp()
{
	LOG("Unload power up audio");
	App->audio->UnloadSoundEffect(boost_sound);
	boost_sound = nullptr;
	return true;
}