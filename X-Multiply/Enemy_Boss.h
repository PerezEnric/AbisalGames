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
	bool wake_up, fight, going_front, going_up, shot;
	SDL_Rect eye_frontdown, eye_down, eye_backdown, eye_back, eye_backup, eye_up;
};
#endif