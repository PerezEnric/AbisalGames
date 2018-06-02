#ifndef __Enemy_BlueJumping_H__
#define __Enemy_BlueJumping_H__

#include "Enemy.h"

class Enemy_BlueJumping : public Enemy
{
private:
	Animation jumping;
	int cd = 0;
	int points = 0;
	bool going_back,go_down;
	bool action = false;
	float wave;
	int original_y;
	float speed;
public:

	Enemy_BlueJumping(int x, int y);
	~Enemy_BlueJumping() {};
	void Move();
	void OnCollision(Collider* collider);
	bool CleanUp();
};

#endif //  __Enemy_LateralFin_H__

