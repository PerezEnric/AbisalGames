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

	
	graphics = App->textures->Load("Sprites_Assets/TileMap1.png");
	graphicswall = App->textures->Load("Sprites_Assets/FirstLvlMap.png");
	graphicsinjection = App->textures->Load("Sprites_Assets/Injection.png");
	firstlvlmusic = App->audio->LoadMusic("Audio_Assets/Stage_1_Music.ogg");
	spaceshipdrop = App->audio->LoadSoundEffect("Audio_Assets/injection.wav");
	
	App->audio->PlayMusic(firstlvlmusic);
	App->audio->PlaySoundEffect(spaceshipdrop);
	App->audio->PlayMusic(firstlvlmusic);


	return ret;
}

// UnLoad assets
bool ModuleBackground::CleanUp()
{
	LOG("Unloading first level scene scene");

	App->textures->Unload(graphics);
	App->textures->Unload(graphicswall);
	App->player->Disable();
	App->audio->UnloadSoundEffect(spaceshipdrop);
	spaceshipdrop = nullptr;
	
	App->collision->Disable();

	return true;
}
// Update: draw background
update_status ModuleBackground::Update()
{
	animinject();
		// Draw everything --------------------------------------
	App->render->Blit(graphicswall, 0, 0, &wall, 0.75f);
	App->render->Blit(graphics, 0, 0, &background, 0.75f);
	App->render->Blit(graphicsinjection, xinject, yinject, &injection, 0.75f);


	if (App->intro->flag)
	{
		int vspeed = 1.5;
		if (App->render->camera.x <= -10600
			&& App->render->camera.x >= -13620)
		{
			App->render->camera.y -= vspeed;
			App->player->position.y -= vspeed;
		}
		
		if (move == false)
		{
			App->render->camera.x = 0;
		}
	}

	

	return UPDATE_CONTINUE;
}

//Dropping animation creation

void ModuleBackground::animinject()
{
	if (yinject >= -4 && inject)
	{
		if (injectionanim.GetCurrentFrameIndex() == 6)
		{
			App->player->Enable();
			move = true;
		}
		if (injectionanim.GetCurrentFrameIndex() == 11)
		{
			App->player->Enable();
			inject = false;
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