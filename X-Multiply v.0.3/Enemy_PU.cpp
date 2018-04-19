#include "Application.h"
#include "Enemy_PU.h"
#include "ModuleCollision.h"

Enemy_PU::Enemy_PU(int x, int y) : Enemy(x, y)
{
	fly_PU.PushBack({ 324, 7, 28, 19 });
	fly_PU.PushBack({ 356, 6, 31, 20 });
	fly_PU.speed = 0.1f;
	animation = &fly_PU;
	collider = App->collision->AddCollider({ 0, 0, 31, 20 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	original_y = y;
}
void Enemy_PU::Move()
{
	position.y = int(float(original_y));;
	position.x -= 1;
}