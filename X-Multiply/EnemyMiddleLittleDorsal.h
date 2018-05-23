#ifndef __EnemyMiddleLittleDorsal_H__
#define __EnemyMiddleLittleDorsal_H__

#include "Enemy.h"

class EnemyMiddleLittleDorsal : public Enemy
{
private:

	Animation middlelittledorsal;
	int points = 600;
public:

	EnemyMiddleLittleDorsal(int x, int y);
	~EnemyMiddleLittleDorsal() {};
	void OnCollision(Collider* collider);
	bool CleanUp();
};

#endif //  __EnemyMiddleLittleDorsal_H__