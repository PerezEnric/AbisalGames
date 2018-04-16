#include "Application.h"
#include "Enemy_Ball.h"
#include "ModuleCollision.h"

Enemy_Ball::Enemy_Ball(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ -24, -16, 24,24 });
	fly.PushBack({ -52, -16, 24,24 });
	fly.PushBack({ -80, -16, 24,24 });
	fly.speed = 0.2f;
	animation = &fly;
	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	original_y;
}
void Enemy_Ball::Move()
{
	if (going_up)
	{
		if (wave > 1.0f)
			going_up = false;
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
	position.x -= 1;
}