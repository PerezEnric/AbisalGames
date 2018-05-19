#include "Application.h"
#include "Enemy_LateralFin.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"

Enemy_LateralFin::Enemy_LateralFin(int x, int y) : Enemy(x, y)
{
	latfin.PushBack({ 41, 197, 75, 76 });
	latfin.PushBack({ 134, 195, 66, 78 });
	latfin.PushBack({ 218, 196, 35, 76 });
	latfin.PushBack({ 50, 294, 67, 76 });
	latfin.speed = 0.1f;
	animation = &latfin;
	collider = App->collision->AddCollider({ 0, 0, 75, 76 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	original_y = y;
	/*shrimp_death = App->audio->LoadSoundEffect("Audio_Assets/Ball_Death.wav");*/
}
void Enemy_LateralFin::Move()
{
	
}

void Enemy_LateralFin::OnCollision(Collider* collider)
{
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	App->player->points += points;
	//App->audio->PlaySoundEffect(shrimp_death);
}

bool Enemy_LateralFin::CleanUp()
{
	LOG("Freeing enemy audio");
	//App->audio->UnloadSoundEffect(shrimp_death);
	shrimp_death = nullptr;

	return true;
}