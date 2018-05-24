#include "Application.h"
#include "EnemyRightLittleDorsal.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"

EnemyRightLittleDorsal::EnemyRightLittleDorsal(int x, int y) : Enemy(x, y)
{
	rightlittledorsal.PushBack({ 266, 536, 111, 111 });
	animation = &rightlittledorsal;
	collider = App->collision->AddCollider({ 600, 138, 50, 90 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	/*leftdorsal_death = App->audio->LoadSoundEffect("Audio_Assets/Ball_Death.wav");*/
}

void EnemyRightLittleDorsal::OnCollision(Collider* collider)
{

	//App->audio->PlaySoundEffect(leftdorsal_death);
}


bool EnemyRightLittleDorsal::CleanUp()
{
	LOG("Freeing enemy audio");
	App->audio->UnloadSoundEffect(leftdorsal_death);
	shrimp_death = nullptr;

	return true;
}

void EnemyRightLittleDorsal::Move()
{
	if (cd == 300)
	{
		App->particles->AddParticle(App->particles->rightdorsal_shot, position.x + 150, position.y - 34, COLLIDER_ENEMY_SHOT);
		cd = 0;
	}
	cd++;
}