#ifndef __Waves_PowerUp_H__
#define __Waves_PowerUp_H__
#include "Enemy.h"

class Waves_PowerUp : public Enemy
{
private:
	int original_y = 0;
	Animation fly;
public:

	Waves_PowerUp(int x, int y);
	~Waves_PowerUp() {};
	void Move();
	void OnCollision(Collider* collider);
	bool CleanUp();

};

#endif //  __Waves_PowerUp_H__
