#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
//#include "ModuleAudio.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;

	// Template for a new particle "explosion_shot"
	explosion_shot.anim.PushBack({ 760, 764, 7, 8 });
	explosion_shot.anim.PushBack({ 776, 762, 12, 12 });
	explosion_shot.anim.loop = false;
	explosion_shot.anim.speed = 0.2f;

	// Template for a new particle "laser"
	laser.anim.PushBack({ 791, 767, 16, 3 });
	laser.anim.loop = false;
	laser.anim.speed = 0.3f;
	laser.speed.x = 10;
	laser.life = 600;

	// Template for a new particle "explosion"
	explosion.anim.PushBack({ 727, 888, 24, 23 });
	explosion.anim.PushBack({ 730, 929, 26, 22 });
	explosion.anim.PushBack({ 762, 929, 26, 22 });
	explosion.anim.PushBack({ 793, 924, 44, 32 });
	explosion.anim.PushBack({ 844, 925, 37, 28 });
	explosion.anim.PushBack({ 889, 925, 42, 31 });
	explosion.anim.loop = false;
	explosion.anim.speed = 0.3f;

	// Template for a new particle "turbo"

	speedpowerup.anim.PushBack({ 866, 873, 18, 14 });
	speedpowerup.anim.PushBack({ 892, 873, 24, 13 });
	speedpowerup.anim.PushBack({ 921, 874, 42, 11 });
	speedpowerup.anim.PushBack({ 892, 873, 24, 13 });
	speedpowerup.anim.PushBack({ 921, 874, 42, 11 });
	speedpowerup.anim.PushBack({ 892, 873, 24, 13 });
	speedpowerup.anim.PushBack({ 921, 874, 42, 11 });
	speedpowerup.anim.loop = false;
	speedpowerup.anim.speed = 0.2f;

	//Enemy shot

	enemy_shot.anim.PushBack({ 774,894,8,8 });
	enemy_shot.anim.PushBack({ 791,909,8,8 });
	enemy_shot.anim.PushBack({ 774,909,8,8 });
	enemy_shot.anim.PushBack({ 791,894,8,8 });
	enemy_shot.anim.speed = 0.2f;
	enemy_shot.life = 3000;

	//Bomb Power Up
	bombPU.anim.PushBack({ 819, 905, 15, 4 });
	bombPU.anim.PushBack({ 844, 904, 14, 8 });
	bombPU.anim.PushBack({ 870, 900, 12, 12 });
	bombPU.anim.PushBack({ 884, 898, 9 ,14 });
	bombPU.anim.PushBack({ 912, 899, 4, 15 });
	bombPU.anim.loop = false;
	bombPU.anim.speed = 0.2f;
	bombPU.speed = { 2,3 };
	bombPU.life = 1500;

	//explosion player
	explosion_player.anim.PushBack({ 112,144,16,16 });
	explosion_player.anim.PushBack({ 96,144,16,16 });
	explosion_player.anim.PushBack({ 80,144,16,16 });
	explosion_player.anim.PushBack({ 64,144,16,16 });
	explosion_player.anim.PushBack({ 48,144,16,16 });
	explosion_player.anim.PushBack({ 32,144,16,16 });
	explosion_player.anim.PushBack({ 16,144,16,16 });
	explosion_player.anim.PushBack({ 0,144,16,16 });
	explosion_player.anim.loop = false;
	explosion_player.anim.speed = 0.5f;

	// leftdorsal shot
	leftdorsal_shot.anim.PushBack({ 501, 446, 46, 93 });
	leftdorsal_shot.anim.PushBack({ 437, 450, 46, 89 });
	leftdorsal_shot.anim.speed = 0.05f;
	leftdorsal_shot.life = 1000;

}

ModuleParticles::~ModuleParticles()
{
}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("Sprites_Assets/all_enemies.png");


	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}
	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if (p == nullptr)
			continue;

		if (p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if (SDL_GetTicks() >= p->born)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if (p->fx_played == false)
			{
				p->fx_played = true;
				// Play particle fx here

			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			if (collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			active[i] = p;
			break;
		}
	}
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if (active[i] != nullptr && active[i]->collider == c1)
		{
			delete active[i];
			active[i] = nullptr;
			break;
		}
	}
}


Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) :
	anim(p.anim), position(p.position), speed(p.speed),
	fx(p.fx), born(p.born), life(p.life)
{}

Particle::~Particle()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

bool Particle::Update()
{
	bool ret = true;

	if (life > 0)
	{
		if ((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if (anim.Finished())
			ret = false;

	position.x += speed.x;
	position.y += speed.y;

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);


	return ret;
}