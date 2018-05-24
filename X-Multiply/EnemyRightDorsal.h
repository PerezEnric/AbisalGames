#ifndef __EnemyRightDorsal_H__
#define __EnemyRightDorsal_H__

#include "Enemy.h"

class EnemyRightDorsal : public Enemy
{
private:

	Animation rightdorsal;
	int cd = 0;
	int points = 600;
public:

	EnemyRightDorsal(int x, int y);
	~EnemyRightDorsal() {};
	void Move();
	void OnCollision(Collider* collider);
	bool CleanUp();
};

#endif //  __EnemyRightDorsal_H__