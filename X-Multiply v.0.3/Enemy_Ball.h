#ifndef __Enemy_Ball_H__
#define __Enemy_Ball_H__

#include "Enemy.h"

class Enemy_Ball : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	bool right = false;
	int original_y = 0;
	Animation fly;
	

public:

	Enemy_Ball(int x, int y);
	~Enemy_Ball() {};
	void Move();
	int cd = 0;
};

#endif //  __Enemy_Ball_H__
