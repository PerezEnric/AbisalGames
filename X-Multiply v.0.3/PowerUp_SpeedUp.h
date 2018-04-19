#ifndef __PowerUp_SpeedUp_H__
#define __PowerUp_SpeedUp_H__
#include "PowerUp.h"

class PowerUp_SpeedUp : public PowerUp
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;
	

public:

	PowerUp_SpeedUp(int x, int y);
	~PowerUp_SpeedUp() {};
	void Move();
	void OnCollision(Collider* collider);
	
};

#endif //  __PowerUp_SpeedUp_H__
