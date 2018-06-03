#ifndef __Enemy_PU3_H__
#define __Enemy_PU3_H__

#include "Enemy.h"

class Enemy_PU3 : public Enemy
{
private:
	float wave = -1.0f;
	
	int original_y = 0;
	Animation fly_robot;
	Animation landing_robot;
	Animation walking_robot;
	Animation walkingr_robot;
	Animation wake_up;
	Animation come_house;
	int cd = 0;
	int cd2 = 0;
	int cd3 = 0;
	int points = 400;
	bool action = false;
	bool flying = true;
	bool landing = false;
	bool walking = false;
	bool right = true;
	bool left = false;

public:

	Enemy_PU3(int x, int y);
	~Enemy_PU3() {};
	void Move();
	void OnCollision(Collider* collider);
	bool CleanUp();

};


#endif