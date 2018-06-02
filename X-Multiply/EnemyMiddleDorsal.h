#ifndef __EnemyMiddleDorsal_H__
#define __EnemyMiddleDorsal_H__

#include "Enemy.h"

class EnemyMiddleDorsal : public Enemy
{
private:

	Animation middledorsal;
	int cd = 0;
	int cd2 = 0;
	int points = 600;
public:

	EnemyMiddleDorsal(int x, int y);
	~EnemyMiddleDorsal() {};
	void Move();
	void OnCollision(Collider* collider);
	bool CleanUp();
};

#endif //  __EnemyMiddleDorsal_H__