#include "Application.h"
#include "Enemy_Boss.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModuleBackground.h"
#include "ModuleRender.h"

Enemy_Boss::Enemy_Boss(int x, int y) : Enemy(x, y)
{
	boss.PushBack({ 875,240,113,78 }); //smile
	boss.PushBack({ 870,38,123,82 }); //tongue
	boss.PushBack({ 868,141,123,75 });
	boss.PushBack({ 717,272,96,84 }); //sleep
	boss.speed = 0.0;
	animation = &boss;
	collider = App->collision->AddCollider({ 0, 0, 123, 82 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	eye.PushBack({ 787,564,22,14 }); //front down
	eye.PushBack({ 880,565,20,13 });  //down
	eye.PushBack({ 912,566,16,12 }); //backdown
	eye.PushBack({ 941,566,19,12 });  //back
	eye.PushBack({ 849,564,20,14 }); //backup
	eye.PushBack({ 818,564,21,13 }); //up
	eye.PushBack({ 849,585,16,12 }); //original
	eye.PushBack({ 819,584,19,14 }); //close
	eye.speed = 0.0;
	eyeanim = &eye;

	going_up = true;
	App->background->fight_boss = false;
	going_front = false;


	//go front
	cd = 0;
	cd2 = 0;
	shot_num = 0;
	original_x = App->render->back_limit + App->render->camera.w - 123;

}

bool Enemy_Boss::CleanUp()
{
	blue_death = nullptr;
	return true;
}

void Enemy_Boss::Move()
{
	if (App->background->boss_wakeup)
	{
		boss.current_frame = 0;
		if (App->render->move_back)
		{
			position.x -= 2;
		}

		if (App->render->move_up)
		{
			position.y -= 1;
		}

		if (App->render->move_down)
		{
			position.y += 1;
		}

		if (position.x < original_x)
		{
			position.x++;
		}
		

		if (App->background->fight_boss)
		{
			if (cd == 100)
			{
				App->enemies->AddEnemy(ENEMY_TYPES::BOSS_SHOT, position.x + 12, position.y + 30);
				App->enemies->shot = true;
				cd = 0;
				shot_num++;

				if (shot_num == 2)
				{
					going_front = true;
				}
			}

			if (shot_num == 2)
			{
				if (going_front == true && cd2 >= 30)
				{
					position.x -= 3;
					boss.current_frame = 1;
				}

				if (position.x <= App->render->back_limit)
				{
					going_front = false;
				}

				if (going_front == false && position.x < original_x)
				{
					position.x++;
					boss.current_frame = 2;
				}

				if (position.x >= original_x && cd2 >= 30)
				{
					shot_num = 0;
					boss.current_frame = 0;
					cd2 = 0;
				}

				cd2++;
			}

			else if (going_up && !App->enemies->shot)
			{
				if (position.y <= App->render->up_limit)
				{
					going_up = false;
				}

				else
				{
					position.y -= 2;
				}
			}

			else if (!going_up && !App->enemies->shot)
			{
				if (position.y >= App->render->up_limit + App->render->camera.h - 78)
				{
					going_up = true;
				}

				else
				{
					position.y += 2;
				}
				cd++;
			}
		}
		else
		{
			App->enemies->queue->enemy_life = 80;
		}

		MoveEye();
	}
	else
		boss.current_frame = 3;
}
void Enemy_Boss::OnCollision(Collider* collider)
{
	App->background->fight_boss = false;
	App->background->boss_wakeup = false;
	App->background->bossx = position.x;
	App->background->bossy = position.y;
	App->background->expboss = true;
}

void Enemy_Boss::MoveEye()
{
	if (position.x > App->player->position.x && position.y < App->player->position.y - 40)
	{
		eye.current_frame = 0;
		App->render->Blit(App->enemies->sprites, position.x + 9, position.y + 32, &(eyeanim->GetCurrentFrame()));
	}

	else if (position.x > App->player->position.x - 100 && position.y < App->player->position.y - 40)
	{
		eye.current_frame = 1;
		App->render->Blit(App->enemies->sprites, position.x + 10, position.y + 33, &(eyeanim->GetCurrentFrame()));
	}

	else if (position.y < App->player->position.y - 40)
	{
		eye.current_frame = 2;
		App->render->Blit(App->enemies->sprites, position.x + 12, position.y + 33, &(eyeanim->GetCurrentFrame()));
	}
	else if (position.x > App->player->position.x  && position.y > App->player->position.y - 40)
	{
		eye.current_frame = 6;
		App->render->Blit(App->enemies->sprites, position.x + 12, position.y + 33, &(eyeanim->GetCurrentFrame()));
	}

	else if (position.x > App->player->position.x - 100 && position.y > App->player->position.y)
	{
		eye.current_frame = 5;
		App->render->Blit(App->enemies->sprites, position.x + 10, position.y + 32, &(eyeanim->GetCurrentFrame()));
	}

	else if (position.y > App->player->position.y)
	{
		eye.current_frame = 4;
		App->render->Blit(App->enemies->sprites, position.x + 10, position.y + 32, &(eyeanim->GetCurrentFrame()));
	}

	else
	{
		eye.current_frame = 3;
		App->render->Blit(App->enemies->sprites, position.x + 10, position.y + 33, &(eyeanim->GetCurrentFrame()));
	}

}