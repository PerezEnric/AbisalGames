#include "Application.h"
#include "EnemyMiddleDorsal.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"

EnemyMiddleDorsal::EnemyMiddleDorsal(int x, int y) : Enemy(x, y)
{
	middledorsal.PushBack({ 168, 413, 70, 110 });
	animation = &middledorsal;
	original_y = y;
	collider = App->collision->AddCollider({ 515, 138, 50, 90 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	/*leftdorsal_death = App->audio->LoadSoundEffect("Audio_Assets/Ball_Death.wav");*/
}

void EnemyMiddleDorsal::OnCollision(Collider* collider)
{

	//App->audio->PlaySoundEffect(leftdorsal_death);
}


bool EnemyMiddleDorsal::CleanUp()
{
	LOG("Freeing enemy audio");
	App->audio->UnloadSoundEffect(leftdorsal_death);
	shrimp_death = nullptr;

	return true;
}