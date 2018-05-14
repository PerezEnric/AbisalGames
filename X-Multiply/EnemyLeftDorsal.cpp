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
	original_y = y;
	collider = App->collision->AddCollider({ 452, 124, 63, 50 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
}

void EnemyLeftDorsal::OnCollision(Collider* collider)
{


	//App->audio->PlaySoundEffect(boost_sound);
}

void EnemyLeftDorsal::Enemy_Death()
{
	
}