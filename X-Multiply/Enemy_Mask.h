#ifndef __Enemy_Mask_H__
#define __Enemy_Mask_H__

#include "Enemy.h"

class Enemy_Mask : public Enemy
{
private:
	Animation mask;
	int cd = 0;
	int points = 400;

public:

	Enemy_Mask(int x, int y);
	~Enemy_Mask() {};
	void Move();
	void OnCollision(Collider* collider);
	bool CleanUp();

};

#endif //  __Enemy_Mask_H__