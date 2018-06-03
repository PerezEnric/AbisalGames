#include "Application.h"
#include "EnemyLeftDorsal.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"

EnemyLeftDorsal::EnemyLeftDorsal(int x, int y) : Enemy(x, y)
{
	leftdorsal.PushBack({ 47, 423, 63, 99 });
	animation = &leftdorsal;
	collider = App->collision->AddCollider({ 452, 124, 63, 50 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	/*leftdorsal_death = App->audio->LoadSoundEffect("Audio_Assets/Ball_Death.wav");*/
}

void EnemyLeftDorsal::OnCollision(Collider* collider)
{

	//App->audio->PlaySoundEffect(leftdorsal_death);
}


bool EnemyLeftDorsal::CleanUp()
{
	LOG("Freeing enemy audio");
	//App->audio->UnloadSoundEffect(leftdorsal_death);
	shrimp_death = nullptr;

	return true;
}

void EnemyLeftDorsal::Move()
{
	if (cd == 160)
	{
		App->particles->AddParticle(App->particles->loading_shot, position.x - 12, position.y - 11, COLLIDER_ENEMY_SHOT);
	}
	if (cd == 200)
	{
		App->particles->AddParticle(App->particles->leftdorsal_shot, position.x - 40, position.y - 85, COLLIDER_ENEMY_SHOT);
		cd = 0;
	}
	cd++;
}
