#ifndef __Enemy_GWorm_H__
#define __Enemy_GWorm_H__

#include "Enemy.h"

class Enemy_GWorm : public Enemy
{
private:
	Animation greenw;
	int cd = 0;
	int points = 100;
	int original_y;
	bool walk;
public:

	Enemy_GWorm(int x, int y);
	~Enemy_GWorm() {};
	void Move();
	void OnCollision(Collider* collider);
	bool CleanUp();
};

#endif //  __Enemy_GWorm_H__


