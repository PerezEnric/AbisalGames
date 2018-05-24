#ifndef __Enemy_SpawnWorms_H__
#define __Enemy_SpawnWorms_H__

#include "Enemy.h"

class Enemy_SpawnWorms : public Enemy
{
private:
	Animation spawn;
	int points = 400;

public:

	Enemy_SpawnWorms(int x, int y);
	~Enemy_SpawnWorms() {};
	void Move();
	void OnCollision(Collider* collider);
	bool CleanUp();
};

#endif //  __Enemy_LateralFin_H__

