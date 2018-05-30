#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "p2Point.h"
#include "Animation.h"
#include "ModuleAudio.h"

struct SDL_Texture;
struct Collider;

class Enemy
{
protected:
	Animation * animation = nullptr;
	Collider* collider = nullptr;

public:
	iPoint position;

public:
	Enemy(int x, int y);
	virtual ~Enemy();

	const Collider* GetCollider() const;

	Mix_Chunk* powerup_death = nullptr;
	Mix_Chunk* shrimp_death = nullptr;
	Mix_Chunk* blue_death = nullptr;
	Mix_Chunk* leftdorsal_death = nullptr;
	Mix_Chunk * boost_sound = nullptr;
	Mix_Chunk * new_weapon = nullptr;
	Mix_Chunk * robot_death = nullptr;
	Mix_Chunk * tumour_death = nullptr;
	Mix_Chunk * tail_death = nullptr;
	Mix_Chunk * dorsal_death = nullptr;
	virtual void Move() {};
	virtual void Draw(SDL_Texture* sprites);
	virtual void OnCollision(Collider* collider) = 0;
};

#endif // __ENEMY_H__
