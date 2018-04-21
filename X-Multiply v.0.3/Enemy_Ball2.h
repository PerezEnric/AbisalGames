#ifndef __Enemy_Ball2_H__
#define __Enemy_Ball2_H__

#include "Enemy.h"

class Enemy_Ball2 : public Enemy
{
private:
	float wave = -0.5f;
	bool going_up = true;
	int original_y = 0;
	bool right = false;
	int cd = 0;
	int points = 0;
	Animation fly;

public:
	Mix_Chunk* ball2_death = nullptr;
	Enemy_Ball2(int x, int y);
	~Enemy_Ball2() {};
	void Move();
	void OnCollision(Collider* collider);
};

#endif //  __Enemy_Ball2_H__