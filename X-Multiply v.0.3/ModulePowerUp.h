#ifndef __ModulePowerUp_H__
#define __ModulePowerUp_H__

#include "Module.h"
#include "PowerUp.h"
#include "PowerUp_SpeedUp.h"
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )

#define MAX_POWERUPS 100
enum POWERUP_TYPES
{
	NO_TYP,
	SPEEDUP,
	
};

class PowerUp;

struct PowerUpInfo
{
	POWERUP_TYPES type = POWERUP_TYPES::NO_TYP;
	int x, y;
};

class ModulePowerUp : public Module
{
public:

	ModulePowerUp();
	~ModulePowerUp();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	bool AddPowerUp(POWERUP_TYPES type, int x, int y);

private:

	void SpawnPowerUp(const PowerUpInfo& info);

private:

	PowerUpInfo queue[MAX_POWERUPS];
	PowerUp* powerup[MAX_POWERUPS];
	SDL_Texture* sprites;
};

#endif // __ModulePowerUp_H__
