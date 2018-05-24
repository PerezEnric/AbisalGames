#ifndef __EnemyRightLittleDorsal_H__
#define __EnemyRightLittleDorsal_H__

#include "Enemy.h"

class EnemyRightLittleDorsal : public Enemy
{
private:

	Animation rightlittledorsal;
	int cd = 0;
	int points = 600;
public:

	EnemyRightLittleDorsal(int x, int y);
	~EnemyRightLittleDorsal() {};
	void OnCollision(Collider* collider);
	bool CleanUp();
};

#endif //  __EnemyRightLittleDorsal_H__