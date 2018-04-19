#ifndef __Enemy_Anemone_H__
#define __Enemy_Anemone_H__

#include "Enemy.h"

class Enemy_Anemone : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation anem;

public:

	Enemy_Anemone(int x, int y);
	~Enemy_Anemone() {};

};

#endif //  __Enemy_Anemone_H__