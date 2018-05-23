#ifndef __EnemyLeftDorsal_H__
#define __EnemyLeftDorsal_H__

#include "Enemy.h"

class EnemyLeftDorsal : public Enemy
{
private:

	Animation leftdorsal;
	int cd = 0;
	int points = 600;
public:

	EnemyLeftDorsal(int x, int y);
	~EnemyLeftDorsal() {};
	void OnCollision(Collider* collider);
	void Move();
	bool CleanUp();
};

#endif //  __EnemyLeftDorsal_H__