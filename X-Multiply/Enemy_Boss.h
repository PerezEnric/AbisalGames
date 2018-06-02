#ifndef __Enemy_Boss_H__
#define __Enemy_Boss_H__

#include "Enemy.h"


class Enemy_Boss : public Enemy
{
public:

	Enemy_Boss(int x, int y);
	~Enemy_Boss() {};
	void Move();
	void OnCollision(Collider* collider);
	bool CleanUp();
	void MoveEye();

private:
	Animation boss, eye;
	Animation* eyeanim;
	int cd = 0;
	int shot_num, original_x, cd2;
	int points = 253000;
	bool going_up,going_front;

};
#endif