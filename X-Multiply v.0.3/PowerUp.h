#ifndef __PowerUp_H__
#define __PowerUp_H__

#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider;

class PowerUp
{
protected:
	Animation* animation = nullptr;
	Collider* collider = nullptr;

public:
	iPoint position;

public:
	PowerUp(int x, int y);
	virtual ~PowerUp();

	const Collider* GetCollider() const;

	virtual void Move() {};
	virtual void Draw(SDL_Texture* sprites);
	virtual void OnCollision(Collider* collider) = 0;
};

#endif // __PowerUp_H__