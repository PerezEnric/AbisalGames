#include "Application.h"
#include "Enemy_LittleShrimp.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleUI.h"
#include "ModuleRender.h"

Enemy_LittleShrimp::Enemy_LittleShrimp(int x, int y) : Enemy(x, y)
{
	fly_shrimp.PushBack({ 41, 48, 43, 27 });
	fly_shrimp.PushBack({ 41, 101, 41, 32 });
	fly_shrimp.speed = 0.1f;
	animation = &fly_shrimp;
	collider = App->collision->AddCollider({ 0, 0, 42, 30 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	original_y = y;
	shrimp_death = App->audio->LoadSoundEffect("Audio_Assets/Ball_Death.wav");
	points = 400;
}
void Enemy_LittleShrimp::Move()
{
	if (action == false && position.x < SCREEN_WIDTH + App->render->back_limit + 40)
	{
		action = true;
	}
	if (action == true)
	{
		if (going_up)
		{
			if (wave > 1.0f)
			{
				going_up = false;
				cd++;
				if (cd > 2)
				{
					//shot direction
					if (App->player->position.x < position.x && App->player->position.y < position.y)
						App->particles->enemy_shot.speed = { -1,-1 };

					else if (App->player->position.x > position.x && App->player->position.y < position.y)
						App->particles->enemy_shot.speed = { 1,-1 };

					else if (App->player->position.x > position.x && App->player->position.y > position.y)
						App->particles->enemy_shot.speed = { 1,1 };

					else if (App->player->position.x < position.x && App->player->position.y > position.y)
						App->particles->enemy_shot.speed = { -1,1 };

					App->particles->AddParticle(App->particles->enemy_shot, position.x + 30, position.y + 30, COLLIDER_ENEMY_SHOT);

					cd = 0;
				}
			}
			else
				wave += 0.05f;
		}
		else
		{
			if (wave < -1.0f)
				going_up = true;
			else
				wave -= 0.05f;
		}
		position.y = int(float(original_y) + (25.0f * sinf(wave)));
		position.x -= 1.5f;
	}
	
}

void Enemy_LittleShrimp::OnCollision(Collider* collider)
{
	App->audio->PlaySoundEffect(shrimp_death);
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	App->ui->points = points;
}

bool Enemy_LittleShrimp::CleanUp()
{
	LOG("Freeing enemy audio");
	App->audio->UnloadSoundEffect(shrimp_death);
	shrimp_death = nullptr;

	return true;
}