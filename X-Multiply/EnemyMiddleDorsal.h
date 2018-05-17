#ifndef __EnemyMiddleDorsal_H__
#define __EnemyMiddleDorsal_H__

#include "Enemy.h"

class EnemyMiddleDorsal : public Enemy
{
private:

	Animation middledorsal;
	int original_y;
public:

	EnemyMiddleDorsal(int x, int y);
	~EnemyMiddleDorsal() {};
	void OnCollision(Collider* collider);
	int cd = 0;
	int points = 600;
	bool CleanUp();
	int enemy_life = 3;
	bool alive = true;
};

#endif //  __EnemyMiddleDorsal_H__