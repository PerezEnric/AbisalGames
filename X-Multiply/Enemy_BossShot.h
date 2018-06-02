#ifndef __Enemy_BossShot_H__
#define __Enemy_BossShot_H__

#include "Enemy.h"


class Enemy_BossShot : public Enemy
{
public:

	Enemy_BossShot(int x, int y);
	~Enemy_BossShot() {};
	void Move();
	void OnCollision(Collider* collider);
	bool CleanUp();

private:
	Animation ball, ball2;
	Animation laser,laser2;
	Animation laservertical, laservertical2;
	Animation laserpositive, laserpositive2;
	Animation lasernegative, lasernegative2;
	int cd = 0;
	int points = 0;
	Collider* col;
};
#endif