#include "Application.h"
#include "Enemy_Bluejumping.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"

Enemy_BlueJumping::Enemy_BlueJumping(int x, int y) : Enemy(x, y)
{
	jumping.PushBack({ 715, 81, 29, 30 });
	jumping.PushBack({ 747, 81, 29, 30 });
	jumping.speed = 0.0f;
	animation = &jumping;
	collider = App->collision->AddCollider({ 0, 0, 29, 30 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	go_down = true;
	speed = 0;
	shrimp_death = App->audio->LoadSoundEffect("Audio_Assets/Ball_Death.wav");
}
void Enemy_BlueJumping::Move()
{
	if (go_down && position.y < 100)
	{
		position.y += speed;
		speed += 0.1;
	}

	else if (go_down && position.y >= 30)
	{
		go_down = false;
		jumping.current_frame = 1;
		original_y = position.y;
		App->particles->AddParticle(App->particles->bluejumping_shot, position.x + 30, position.y + 30, COLLIDER_ENEMY_SHOT);
		App->particles->bluejumping_shot.speed = { -1,1 };
	}
	
	else if (go_down == false)
	{
		if (going_up)
		{
			if (wave > 0.0f)
			{
				going_up = false;
			}
			else
				wave += 0.03f;
		}
		else
		{
			if (wave < -1.0f)
			{
				going_up = true;
			}
			else
				wave -= 0.03f;
		}
		position.y = int(float(original_y) + (60.0f * sinf(wave)));
		position.x -= 1.0f;
	}
}

void Enemy_BlueJumping::OnCollision(Collider* collider)
{
	App->audio->PlaySoundEffect(shrimp_death);
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	App->player->points += points;
}

bool Enemy_BlueJumping::CleanUp()
{
	LOG("Freeing enemy audio");
	App->audio->UnloadSoundEffect(shrimp_death);
	shrimp_death = nullptr;

	return true;
}