#ifndef __EnemyMiddleLittleDorsal_H__
#define __EnemyMiddleLittleDorsal_H__

#include "Enemy.h"

class EnemyMiddleLittleDorsal : public Enemy
{
private:

	Animation middlelittledorsal;
	int original_y;
public:

	EnemyMiddleLittleDorsal(int x, int y);
	~EnemyMiddleLittleDorsal() {};
	void OnCollision(Collider* collider);
	int cd = 0;
	int points = 600;
	bool CleanUp();
	int enemy_life = 3;
	bool alive = true;
};

#endif //  __EnemyMiddleLittleDorsal_H__