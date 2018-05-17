#ifndef __Enemy_Mask_H__
#define __Enemy_Mask_H__

#include "Enemy.h"

class Enemy_Mask : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation mask;
	int cd = 0;
	int points = 400;

public:

	Enemy_Mask(int x, int y);
	~Enemy_Mask() {};
	void Move();
	void OnCollision(Collider* collider);
	bool CleanUp();
	int enemy_life = 2;
};

#endif //  __Enemy_Mask_H__

