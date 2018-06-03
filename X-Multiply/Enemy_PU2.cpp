#include "Application.h"
#include "Enemy_PU2.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"

Enemy_PU2::Enemy_PU2(int x, int y) : Enemy(x, y)
{
	fly_PU.PushBack({ 122, 66, 28, 19 });
	fly_PU.PushBack({ 154, 65, 31, 20 });
	fly_PU.speed = 0.1f;
	animation = &fly_PU;
	collider = App->collision->AddCollider({ 0, 0, 31, 20 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	original_y = y;
	powerup_death = App->audio->LoadSoundEffect("Audio_Assets/powerup_death.wav");
	App->enemies->lets = false;
	App->enemies->letb = false;
	App->enemies->lett = false;
}
void Enemy_PU2::Move()
{
	position.y = int(float(original_y));;
	position.x -= 1;

}

void Enemy_PU2::OnCollision(Collider* collider)
{
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);

	App->player->points += points;
	App->audio->PlaySoundEffect(powerup_death);

}

bool Enemy_PU2::CleanUp()
{
	LOG("Freeing enemy audio");
	App->audio->UnloadSoundEffect(powerup_death);
	powerup_death = nullptr;

	return true;
}