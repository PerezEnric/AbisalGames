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
	App->render->Blit(ui, 0, 220, NULL, 0.0f, false);

	// camera move
	if (App->intro->flag)
	{
		int vspeed = 1;
		if (App->render->camera.x <= -8010
			&& App->render->camera.x >= -10358)
		{
			App->player->limity += 0.33;
			App->render->camera.y -= vspeed;
			//App->player->position.y += 0.33f;
		}

		if (move == false)
		{
			App->render->camera.x = 0;
		}
	}
	return UPDATE_CONTINUE;
}

//Dropping animation creation
