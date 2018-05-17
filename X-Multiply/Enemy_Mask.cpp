#include "Application.h"
#include "Enemy_Mask.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"

Enemy_Mask::Enemy_Mask(int x, int y) : Enemy(x, y)
{
	mask.PushBack({ 310, 195, 86, 69 });
	animation = &mask;

	collider = App->collision->AddCollider({ 452, 124, 86, 69 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
}

void Enemy_Mask::OnCollision(Collider* collider)
{

	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	//App->audio->PlaySoundEffect(boost_sound);
}

void Enemy_Mask::Move()
{
	if (cd == 500)
	{
		App->particles->AddParticle(App->particles->enemy_shot, position.x - 5, position.y + 20, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { -1, 0 };
		App->particles->AddParticle(App->particles->enemy_shot, position.x - 5, position.y + 10, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { -1, -1 };
		App->particles->AddParticle(App->particles->enemy_shot, position.x - 5, position.y + 30, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { -1, 1 };
		App->particles->AddParticle(App->particles->enemy_shot, position.x - 5, position.y + 0, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { -1, -2 };
		App->particles->AddParticle(App->particles->enemy_shot, position.x - 5, position.y + 40, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { -1, 2 };

		cd = 0;
	}
	cd++;


}

bool Enemy_Mask::CleanUp()
{
	LOG("Freeing enemy audio");
	App->audio->UnloadSoundEffect(shrimp_death);
	shrimp_death = nullptr;

	return true;
}