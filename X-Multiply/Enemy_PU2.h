#ifndef __Enemy_PU2_H__
#define __Enemy_PU2_H__

#include "Enemy.h"

class Enemy_PU2 : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation fly_PU;
	int points = 1000;

public:

	Enemy_PU2(int x, int y);
	~Enemy_PU2() {};
	void Move();
	void OnCollision(Collider* collider);
	bool CleanUp();
};

#endif // __Enemy_PU_H__


