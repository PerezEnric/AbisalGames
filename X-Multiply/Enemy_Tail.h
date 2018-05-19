#ifndef __Enemy_Tail_H__
#define __Enemy_Tail_H__

#include "Enemy.h"

class Enemy_Tail : public Enemy
{
private:
	float wave = -1.0f;
	
	Animation tail_fall;
	int points = 400;
	bool deadtail = false;
	int cdtail = 0;
	SDL_Texture* monster_tail2 = nullptr;
	SDL_Rect tail2;
	
public:

	Enemy_Tail(int x, int y);
	~Enemy_Tail() {};
	void Move();
	void OnCollision(Collider* collider);
	bool CleanUp();
};

#endif //  __Enemy_Tail_H__