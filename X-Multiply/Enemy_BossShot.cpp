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
	laserpositive.PushBack({ 938,525,9,7 }); //yellow
	laserpositive.PushBack({ 902 ,513,17,6 });//black
	laserpositive.PushBack({ 720,599,31,17 });
	laserpositive.PushBack({ 809,448,49,23 });
	laserpositive.PushBack({ 716,563,51,26 });
	laserpositive.PushBack({ 809,448,49,23 });
	laserpositive.PushBack({ 720,599,31,17 });
	laserpositive.PushBack({ 902 ,513,17,6 });
	laserpositive.PushBack({ 938,525,9,7 });
	laserpositive.speed = 0.2f;
	laserpositive.loop = false;

	//negative diagonal
	lasernegative.PushBack({ 646,633,8,12 }); //yellow
	lasernegative.PushBack({ 670,578,17,32 });//black
	lasernegative.PushBack({ 606,576,20,40 });
	lasernegative.PushBack({ 614,500,23,48 });
	lasernegative.PushBack({ 568,570,23,48 });
	lasernegative.PushBack({ 614,500,23,48 });
	lasernegative.PushBack({ 606,576,20,40 });
	lasernegative.PushBack({ 670,578,17,32 });
	lasernegative.PushBack({ 646,633,8,12 });
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
	if (ball.current_frame >= 10)
	{
		animation = &laser;
		position.x -= 3;
	}
	if (laser.current_frame >= 8)
	{
		ball.current_frame = 0;
		animation = &ball2;
	}
	if (cd == 100)
	{

		App->enemies->shot = false;
		App->particles->AddParticle(App->particles->laser, position.x + 10, position.y + 10, COLLIDER_ENEMY_SHOT);
	}
	cd++;
}
void Enemy_BossShot::OnCollision(Collider* collider)
{
	App->enemies->shot = false;
}