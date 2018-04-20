#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleIntroScene.h"
#include "ModuleEnemies.h"
#include "ModuleFadeToBlack.h"


ModuleBackground::ModuleBackground()
{
	// Background 
	background.x = 54;
	background.y = 492;
	background.w = 4961;
	background.h = 513;

	

	wall.x = 250;
	wall.y = 1000;
	wall.w = 4961;
	wall.h = 513;

}

bool ModuleBackground::Init()
{

	//Spaceship drop animation
	injectionanim.PushBack({ 28,24,48,102 });
	injectionanim.PushBack({ 107,24,48,105 });
	injectionanim.PushBack({ 188,24,48,103 });
	injectionanim.PushBack({ 266,24,48,113 });
	injectionanim.PushBack({ 335,24,48,121 });
	injectionanim.PushBack({ 414,24,48,123 });
	injectionanim.PushBack({ 414,24,48,122 });
	injectionanim.PushBack({ 335,24,48,120 });
	injectionanim.PushBack({ 266,24,48,112 });
	injectionanim.PushBack({ 188,24,48,103 });
	injectionanim.PushBack({ 107,24,48,105 });
	injectionanim.PushBack({ 28,24,48,102 });

	injectionanim.loop = false;
	injectionanim.speed = 0.2f;

	//Injection Measurements
	injection.x = 28;
	injection.y = 15;
	injection.w = 48;
	injection.h = 102;

	inject = true; 

	return true;

}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;

	App->player->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->enemies->Disable();
	App->textures->Disable();

	graphics = App->textures->Load("Sprites_Assets/TileMap1.png");
	graphicswall = App->textures->Load("Sprites_Assets/FirstLvlMap.png");
	graphicsinjection = App->textures->Load("Sprites_Assets/Injection.png");
	ui = App->textures->Load("Sprites_Assets/UI_1.png");
	firstlvlmusic = App->audio->LoadMusic("Audio_Assets/Stage_1_Music.ogg");
	spaceshipdrop = App->audio->LoadSoundEffect("Audio_Assets/injection.wav");
	App->player->destroyed = false;
	if (App->player->live < 3 && App->player->live > 0)
	{
		App->player->Enable();
		App->player->position.y = 103;
	}


	App->audio->PlayMusic(firstlvlmusic);
	App->audio->PlaySoundEffect(spaceshipdrop);
	App->collision->Enable();
	App->particles->Enable();
	App->enemies->Enable();
	App->textures->Enable();
	//Collider
	App->collision->AddCollider({ 0,213,2800,20 }, COLLIDER_WALL);
	App->collision->AddCollider({ 505, -3,2020,10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 410, 190,50,40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 510, 190,70,40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 640, -3,70,25 }, COLLIDER_WALL);
	App->collision->AddCollider({ 760, -3,47,40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1012, -3,96,40 }, COLLIDER_WALL);
	
	//Enemies
	App->enemies->AddEnemy(ENEMY_TYPES::BALL, 600, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::BALL2, 630, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::SHRIMP, 1000, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::ANEMONE, 520, 150);
	App->enemies->AddEnemy(ENEMY_TYPES::ANEMONE, 1050, 165);
	App->enemies->AddEnemy(ENEMY_TYPES::PU, 600, 100);

	//Power Ups
	App->enemies->AddEnemy(ENEMY_TYPES::SPEEDUP, 700, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMB, 800, 100);

	return ret;
}

// UnLoad assets
bool ModuleBackground::CleanUp()
{
	LOG("Unloading first level scene scene");

	App->textures->Unload(graphics);
	graphics = nullptr;
	App->textures->Unload(graphicswall);
	graphicswall = nullptr;
	App->textures->Unload(graphicsinjection);
	graphicsinjection = nullptr;
	App->textures->Unload(ui);
	ui = nullptr;
	
	App->player->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->enemies->Disable();
	App->textures->Disable();

	App->audio->UnloadMusic(firstlvlmusic);
	firstlvlmusic = nullptr;
	App->audio->UnloadSoundEffect(spaceshipdrop);
	spaceshipdrop = nullptr;

	return true;
}
// Update: draw background
update_status ModuleBackground::Update()
{
	animinject();
		// Draw everything --------------------------------------
	App->render->Blit(graphicswall, -10, 0, &wall, 1.0f);
	App->render->Blit(graphics, 0, 0, &background, 1.0f);
	App->render->Blit(graphicsinjection, xinject, yinject, &injection, 1.0f);
	App->render->Blit(ui, 0, 224, NULL, 0.0f, false);
	
	if (App->intro->flag)
	{
		int vspeed = 1;
		if (App->render->camera.x <= -8010
			&& App->render->camera.x >= -10370)
		{
			App->render->camera.y -= vspeed;
			//App->player->position.y += vspeed;
		}
		
		if (move == false)
		{
			App->render->camera.x = 0;
		}
	}
	
	if (App->player->live == 0 && App->player->destroyed == true)
	{
		App->fade->FadeToBlack((Module*)App->background, (Module*)App->win_lose);
		Disable();
	}
	else if(App->player->live > 0 && App->player->destroyed == true)
	{
		
		App->fade->FadeToBlack((Module*)App->background, (Module*)App->background);
	}
	

	return UPDATE_CONTINUE;
}

//Dropping animation creation

void ModuleBackground::animinject()
{
	if (yinject >= -4 && inject)
	{
		if (injectionanim.GetCurrentFrameIndex() == 3)
		{
			App->player->Enable();
			inject = false;
			move = true;
		}
		injection = injectionanim.GetCurrentFrame();
	}
	else
	{
		if (!inject)
		{

			if (injectionanim.Done())
			{
				yinject--;
			}
			else
			{
				injection = injectionanim.GetCurrentFrame();
			}
		}
		else
		{
			yinject++;
		}
	}
}