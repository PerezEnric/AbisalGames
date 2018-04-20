#ifndef __Enemy_Ball2_H__
#define __Enemy_Ball2_H__

#include "Enemy.h"

class Enemy_Ball2 : public Enemy
{
private:
	float wave = -0.5f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;

public:

	Enemy_Ball2(int x, int y);
	~Enemy_Ball2() {};
	void Move();
};

#endif //  __Enemy_Ball2_H__