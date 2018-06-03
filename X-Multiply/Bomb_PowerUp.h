#ifndef __Bomb_PowerUp_H__
#define __Bomb_PowerUp_H__
#include "Enemy.h"

class Bomb_PowerUp : public Enemy
{
private:
	Animation fly;
	int original_y = 0;
	int cd = 0;
	int cd2 = 0;
	int cd3 = 0;
	int points = 400;
	bool action = false;
	bool flying = true;
	bool landing = false;
	bool walking = false;
	bool right = true;
	bool left = false;

public:
	Bomb_PowerUp(int x, int y);
	~Bomb_PowerUp() {};
	void OnCollision(Collider* collider);
	void Move();
	bool CleanUp();
};

#endif
