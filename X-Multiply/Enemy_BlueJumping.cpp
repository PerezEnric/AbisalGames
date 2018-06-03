#include "Application.h"
#include "Enemy_Bluejumping.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"
#include "ModuleUI.h"

Enemy_BlueJumping::Enemy_BlueJumping(int x, int y) : Enemy(x, y)
{
	jumping.PushBack({ 715, 81, 29, 30 });
	jumping.PushBack({ 747, 81, 29, 30 });
	jumping.speed = 0.0f;
	animation = &jumping;
	collider = App->collision->AddCollider({ 0, 0, 29, 30 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	go_down = true;
	going_back = false;
	speed = 0;
	cd = 40;
	blue_death = App->audio->LoadSoundEffect("Audio_Assets/Ball_Death.wav");
	points = 1000;
}
void Enemy_BlueJumping::Move()
{
	
		if (go_down && position.y < 400)
		{
			position.y += speed;
			speed += 0.1;
		}
		if (App->background->moredown && position.y >= 220)
		{
			go_down = false;
			jumping.current_frame = 1;
			original_y = position.y;
			App->background->moredown = false;
		}

		else if (go_down && position.y >= 90 && !App->background->moredown)
		{
			go_down = false;
			jumping.current_frame = 1;
			original_y = position.y;
		}

		else if (go_down == false && position.y > 40)
		{
			position.y -= 2.5;
			going_back = true;
			original_y = position.y;
		}

		else if (going_back)
		{
			position.x -= 1;
			position.y = original_y;
			if (cd == 90)
			{
				App->particles->bluejumping_shot.speed = { -2 , 1 };
				App->particles->AddParticle(App->particles->bluejumping_shot, position.x - 30, position.y + 30, COLLIDER_ENEMY_SHOT);
				App->particles->bluejumping_shot.speed = { -2 , 0 };
				App->particles->AddParticle(App->particles->bluejumping_shot, position.x - 30, position.y + 30, COLLIDER_ENEMY_SHOT);
				App->particles->bluejumping_shot.speed = { -2 , -1 };
				App->particles->AddParticle(App->particles->bluejumping_shot, position.x - 30, position.y + 30, COLLIDER_ENEMY_SHOT);

				cd = 0;
			}
			cd++;
		}
}

void Enemy_BlueJumping::OnCollision(Collider* collider)
{
	App->audio->PlaySoundEffect(blue_death);
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	App->ui->points += points;
}

bool Enemy_BlueJumping::CleanUp()
{
	LOG("Freeing enemy audio");
	App->audio->UnloadSoundEffect(blue_death);
	blue_death = nullptr;

	return true;
}