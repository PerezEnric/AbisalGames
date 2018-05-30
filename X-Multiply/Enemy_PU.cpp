#include "Application.h"
#include "Enemy_PU.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"

Enemy_PU::Enemy_PU(int x, int y) : Enemy(x, y)
{
	//Basic fly
	fly_robot.PushBack({ 122, 66, 28, 19 });
	fly_robot.PushBack({ 154, 65, 31, 20 });
	

	//Landing
	fly_robot.PushBack({ 241, 5, 28, 17 });
	fly_robot.PushBack({ 209, 5, 31, 19 });
	fly_robot.PushBack({ 177, 5, 28, 21 });
	fly_robot.PushBack({ 145, 5, 31, 22 });
	fly_robot.PushBack({ 113, 5, 28, 22 });
	fly_robot.PushBack({ 305, 29, 28, 22 });
	fly_robot.PushBack({ 277, 32, 28, 19 });
	


	//Walking
	fly_robot.PushBack({ 241, 29, 28, 22 });
	fly_robot.PushBack({ 209, 29, 28, 22 });
	fly_robot.PushBack({ 177, 29, 28, 22 });
	fly_robot.PushBack({ 145, 29, 28, 22 });



	fly_robot.speed = 0.1f;
	animation = &fly_robot;

	collider = App->collision->AddCollider({ 0, 0, 28, 19 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	original_y = y;
	/*shrimp_death = App->audio->LoadSoundEffect("Audio_Assets/Ball_Death.wav");*/
}
void Enemy_PU::Move()
{
	//Fly movement
	if (flying == true)
	{

		fly_robot.current_frame = 1;
		fly_robot.current_frame = 2;

		position.y = int(float(original_y));;
		position.x -= 1;
		cd++;
		if (cd > 100)
		{
			landing = true;
			flying = false;
		}
	}

	//Landing movement
	else if (landing == true && flying == false && walking == false)
	{
		fly_robot.current_frame = 3;
		fly_robot.current_frame = 4;
		fly_robot.current_frame = 5;
		fly_robot.current_frame = 6;
		fly_robot.current_frame = 7;
		fly_robot.current_frame = 8;
		fly_robot.current_frame = 9;

		position.y += 1;
		position.x += 1;
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
			fly_robot.current_frame = 10;
			fly_robot.current_frame = 11;
			fly_robot.current_frame = 12;
			fly_robot.current_frame = 13;

			position.x += 1;
			cd3++;
			if (cd3 > 100)
			{
				left = true;
				right = false;
				cd3 = 0;
			}
		}
		//Left walking movement
		if (left == true && right == false)
		{
			fly_robot.current_frame = 10;
			fly_robot.current_frame = 11;
			fly_robot.current_frame = 12;
			fly_robot.current_frame = 13;
			position.x -= 1;
			cd3++;
			if (cd3 > 100)
			{
				right = true;
				left = false;
				cd3 = 0;
			}
		}

	}
}

void Enemy_PU::OnCollision(Collider* collider)
{
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	App->player->points += points;
	//App->audio->PlaySoundEffect(shrimp_death);
}

bool Enemy_PU::CleanUp()
{
	LOG("Freeing enemy audio");
	//App->audio->UnloadSoundEffect(shrimp_death);
	shrimp_death = nullptr;

	return true;
}