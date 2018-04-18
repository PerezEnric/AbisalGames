#include "Application.h"
#include "Enemy_LittleShrimp.h"
#include "ModuleCollision.h"

Enemy_LittleShrimp::Enemy_LittleShrimp(int x, int y) : Enemy(x, y)
{
	fly_shrimp.PushBack({ 37, 74, 43, 27 });
	fly_shrimp.PushBack({ 37, 127, 41, 32 });
	fly_shrimp.speed = 0.1f;
	animation = &fly_shrimp;
	collider = App->collision->AddCollider({ 0, 0, 42, 30 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	original_y = y;
}
void Enemy_LittleShrimp::Move()
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