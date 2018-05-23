#ifndef __EnemyLeftLittleDorsal_H__
#define __EnemyLeftLittleDorsal_H__

#include "Enemy.h"

class EnemyLeftLittleDorsal : public Enemy
{
private:

	Animation leftlittledorsal;
	int points = 600;
public:

	EnemyLeftLittleDorsal(int x, int y);
	~EnemyLeftLittleDorsal() {};
	void OnCollision(Collider* collider);
	
	bool CleanUp();
};

#endif //  __EnemyLeftLittleDorsal_H__