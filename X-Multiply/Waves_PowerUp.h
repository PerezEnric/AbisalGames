#ifndef __Waves_PowerUp_H__
#define __Waves_PowerUp_H__
#include "Enemy.h"

class Waves_PowerUp : public Enemy
{
private:
	int original_y = 0;
	Animation fly;
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

	Waves_PowerUp(int x, int y);
	~Waves_PowerUp() {};
	void Move();
	void OnCollision(Collider* collider);
	bool CleanUp();

};

#endif //  __Waves_PowerUp_H__
