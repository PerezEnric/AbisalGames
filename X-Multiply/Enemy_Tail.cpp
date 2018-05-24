#include "Application.h"
#include "Enemy_Tail.h"
#include "ModuleEnemies.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"


Enemy_Tail::Enemy_Tail(int x, int y) : Enemy(x, y)
{
	tail_fall.PushBack({ 426, 65, 219, 57 });
	animation = &tail_fall;
	collider = App->collision->AddCollider({ 0, 0, 219, 57 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	// Sprite of enemy Monster Tail
	//tail2.x = 426;
	//tail2.y = 65;
	//tail2.w = 219;
	//tail2.h = 57;
	// Loading Monster's Tail
	/*monster_tail2 = App->textures->Load("Sprites_Assets/Enemies/all_enemies.png");*/
	/*shrimp_death = App->audio->LoadSoundEffect("Audio_Assets/Ball_Death.wav");*/
}
void Enemy_Tail::Move()
{
	//if (App->enemies->queue->enemy_life == 1 && deadtail == false)
	//{
	//	App->render->Blit(monster_tail2, 1022, 270, &tail2); // monster tail
	//	cdtail++;
	//	App->enemies->queue->enemy_life += 1;
	//	if (cdtail == 300)
	//	{
	//		deadtail = true;
	//	}
	//}
}

void Enemy_Tail::OnCollision(Collider* collider)
{
	/*App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	App->player->points += points;*/
	//App->audio->PlaySoundEffect(shrimp_death);
}

bool Enemy_Tail::CleanUp()
{
	LOG("Freeing enemy audio");
	//App->audio->UnloadSoundEffect(shrimp_death);
	

	return true;
}