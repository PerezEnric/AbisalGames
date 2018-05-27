#ifndef __Enemy_Tail_H__
#define __Enemy_Tail_H__

#include "Enemy.h"

class Enemy_Tail : public Enemy
{
private:
	
	int points = 400;
	int cdtail = 0;
	
	
public:
	Animation tail_fall;
	SDL_Texture * monster_tail2 = nullptr;
	Enemy_Tail(int x, int y);
	~Enemy_Tail() {};
	void OnCollision(Collider* collider);
	bool CleanUp();
};

#endif //  __Enemy_Tail_H__