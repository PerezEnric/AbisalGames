#include "Application.h"
#include "Enemy_Ball2.h"
#include "ModuleCollision.h"

Enemy_Ball2::Enemy_Ball2(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 24, 16, 24,24 });
	fly.PushBack({ 52, 16, 24,24 });
	fly.PushBack({ 80, 16, 24,24 });
	fly.speed = 0.1f;
	animation = &fly;
	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	original_y = y;
}
void Enemy_Ball2::Move()
{
	if (going_up)
	{
		if (wave > 1.0f)
			going_up = false;
		else
			wave += 0.07f;
	}
	else
	{
		if (wave < -1.0f)
			going_up = true;
		else
			wave -= 0.07f;
	}

	position.y = int(float(original_y) + (25.0f * sinf(wave)));
	position.x -= 1.2;
}