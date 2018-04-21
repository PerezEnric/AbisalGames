#include "Application.h"
#include "Enemy_Ball2.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"

Enemy_Ball2::Enemy_Ball2(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 24, 16, 24,24 });
	fly.PushBack({ 52, 16, 24,24 });
	fly.PushBack({ 80, 16, 24,24 });
	fly.speed = 0.1f;
	animation = &fly;
	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	ball2_death = App->audio->LoadSoundEffect("Audio_Assets/Ball_Death.wav");
	original_y = y;
}
void Enemy_Ball2::Move()

{
	if (cd > 180)
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

void Enemy_Ball2::OnCollision(Collider* collider)
{
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	App->player->points += points;
	App->audio->PlaySoundEffect(ball2_death);
}