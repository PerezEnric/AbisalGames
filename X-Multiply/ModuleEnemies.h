#pragma once
#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"
#include "EnemyLeftDorsal.h"
#include "Enemy_LateralFin.h"
#include "EnemyLeftLittleDorsal.h"
#include "EnemyMiddleDorsal.h"
#include "EnemyMiddleLittleDorsal.h"
#include "Enemy_LittleShrimp.h"
#include "EnemyRightDorsal.h"
#include "EnemyRightLittleDorsal.h"
#include "Enemy_SpawnWorms.h"
#include "Enemy_Tail.h"
#include "Enemy_Mask.h"
#include "Enemy_PU.h"
#include "Enemy_BlueJumping.h"
#include "Enemy_Boss.h"
#include "Enemy_BossShot.h"
#include "Enemy_GWorm.h"
#include "Enemy_BWorm.h"
#include "PowerUp_SpeedUp.h"
#include "Bomb_PowerUp.h"
#include "Waves_PowerUp.h"
#include "Tentacles_PowerUp.h"
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )

#define MAX_ENEMIES 100

enum ENEMY_TYPES
{
	NO_TYPE,
	LEFTDORSAL,
	LEFTLITTLEDORSAL,
	MIDDLEDORSAL,
	MIDDLELITTLEDORSAL,
	SHRIMP,
	MASK,
	SPAWN,
	RIGHTDORSAL,
	RIGHTLITTLEDORSAL,
	TAIL,
	GWORM,
	BWORM,
	LATERALFIN,
	BLUE_JUMPING,
	BOSS,
	BOSS_SHOT,
	PU,
	SPEEDUP,
	BOMB,
	TENTACLES,
	WAVES,
};

class Enemy;

struct EnemyInfo
{
	ENEMY_TYPES type = ENEMY_TYPES::NO_TYPE;
	int x, y;
	float  enemy_life;

};

class ModuleEnemies : public Module
{
public:

	ModuleEnemies();
	~ModuleEnemies();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);
	bool AddEnemy(ENEMY_TYPES type, int x, int y);
	uint points = 0;
	bool lets;
	bool letb;
	bool lett;
	bool shot;
	EnemyInfo queue[MAX_ENEMIES];
	Enemy* enemies[MAX_ENEMIES];
	ENEMY_TYPES type = ENEMY_TYPES::NO_TYPE;

private:

	void SpawnEnemy(const EnemyInfo& info);

public:

	SDL_Texture * sprites;
};

#endif // __ModuleEnemies_H__
