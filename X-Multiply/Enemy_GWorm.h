#ifndef __Enemy_GWorm_H__
#define __Enemy_GWorm_H__

#include "Enemy.h"

class Enemy_GWorm : public Enemy
{
private:
	Animation greenw;
	Animation greenw_shoot;
	int cd = 0;
	int cd2 = 0;
	int points = 100;
	int original_y;
	bool walk = true;
	bool stop = false;
	bool action = false;
	bool firstwalk = true;
public:

	Enemy_GWorm(int x, int y);
	~Enemy_GWorm() {};
	void Move();
	void OnCollision(Collider* collider);
	bool CleanUp();
};

#endif //  __Enemy_GWorm_H__


