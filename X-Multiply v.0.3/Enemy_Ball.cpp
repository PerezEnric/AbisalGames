#include "Application.h"
#include "Enemy_Ball.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"

Enemy_Ball::Enemy_Ball(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 24, 16, 24,24 });
	fly.PushBack({ 52, 16, 24,24 });
	fly.PushBack({ 80, 16, 24,24 });
	fly.speed = 0.1f;
	animation = &fly;
	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	original_y = y;
	ball_death = App->audio->LoadSoundEffect("Audio_Assets/Ball_Death.wav");
	App->enemies->points = 100;
}
void Enemy_Ball::Move()
{
	if (cd > 188)
		right = true;
	cd++; 
	
	if (going_up)
	{
		if (wave > 1.5f)
			going_up = false;
		else
			wave += 0.1f;
	}
	else
	{
		if (wave < -1.5f)
			going_up = true;
		else
			wave -= 0.1f;
	}

	position.y = int(float(original_y) + (30.0f * sinf(wave)));

	if (right)
	{
		position.x += 2.7;
	}
	else
	{
		position.x -= 1.7;
	}

}

void Enemy_Ball::OnCollision(Collider* collider)
{
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	App->player->points += points;
	App->audio->PlaySoundEffect(ball_death);
}

bool Enemy_Ball::CleanUp()
{
	LOG("Freeing enemy audio");
	App->audio->UnloadSoundEffect(ball_death);
	ball_death = nullptr;

	return true;
}