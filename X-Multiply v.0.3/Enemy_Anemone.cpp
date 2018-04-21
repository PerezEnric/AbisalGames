#include "Application.h"
#include "Enemy_Anemone.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"

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
	if (cd == 100)
	{
		App->particles->AddParticle(App->particles->enemy_shot, position.x + 24, position.y + 20, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { -1, -1 };
		App->particles->AddParticle(App->particles->enemy_shot, position.x + 12, position.y + 10, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { -2, -1 };
		App->particles->AddParticle(App->particles->enemy_shot, position.x, position.y, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { 0, -1 };
		App->particles->AddParticle(App->particles->enemy_shot, position.x + 36, position.y + 10, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { 2, -1 };
		App->particles->AddParticle(App->particles->enemy_shot, position.x + 48, position.y + 20, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { 1, -1 };

		cd = 0;
	}
	cd++;
}

void Enemy_Anemone::OnCollision(Collider* collider)
{
	App->player->points += points;
}