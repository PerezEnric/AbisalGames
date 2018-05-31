#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "ModuleCollision.h"
#include "p2Point.h"


#define MAX_ACTIVE_PARTICLES 500


struct SDL_Texture;
struct Collider;
enum COLLIDER_TYPE;

struct Particle
{
	Collider* collider = nullptr;
	Animation anim;
	uint fx = 0;
	iPoint position;
	iPoint speed;
	Uint32 born = 0;
	Uint32 life = 0;
	bool fx_played = false;

	Particle();
	Particle(const Particle& p);
	~Particle();
	bool Update();
};

class ModuleParticles : public Module
{
public:
	ModuleParticles();
	~ModuleParticles();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	void AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type = COLLIDER_NONE, Uint32 delay = 0);

private:

	SDL_Texture* graphics = nullptr;
	Particle* active[MAX_ACTIVE_PARTICLES];
	uint last_particle = 0;

public:

	Particle laser;
	Particle explosion_shot;
	Particle explosion;
	Particle speedpowerup;
	Particle enemy_shot;
	Particle bombPU;
	Particle explosion_player;
	Particle leftdorsal_shot;
	Particle middleleft_shot;
	Particle middleright_shot;
	Particle rightdorsal_shot;
	Particle bluejumping_shot;
	Particle waves_shot;
	Particle missile_shot;
};

#endif // __MODULEPARTICLES_H__
