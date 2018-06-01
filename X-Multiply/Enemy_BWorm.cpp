#include "Application.h"
#include "Enemy_BWorm.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"

Enemy_BWorm::Enemy_BWorm(int x, int y) : Enemy(x, y)
{
	brown_down.PushBack({480,240,22,27});
	brown_rdown1.PushBack({437,196,22,28});
	brown_rdown2.PushBack({460,198,25,26});
	brown_rdown3.PushBack({487,201,29,21});
	brown_hor.PushBack({626,202,27,22});
	brown_up.PushBack({657,199,22,27});
	brown_rup1.PushBack({529,196,28,21});
	brown_rup2.PushBack({566,196,25,26});
	brown_rup3.PushBack({599,195,21,29});
	brown_dspawn.PushBack({ 448,347,23,6 });
	brown_dspawn.PushBack({ 483,347,25,7 });
	brown_dspawn.PushBack({ 521,347,31,11 });
	brown_dspawn.speed = 0.1;


	animation = &brown_down;
	collider = App->collision->AddCollider({ 0, 0, 22, 27 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	blue_death = App->audio->LoadSoundEffect("Audio_Assets/Ball_Death.wav");
}
void Enemy_BWorm::Move()
{
	if (dspawn == true)
	{
		position.y -= 0;
		position.x += 0;
		cd++;
		if (cd == 50)
		{
			dspawn = false;
			down = true;
			animation = &brown_down;
			cd = 0;
		}
	}

	if (down == true)
	{
		position.y += 1;
		position.x += 0;
		cd++;
		if(cd == 50)
		{
			down = false;
			downr = true;
			animation = &brown_rdown1;
			cd = 0;
		}
	}
	if(downr == true)
	{
		position.y += 1;
		position.x += 1;
		cd++;
		if (cd == 50)
		{
			downr = false;
			downr2 = true;
			animation = &brown_rdown2;
			cd = 0;
		}
	}

	if (downr2 == true)
	{
		position.y += 1;
		position.x += 1;
		cd++;
		if (cd == 50)
		{
			downr2 = false;
			downr3 = true;
			animation = &brown_rdown3;
			cd = 0;
		}
	}

	if (downr3 == true)
	{
		position.y += 1;
		position.x += 1;
		cd++;
		if (cd == 50)
		{
			downr3 = false;
			hor = true;
			animation = &brown_hor;
			cd = 0;
		}
	}

	if (hor == true)
	{
		position.y += 0;
		position.x += 1;
		cd++;
		if (cd == 50)
		{
			hor = false;
			upr = true;
			animation = &brown_rup1;
			cd = 0;
		}
	}

	if (upr == true)
	{
		position.y -= 1;
		position.x += 1;
		cd++;
		if (cd == 50)
		{
			upr = false;
			upr2 = true;
			animation = &brown_rup2;
			cd = 0;
		}
	}

	if (upr2 == true)
	{
		position.y -= 1;
		position.x += 1;
		cd++;
		if (cd == 50)
		{
			upr2 = false;
			upr3 = true;
			animation = &brown_rup3;
			cd = 0;
		}
	}

	if (upr3 == true)
	{
		position.y -= 1;
		position.x += 1;
		cd++;
		if (cd == 50)
		{
			upr3 = false;
			up = true;
			animation = &brown_up;
			cd = 0;
		}
	}
	if (up == true)
	{
		position.y -= 1;
		position.x += 0;
		cd++;
		if (cd == 50)
		{
			up = false;
			dspawn = true;
			animation = &brown_dspawn;
			cd = 0;
		}
	}

	

}

void Enemy_BWorm::OnCollision(Collider* collider)
{
	App->audio->PlaySoundEffect(blue_death);
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	App->player->points += points;
}

bool Enemy_BWorm::CleanUp()
{
	LOG("Freeing enemy audio");
	App->audio->UnloadSoundEffect(blue_death);
	blue_death = nullptr;

	return true;
}