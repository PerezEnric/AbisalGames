#include "Application.h"
#include "Enemy_Tail.h"
#include "ModuleEnemies.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleBackground.h"


Enemy_Tail::Enemy_Tail(int x, int y) : Enemy(x, y)
{
	tail_fall.PushBack({ 426, 65, 219, 57 });
	animation = &tail_fall;
	collider = App->collision->AddCollider({ 0, 0, 219, 57 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	/*shrimp_death = App->audio->LoadSoundEffect("Audio_Assets/Ball_Death.wav");*/
}


void Enemy_Tail::OnCollision(Collider* collider)
{
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	App->player->points += points;
	App->background->taildown = true;
	//App->audio->PlaySoundEffect(shrimp_death);
}

bool Enemy_Tail::CleanUp()
{
	LOG("Freeing enemy audio");
	//App->audio->UnloadSoundEffect(shrimp_death);
	

	return true;
}