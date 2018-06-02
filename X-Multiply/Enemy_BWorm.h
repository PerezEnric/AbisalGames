#ifndef __Enemy_BWorm_H__
#define __Enemy_BWorm_H__

#include "Enemy.h"

class Enemy_BWorm : public Enemy
{
private:
	Animation brown_down;
	Animation brown_rdown1;
	Animation brown_rdown2;
	Animation brown_rdown3;
	Animation brown_hor;
	Animation brown_up;
	Animation brown_rup1;
	Animation brown_rup2;
	Animation brown_rup3;
	Animation brown_dspawn;

	int cd = 0;
	int cd2 = 0;
	int points = 100;
	int original_y;
	bool down = false;
	bool downr = false;
	bool downr2 = false;
	bool downr3 = false;
	bool hor = false;
	bool upr = false;
	bool upr2 = false;
	bool upr3 = false;
	bool up = false;
	bool dspawn = true;
	bool action = false;
public:

	Enemy_BWorm(int x, int y);
	~Enemy_BWorm() {};
	void Move();
	void OnCollision(Collider* collider);
	bool CleanUp();
};

#endif //  __Enemy_BWorm_H__



