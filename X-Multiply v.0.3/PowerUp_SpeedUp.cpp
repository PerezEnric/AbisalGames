#include "Application.h"
#include "PowerUp_SpeedUp.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"


PowerUp_SpeedUp::PowerUp_SpeedUp(int x, int y) : PowerUp(x, y)
{
	fly.PushBack({ 164, 74, 24,13 });
	fly.speed = 0.1f;
	animation = &fly;
	collider = App->collision->AddCollider({ 0, 0, 24, 13 }, COLLIDER_TYPE::COLLIDER_POWER_UP, (Module*)App->powerup);
	original_y = y;
}
void PowerUp_SpeedUp::Move()
{
	

	position.y = int(float(original_y));
	position.x -= 0;
}

void PowerUp_SpeedUp::OnCollision(Collider* collider)
{
	App->player->turbo = true;
}