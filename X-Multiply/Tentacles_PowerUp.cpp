#include "Application.h"
#include "Tentacles_PowerUp.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleTentacles.h"


Tentacles_PowerUp::Tentacles_PowerUp(int x, int y) : Enemy(x, y)
{
	tentacleanim.PushBack({ 202, 100, 18,15 });
	tentacleanim.speed = 0.1f;
	animation = &tentacleanim;
	collider = App->collision->AddCollider({ 0,0,18,15 }, COLLIDER_TYPE::COLLIDER_POWER_UP, (Module*)App->enemies);
	original_y = y;
	new_weapon = App->audio->LoadSoundEffect("Audio_Assets/power_up2.wav");
}


void Tentacles_PowerUp::OnCollision(Collider* collider)
{
	App->audio->PlaySoundEffect(new_weapon);
	App->player->tentacles = true;
	App->tentacle->Enable();
}

void Tentacles_PowerUp::Move()
{

		//Fly movement
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
			if (cd2 > 100)
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

			if (position.y <= original_y)
			{
				position.x += 1;
			}
			else
				position.y -= 1;

			cd3++;
		}
}

bool  Tentacles_PowerUp::CleanUp()
{
	LOG("Unload power up audio");
	App->audio->UnloadSoundEffect(new_weapon);
	new_weapon = nullptr;
	return true;
}