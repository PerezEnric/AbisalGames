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
	collider = App->collision->AddCollider({ 515, 138, 50, 90 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	/*leftdorsal_death = App->audio->LoadSoundEffect("Audio_Assets/Ball_Death.wav");*/
	cd = -30;
	cd2 = -60;
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

void EnemyMiddleDorsal::Move()
{
	if (cd == 260)
	{
		App->particles->AddParticle(App->particles->loading_shot, position.x - 7, position.y - 11, COLLIDER_ENEMY_SHOT);
	} 

	if (cd == 300)
	{
		App->particles->AddParticle(App->particles->middleleft_shot, position.x, position.y - 90, COLLIDER_ENEMY_SHOT);
		cd = 0;
	}

	if (cd2 == 260)
	{
		App->particles->AddParticle(App->particles->loading_shot, position.x + 70, position.y , COLLIDER_ENEMY_SHOT);
	}

	if (cd2 == 300)
	{
		App->particles->AddParticle(App->particles->middleright_shot, position.x + 71, position.y - 69, COLLIDER_ENEMY_SHOT);
		cd2 = 0;
	}
	cd++;
	cd2++;

}
