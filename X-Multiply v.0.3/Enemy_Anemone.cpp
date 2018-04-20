#include "Application.h"
#include "Enemy_Anemone.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"

Enemy_Anemone::Enemy_Anemone(int x, int y) : Enemy(x, y)
{
	anem.PushBack({ 139, 18, 48,41 });
	anem.PushBack({ 200, 19, 46,39 });
	anem.PushBack({ 260, 16, 47,42 });
	anem.speed = 0.1f;
	animation = &anem;
	collider = App->collision->AddCollider({ 0, 0, 47, 42 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void Enemy_Anemone::Move()
{
	
}