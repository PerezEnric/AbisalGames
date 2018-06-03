#include "Application.h"
#include "Enemy_PU.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleRender.h"
#include "ModuleUI.h"

Enemy_PU::Enemy_PU(int x, int y) : Enemy(x, y)
{
	//Basic fly
	fly_robot.PushBack({ 122, 66, 28, 19 });
	fly_robot.PushBack({ 154, 65, 31, 20 });
	fly_robot.speed = 0.1f;

	//Landing
	landing_robot.PushBack({ 241, 5, 28, 17 });
	landing_robot.PushBack({ 209, 5, 31, 19 });
	landing_robot.PushBack({ 177, 5, 28, 21 });
	landing_robot.PushBack({ 145, 5, 31, 22 });
	landing_robot.PushBack({ 113, 5, 28, 22 });
	landing_robot.PushBack({ 305, 29, 28, 22 });
	landing_robot.PushBack({ 277, 32, 28, 19 });
	landing_robot.speed = 0.1f;


	//Walking left
	walking_robot.PushBack({ 241, 29, 28, 22 });
	walking_robot.PushBack({ 209, 29, 28, 22 });
	walking_robot.PushBack({ 177, 29, 28, 22 });
	walking_robot.PushBack({ 145, 29, 28, 22 });
	walking_robot.speed = 0.1f;

	//Walking right
	walkingr_robot.PushBack({ 346, 29, 28, 22 });
	walkingr_robot.PushBack({ 378, 29, 28, 22 });
	walkingr_robot.PushBack({ 410, 29, 28, 22 });
	walkingr_robot.PushBack({ 442, 29, 28, 22 });
	walkingr_robot.speed = 0.1f;

	//wake up
	wake_up.PushBack({ 277, 32, 28, 19 });
	wake_up.PushBack({ 305, 29, 28, 22 });
	wake_up.PushBack({ 113, 5, 28, 22 });
	wake_up.PushBack({ 145, 5, 31, 22 });
	wake_up.PushBack({ 177, 5, 28, 21 });
	wake_up.PushBack({ 209, 5, 31, 19 });
	wake_up.PushBack({ 241, 5, 28, 17 });
	wake_up.speed = 0.1f;
	wake_up.loop = false;


	
	animation = &fly_robot;

	collider = App->collision->AddCollider({ 0, 0, 28, 19 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	original_y = y;
	robot_death = App->audio->LoadSoundEffect("Audio_Assets/powerup_death.wav");
	points = 1000;
}
void Enemy_PU::Move()
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
				animation = &landing_robot;
			}
		}

		//Landing movement
		else if (landing == true && flying == false && walking == false)
		{
			position.y += 1;
			position.x -= 0;
			cd2++;
			if (cd2 > 30)
			{
				walking = true;
				landing = false;
				animation = &walkingr_robot;
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
				if (cd3 > 100)
				{
					walking = false;
					landing = false;
					flying = false;
					cd3 = 0;
					animation = &wake_up;
				}
			}

		}
		else if (walking == false && landing == false && flying == false)
		{
			position.y -= 1;
		}


}

void Enemy_PU::OnCollision(Collider* collider)
{
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	App->ui->points += points;
	App->audio->PlaySoundEffect(robot_death);
}

bool Enemy_PU::CleanUp()
{
	LOG("Freeing enemy audio");
	App->audio->UnloadSoundEffect(robot_death);
	robot_death = nullptr;

	return true;
}