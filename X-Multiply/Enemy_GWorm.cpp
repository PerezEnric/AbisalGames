#include "Application.h"
#include "Enemy_GWorm.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"

Enemy_GWorm::Enemy_GWorm(int x, int y) : Enemy(x, y)
{
	//Walking
	greenw.PushBack({ 272, 70, 30, 15 });
	greenw.PushBack({ 307, 69, 27, 16 });
	greenw.speed = 0.1f;
	//Shooting
	greenw_shoot.PushBack({ 348, 70, 26, 21 });
	greenw_shoot.PushBack({ 274, 99, 27, 16 });
	greenw_shoot.PushBack({ 319, 97, 33, 18 });
	greenw_shoot.speed = 0.1f;
	animation = &greenw;
	collider = App->collision->AddCollider({ 0, 0, 29, 30 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	blue_death = App->audio->LoadSoundEffect("Audio_Assets/Ball_Death.wav");
}
void Enemy_GWorm::Move()
{
	if (walk == true)
	{
		greenw.current_frame = 1;
		greenw.current_frame = 2;
		position.y = int(float(original_y) + 0);
		position.x -= 1.0f;
		cd++;
			if (cd == 100)
			{
				walk = false;
				animation = &greenw_shoot;
			}
	}
	else if (walk == false)
	{
		greenw.current_frame = 3;
		greenw.current_frame = 4;
		greenw.current_frame = 5;
		position.y = int(float(original_y) + 0);
		position.x += 0;

	}

	position.x -= 1.0f;
}

void Enemy_GWorm::OnCollision(Collider* collider)
{
	App->audio->PlaySoundEffect(blue_death);
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	App->player->points += points;
}

bool Enemy_GWorm::CleanUp()
{
	LOG("Freeing enemy audio");
	App->audio->UnloadSoundEffect(blue_death);
	blue_death = nullptr;

	return true;
}