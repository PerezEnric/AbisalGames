#include "Application.h"
#include "Enemy_BossShot.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"


Enemy_BossShot::Enemy_BossShot(int x, int y) : Enemy(x, y)
{
	//laser ball
	ball.PushBack({ 644,410,10,10 }); //balck
	ball.PushBack({ 644,453,10,10 }); //yellow
	ball.PushBack({ 644,410,10,10 }); //balck
	ball.PushBack({ 644,453,10,10 }); //yellow
	ball.PushBack({ 661,405,20,20 });
	ball.PushBack({ 662,450,16,16 });
	ball.PushBack({ 661,405,20,20 });
	ball.PushBack({ 662,450,16,16 });
	ball.PushBack({ 694,400,32,30 });
	ball.PushBack({ 694,443,32,30 });
	ball.PushBack({ 694,400,32,30 });
	ball.PushBack({ 694,443,32,30 });
	ball.speed = 0.6f;
	ball.loop = false;
	animation = &ball;
	collider = App->collision->AddCollider({ 0, 0, 32, 30 }, COLLIDER_TYPE::COLLIDER_SPECIAL_SHOT, (Module*)App->enemies);


	ball2.PushBack({ 644,410,10,10 }); //balck
	ball2.PushBack({ 644,453,10,10 }); //yellow
	ball2.PushBack({ 644,410,10,10 }); //balck
	ball2.PushBack({ 644,453,10,10 }); //yellow
	ball2.PushBack({ 661,405,20,20 });
	ball2.PushBack({ 662,450,16,16 });
	ball2.PushBack({ 661,405,20,20 });
	ball2.PushBack({ 662,450,16,16 });
	ball2.PushBack({ 694,400,32,30 });
	ball2.PushBack({ 694,443,32,30 });
	ball2.PushBack({ 694,400,32,30 });
	ball2.PushBack({ 694,443,32,30 });
	ball2.speed = 0.6f;
	ball2.loop = false;


	// horitzontal laser
	laser.PushBack({ 752,415,8,6 }); //yellow
	laser.PushBack({ 936 ,419,16,6 });//black
	laser.PushBack({ 862,415,24,6 });
	laser.PushBack({ 772,415,56,6 });
	laser.PushBack({ 792,499,56,6 });
	laser.PushBack({ 772,415,56,6 });
	laser.PushBack({ 862,415,24,6 });
	laser.PushBack({ 936 ,419,16,6 });
	laser.PushBack({ 752,415,8,6 });
	laser.speed = 0.2f;
	laser.loop = false;

	laser2.PushBack({ 752,415,8,6 }); //yellow
	laser2.PushBack({ 936 ,419,16,6 });//black
	laser2.PushBack({ 862,415,24,6 });
	laser2.PushBack({ 772,415,56,6 });
	laser2.PushBack({ 792,499,56,6 });
	laser2.PushBack({ 772,415,56,6 });
	laser2.PushBack({ 862,415,24,6 });
	laser2.PushBack({ 936 ,419,16,6 });
	laser2.PushBack({ 752,415,8,6 });
	laser2.speed = 0.2f;
	laser2.loop = false;

	//vertical laser
	laservertical.PushBack({ 670,537,6,8 }); //yellow
	laservertical.PushBack({ 727 ,529,6,16 });//black
	laservertical.PushBack({ 670,499,6,24 });
	laservertical.PushBack({ 709,491,6,56 });
	laservertical.PushBack({ 693,491,6,56 });
	laservertical.PushBack({ 709,491,6,56 });
	laservertical.PushBack({ 670,499,6,24 });
	laservertical.PushBack({ 727 ,529,6,16 });
	laservertical.PushBack({ 670,537,6,8 });
	laservertical.speed = 0.2f;
	laservertical.loop = false;

	laservertical2.PushBack({ 670,537,6,8 }); //yellow
	laservertical2.PushBack({ 727 ,529,6,16 });//black
	laservertical2.PushBack({ 670,499,6,24 });
	laservertical2.PushBack({ 709,491,6,56 });
	laservertical2.PushBack({ 693,491,6,56 });
	laservertical2.PushBack({ 709,491,6,56 });
	laservertical2.PushBack({ 670,499,6,24 });
	laservertical2.PushBack({ 727 ,529,6,16 });
	laservertical2.PushBack({ 670,537,6,8 });
	laservertical2.speed = 0.2f;
	laservertical2.loop = false;

	//positive diagonal
	laserpositive.PushBack({ 793,619,11,16 }); //yellow
	laserpositive.PushBack({ 709,579,17,32 });//black
	laserpositive.PushBack({ 718,643,20,40 });
	laserpositive.PushBack({ 748,564,23,48 });
	laserpositive.PushBack({ 751,639,23,48 });
	laserpositive.PushBack({ 748,564,23,48 });
	laserpositive.PushBack({ 718,643,20,40 });
	laserpositive.PushBack({ 709,579,17,32 });
	laserpositive.PushBack({ 793,619,11,16 });
	laserpositive.speed = 0.2f;
	laserpositive.loop = false;

	//negative diagonal
	lasernegative.PushBack({ 592,618,11,16 }); //yellow
	lasernegative.PushBack({ 670,578,17,32 });//black
	lasernegative.PushBack({ 658,542,20,40 });
	lasernegative.PushBack({ 625,563,23,48 });
	lasernegative.PushBack({ 622,638,23,48 });
	lasernegative.PushBack({ 625,563,23,48 });
	lasernegative.PushBack({ 658,542,20,40 });
	lasernegative.PushBack({ 670,578,17,32 });
	lasernegative.PushBack({ 592,618,11,16 });
	lasernegative.speed = 0.2f;
	lasernegative.loop = false;
}

bool Enemy_BossShot::CleanUp()
{
	blue_death = nullptr;
	return true;
}

void Enemy_BossShot::Move()
{
	if (ball.current_frame < 10)
	{
		posoriginal.x = position.x;
		posoriginal.y = position.y;
		posplayer.x = App->player->position.x;
		posplayer.y = App->player->position.y;
	}
	if (ball.current_frame >= 10 && posplayer.x < posoriginal.x
		&& posplayer.y > posoriginal.y - 30 && posplayer.y < posoriginal.y + 48.0f)
	{
		animation = &laser;
		position.x -= 3;
	}

	else if (ball.current_frame >= 10 && posplayer.y > posoriginal.y
		&& posplayer.x > posoriginal.x - 30 && posplayer.x < posoriginal.x + 30.0f)
	{
		animation = &laservertical;
		position.y += 3;
	}

	else if (ball.current_frame >= 8 && posplayer.x > posoriginal.x
		&& posplayer.y > posoriginal.y - 30 && posplayer.y < posoriginal.y + 48.0f)
	{
		animation = &laser;
		position.x += 3;
	}

	else if (ball.current_frame >= 10 && posplayer.y < posoriginal.y
		&& posplayer.x > posoriginal.x - 30 && posplayer.x < posoriginal.x + 30.0f)
	{
		animation = &laservertical;
		position.y -= 3;
	}

	else if (ball.current_frame >= 10
		&& posplayer.y > posoriginal.y && posplayer.x < posoriginal.x)
	{
		animation = &lasernegative;
		position.x += -2.0f;
		position.y += 3.0f;
	}

	else if (ball.current_frame >= 10
		&& posplayer.y < posoriginal.y && posplayer.x > posoriginal.x)
	{
		animation = &lasernegative;
		position.x += 2.0f;
		position.y += -3.0f;
	}

	else if (ball.current_frame >= 10
		&& posplayer.y < posoriginal.y && posplayer.x < posoriginal.x)
	{
		animation = &laserpositive;
		position.x += -2.0f;
		position.y += -3.0f;
	}

	else if (ball.current_frame >= 10
		&& posplayer.y > posoriginal.y && posplayer.x > posoriginal.x)
	{
		animation = &laserpositive;
		position.x += 2.0f;
		position.y += 3.0f;
	}

	if (laser.current_frame >= 8 || laservertical.current_frame >= 8 
		|| lasernegative.current_frame >= 8 || laserpositive.current_frame >= 8)
	{
		if (cd == 2)
		{

			App->enemies->shot = false;
			App->particles->trans.life = 30;
			App->particles->AddParticle(App->particles->trans, position.x + 10, position.y + 10, COLLIDER_ENEMY_SHOT);
			App->particles->trans.life = 1000;
			cd = 0;
		}

		ball.Reset();
		animation = &ball;
		laser.Reset();
		laservertical.Reset();
		laserpositive.Reset();
		lasernegative.Reset();
		cd++;
	}

	
}
void Enemy_BossShot::OnCollision(Collider* collider)
{
	App->enemies->shot = false;
}