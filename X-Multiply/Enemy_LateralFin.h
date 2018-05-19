#ifndef __Enemy_LateralFin_H__
#define __Enemy_LateralFin_H__

#include "Enemy.h"

class Enemy_LateralFin : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation latfin;
	int cd = 0;
	int points = 400;

public:

	Enemy_LateralFin(int x, int y);
	~Enemy_LateralFin() {};
	void Move();
	void OnCollision(Collider* collider);
	bool CleanUp();
	int enemy_life = 2;
};

#endif //  __Enemy_LateralFin_H__
