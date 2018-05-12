#ifndef __EnemyLeftDorsal_H__
#define __EnemyLeftDorsal_H__

#include "Enemy.h"

class EnemyLeftDorsal : public Enemy
{
private:

	Animation leftdorsal;
	int original_y;
public:

	EnemyLeftDorsal(int x, int y);
	~EnemyLeftDorsal() {};
	void Enemy_Death();
	void OnCollision(Collider* collider);
	int cd = 0;
	int points = 600;
	//bool CleanUp();
	int enemy_life = 3;
	bool alive = true;
};

#endif //  __EnemyLeftDorsal_H__