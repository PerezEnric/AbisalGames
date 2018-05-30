#ifndef __Enemy_PU_H__
#define __Enemy_PU_H__

#include "Enemy.h"

class Enemy_PU : public Enemy
{
private:
	float wave = -1.0f;
	bool flying = true;
	bool landing = false;
	bool walking = false;
	bool right = true;
	bool left = false;
	int original_y = 0;
	Animation fly_robot;
	Animation landing_robot;
	Animation walking_robot;
	int cd = 0;
	int cd2 = 0;
	int cd3 = 0;
	int points = 400;

public:

	Enemy_PU(int x, int y);
	~Enemy_PU() {};
	void Move();
	void OnCollision(Collider* collider);
	bool CleanUp();

};

#endif //  __Enemy_PU_H__

