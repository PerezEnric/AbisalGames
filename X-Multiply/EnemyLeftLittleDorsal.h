#ifndef __EnemyLeftLittleDorsal_H__
#define __EnemyLeftLittleDorsal_H__

#include "Enemy.h"

class EnemyLeftLittleDorsal : public Enemy
{
private:

	Animation leftlittledorsal;
	int original_y;
public:

	EnemyLeftLittleDorsal(int x, int y);
	~EnemyLeftLittleDorsal() {};
	void OnCollision(Collider* collider);
	int cd = 0;
	int points = 600;
	bool CleanUp();
	int enemy_life = 3;
	bool alive = true;
};

#endif //  __EnemyLeftLittleDorsal_H__