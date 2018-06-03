#include "Application.h"
#include "Enemy_Mask.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleUI.h"

Enemy_Mask::Enemy_Mask(int x, int y) : Enemy(x, y)
{
	mask.PushBack({ 310, 195, 86, 69 });
	animation = &mask;

	collider = App->collision->AddCollider({ 0, 0, 86, 69 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	tumour_death = App->audio->LoadSoundEffect("Audio_Assets/tumour_death.wav");
	points = 1000;
}

void Enemy_Mask::OnCollision(Collider* collider)
{
	App->audio->PlaySoundEffect(tumour_death);
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	App->ui->points += points;
}

void Enemy_Mask::Move()
{
	if (cd == 1000 && firsttime)
	{
		App->particles->AddParticle(App->particles->enemy_shot, position.x - 5, position.y + 20, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { -1, 0 };
		App->particles->AddParticle(App->particles->enemy_shot, position.x - 5, position.y + 10, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { -1, -1 };
		App->particles->AddParticle(App->particles->enemy_shot, position.x - 5, position.y + 30, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { -1, 1 };
		App->particles->AddParticle(App->particles->enemy_shot, position.x - 5, position.y + 0, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { -1, -2 };
		App->particles->AddParticle(App->particles->enemy_shot, position.x - 5, position.y + 40, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { -1, 2 };
		firsttime = false;
		cd = 0;
		cd2 = 0;
	}
	if (cd == 500 && !firsttime)
	{
		App->particles->AddParticle(App->particles->enemy_shot, position.x - 5, position.y + 20, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { -1, 0 };
		App->particles->AddParticle(App->particles->enemy_shot, position.x - 5, position.y + 10, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { -1, -1 };
		App->particles->AddParticle(App->particles->enemy_shot, position.x - 5, position.y + 30, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { -1, 1 };
		App->particles->AddParticle(App->particles->enemy_shot, position.x - 5, position.y + 0, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { -1, -2 };
		App->particles->AddParticle(App->particles->enemy_shot, position.x - 5, position.y + 40, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { -1, 2 };
		cd = 0;

	}

	if (cd2 == 520 && !firsttime)
	{
		App->particles->AddParticle(App->particles->enemy_shot, position.x - 5, position.y + 20, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { -1, 0 };
		App->particles->AddParticle(App->particles->enemy_shot, position.x - 5, position.y + 10, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { -1, -1 };
		App->particles->AddParticle(App->particles->enemy_shot, position.x - 5, position.y + 30, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { -1, 1 };
		App->particles->AddParticle(App->particles->enemy_shot, position.x - 5, position.y + 0, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { -1, -2 };
		App->particles->AddParticle(App->particles->enemy_shot, position.x - 5, position.y + 40, COLLIDER_ENEMY_SHOT);
		App->particles->enemy_shot.speed = { -1, 2 };
		cd2 = 0;
	}
	cd++;
	cd2++;

}

bool Enemy_Mask::CleanUp()
{
	LOG("Freeing enemy audio");
	App->audio->UnloadSoundEffect(tumour_death);
	tumour_death = nullptr;

	return true;
}