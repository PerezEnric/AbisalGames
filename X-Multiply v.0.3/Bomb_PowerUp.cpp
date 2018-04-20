#include "Application.h"
#include "Bomb_PowerUp.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"


Bomb_PowerUp::Bomb_PowerUp(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 360, 39, 21,16 });
	fly.speed = 0.1f;
	animation = &fly;
	collider = App->collision->AddCollider({ 0, 0, 21, 16 }, COLLIDER_TYPE::COLLIDER_POWER_UP, (Module*)App->enemies);
	original_y = y;
}


void Bomb_PowerUp ::OnCollision(Collider* collider)
{
	App->player->bomb = true;
}
