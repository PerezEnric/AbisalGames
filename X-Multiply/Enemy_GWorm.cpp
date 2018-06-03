#include "Application.h"
#include "Enemy_GWorm.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleRender.h"
#include "ModuleUI.h"

Enemy_GWorm::Enemy_GWorm(int x, int y) : Enemy(x, y)
{
	//Walking
	greenw.PushBack({ 272, 70, 30, 15 });
	greenw.PushBack({ 307, 69, 27, 16 });
	greenw.speed = 0.05f;
	//Shooting
	greenw_shoot.PushBack({ 348, 70, 26, 21 });
	greenw_shoot.PushBack({ 274, 99, 27, 16 });
	greenw_shoot.PushBack({ 319, 97, 33, 18 });
	greenw_shoot.speed = 0.02f;

	animation = &greenw;
	collider = App->collision->AddCollider({ 0, 0, 29, 30 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	blue_death = App->audio->LoadSoundEffect("Audio_Assets/Ball_Death.wav");
	points = 200;
	firstwalk = true;
}
void Enemy_GWorm::Move()
{
	if (action == false && position.x < SCREEN_WIDTH + App->render->back_limit + 40)
	{
		action = true;
	}

		if (walk == true)
		{
			if (stop == true)
			{
				position.y += 0;
				position.x -= 0;
				stop = false;
			}
			else
			{
				if (firstwalk == true)
				{
					position.y -= 0;
				}
				else
					position.y -= 0.5f;
				position.x -= 1.0f;
				stop = true;
			}

			cd++;
			if (cd == 100)
			{
				walk = false;
				animation = &greenw_shoot;
				cd = 0;
			}
		}
		else if (walk == false)
		{
			position.y -= 0;
			position.x += 0;
			cd2++;
			if (cd2 == 100)
			{
				if (App->player->position.x < position.x && App->player->position.y < position.y)
					App->particles->enemy_shot.speed = { -1,-1 };

				else if (App->player->position.x > position.x && App->player->position.y < position.y)
					App->particles->enemy_shot.speed = { 1,-1 };

				else if (App->player->position.x > position.x && App->player->position.y > position.y)
					App->particles->enemy_shot.speed = { 1,1 };

				else if (App->player->position.x < position.x && App->player->position.y > position.y)
					App->particles->enemy_shot.speed = { -1,1 };

				App->particles->AddParticle(App->particles->enemy_shot, position.x + 30, position.y + 30, COLLIDER_ENEMY_SHOT);
				cd2 = 0;
			}

			cd++;
			if (cd == 100)
			{
				walk = true;
				animation = &greenw;
				cd = 0;
				firstwalk = false;
			}
		}
	

}

void Enemy_GWorm::OnCollision(Collider* collider)
{
	App->audio->PlaySoundEffect(blue_death);
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	App->ui->points += points;
}

bool Enemy_GWorm::CleanUp()
{
	LOG("Freeing enemy audio");
	App->audio->UnloadSoundEffect(blue_death);
	blue_death = nullptr;

	return true;
}