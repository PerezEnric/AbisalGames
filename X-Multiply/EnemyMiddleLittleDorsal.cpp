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

void EnemyMiddleLittleDorsal::Move()
{
	if (cd == 300)
	{
		App->particles->AddParticle(App->particles->middleleft_shot, position.x, position.y - 90, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->middleright_shot, position.x + 71, position.y - 69, COLLIDER_ENEMY_SHOT);
		cd = 0;
	}
	cd++;
}