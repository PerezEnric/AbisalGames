#include "Application.h"
#include "EnemyMiddleLittleDorsal.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"

EnemyMiddleLittleDorsal::EnemyMiddleLittleDorsal(int x, int y) : Enemy(x, y)
{
	middlelittledorsal.PushBack({ 158, 532, 69, 110 });
	animation = &middlelittledorsal;
	original_y = y;
	collider = App->collision->AddCollider({ 515, 138, 50, 90 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	/*leftdorsal_death = App->audio->LoadSoundEffect("Audio_Assets/Ball_Death.wav");*/
}

void EnemyMiddleLittleDorsal::OnCollision(Collider* collider)
{

	//App->audio->PlaySoundEffect(leftdorsal_death);
}


bool EnemyMiddleLittleDorsal::CleanUp()
{
	LOG("Freeing enemy audio");
	App->audio->UnloadSoundEffect(leftdorsal_death);
	shrimp_death = nullptr;

	return true;
}