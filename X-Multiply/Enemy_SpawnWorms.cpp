#include "Application.h"
#include "Enemy_SpawnWorms.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"

Enemy_SpawnWorms::Enemy_SpawnWorms(int x, int y) : Enemy(x, y)
{
	spawn.PushBack({ 173, 313, 99, 45 });
	
	animation = &spawn;
	collider = App->collision->AddCollider({ 0, 0, 99, 45 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	/*shrimp_death = App->audio->LoadSoundEffect("Audio_Assets/Ball_Death.wav");*/
}
void Enemy_SpawnWorms::Move()
{
	if (cd == 110)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::GWORM, 993, 230);
		cd = 0;
	}
	cd++;

}

void Enemy_SpawnWorms::OnCollision(Collider* collider)
{
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	App->player->points += points;
	//App->audio->PlaySoundEffect(shrimp_death);
}

bool Enemy_SpawnWorms::CleanUp()
{
	LOG("Freeing enemy audio");
	//App->audio->UnloadSoundEffect(shrimp_death);
	shrimp_death = nullptr;

	return true;
}