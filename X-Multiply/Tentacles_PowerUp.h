#ifndef __Tentacles_PowerUp_H__
#define __Tentacles_PowerUp_H__
#include "Enemy.h"

class Tentacles_PowerUp : public Enemy
{
private:
	Animation tentacleanim;
	int original_y = 0;
	bool flying = true;
	bool landing = false;
	bool walking = false;
	bool right = true;
	bool left = false;
	int cd = 0;
	int cd2 = 0;
	int cd3 = 0;

public:
	Tentacles_PowerUp(int x, int y);
	~Tentacles_PowerUp() {};
	void OnCollision(Collider* collider);
	void Move();
	bool CleanUp();

};

#endif //__Tentacles_PowerUp_H__

