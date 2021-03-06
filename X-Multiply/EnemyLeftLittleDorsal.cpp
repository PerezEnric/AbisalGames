#include "Application.h"
#include "EnemyLeftLittleDorsal.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleUI.h"

EnemyLeftLittleDorsal::EnemyLeftLittleDorsal(int x, int y) : Enemy(x, y)
{
	leftlittledorsal.PushBack({ 41, 538, 63, 99 });
	animation = &leftlittledorsal;
	collider = App->collision->AddCollider({ 452, 124, 63, 50 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	dorsal_death = App->audio->LoadSoundEffect("Audio_Assets/dorsal_death.wav");
	points = 1000;
}

void EnemyLeftLittleDorsal::OnCollision(Collider* collider)
{
	App->ui->points += points;
	App->audio->PlaySoundEffect(dorsal_death);
}


bool EnemyLeftLittleDorsal::CleanUp()
{
	LOG("Freeing enemy audio");
	App->audio->UnloadSoundEffect(dorsal_death);
	dorsal_death = nullptr;

	return true;
}

void EnemyLeftLittleDorsal::Move()
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