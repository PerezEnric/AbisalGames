#ifndef __PowerUp_SpeedUp_H__
#define __PowerUp_SpeedUp_H__
#include "Enemy.h"

class PowerUp_SpeedUp : public Enemy
{
private:
	int original_y = 0;
	Animation fly;
	int cd = 0;
	int cd2 = 0;
	int cd3 = 0;
	bool flying = true;
	bool landing = false;
	bool walking = false;
	bool right = true;
	bool left = false;

public:
	
	PowerUp_SpeedUp(int x, int y);
	~PowerUp_SpeedUp() {};
	void Move();
	void OnCollision(Collider* collider);
	bool CleanUp();

};

#endif //  __PowerUp_SpeedUp_H__
