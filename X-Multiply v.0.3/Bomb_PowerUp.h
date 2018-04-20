#ifndef __Bomb_PowerUp_H__
#define __Bomb_PowerUp_H__
#include "Enemy.h"

class Bomb_PowerUp : public Enemy
{
private:
	Animation fly;
	int original_y = 0;

public:

	Bomb_PowerUp(int x, int y);
	~Bomb_PowerUp() {};
	void OnCollision(Collider* collider);

};

#endif
