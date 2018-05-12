#include "Application.h"
#include "Waves_PowerUp.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"


Waves_PowerUp::Waves_PowerUp(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 222, 100, 18, 15 });
	fly.speed = 0.1f;
	animation = &fly;
	collider = App->collision->AddCollider({ 0, 0, 24, 13 }, COLLIDER_TYPE::COLLIDER_POWER_UP, (Module*)App->enemies);
	original_y = y;
	//boost_sound = App->audio->LoadSoundEffect("Audio_Assets/power_up.wav");
}
void Waves_PowerUp::Move()
{
	position.y = int(float(original_y));
	if (App->enemies->lets == false)
	{
		position.x -= 1;
	}
	else
	{
		position.x -= 0;
	}
}

void Waves_PowerUp::OnCollision(Collider* collider)
{
	App->player->turbo = true;
	//App->audio->PlaySoundEffect(boost_sound);
}

bool  Waves_PowerUp::CleanUp()
{
	LOG("Unload power up audio");
	//App->audio->UnloadSoundEffect(boost_sound);
	boost_sound = nullptr;
	return true;
}