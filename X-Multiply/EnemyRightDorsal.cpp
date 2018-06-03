#include "Application.h"
#include "EnemyRightDorsal.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"

EnemyRightDorsal::EnemyRightDorsal(int x, int y) : Enemy(x, y)
{
	rightdorsal.PushBack({ 280, 411, 109, 108 });
	animation = &rightdorsal;
	collider = App->collision->AddCollider({ 600, 138, 50, 90 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	/*leftdorsal_death = App->audio->LoadSoundEffect("Audio_Assets/Ball_Death.wav");*/
}

void EnemyRightDorsal::OnCollision(Collider* collider)
{

	//App->audio->PlaySoundEffect(leftdorsal_death);
}


bool EnemyRightDorsal::CleanUp()
{
	LOG("Freeing enemy audio");
	App->audio->UnloadSoundEffect(leftdorsal_death);
	shrimp_death = nullptr;

	return true;
}

void EnemyRightDorsal::Move()
{
	/*if (cd == 300)
	{
		App->particles->AddParticle(App->particles->rightdorsal_shot, position.x + 107, position.y - 32, COLLIDER_ENEMY_SHOT);
		cd = 0;
	}
	cd++;*/
}
