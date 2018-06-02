#include "Application.h"
#include "Enemy_BossShot.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"

Enemy_BossShot::Enemy_BossShot(int x, int y) : Enemy(x, y)
{
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