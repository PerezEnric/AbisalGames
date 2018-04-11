#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"

ModuleBackground::ModuleBackground()
{
	// Background 
	background.x = 54;
	background.y = 491;
	background.w = 4961;
	background.h = 513;

	

	wall.x = 100;
	wall.y = 150;
	wall.w = 500;
	wall.h = 600;

	background2.x = 0;
	background2.y = 0;
	background2.w = 512;
	background2.h = 512;

	
	
}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;

	
	graphics = App->textures->Load("TileMap1.png");
	graphicswall = App->textures->Load("FirstLvlMap1.png");
	graphicswall2 = App->textures->Load("FirstLvlMap3.png");
	//firstlvlmusic = App->audio->LoadMusic("Stage_1_Music.ogg");
	App->audio->PlayMusic(firstlvlmusic);
	App->player->Enable();
	return ret;
}

// UnLoad assets
bool ModuleBackground::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(graphics);
	App->player->Disable();

	return true;
}
// Update: draw background
update_status ModuleBackground::Update()
{
	

	// Draw everything --------------------------------------
	App->render->Blit(graphicswall, 0, 0, &wall, 0.75f);
	App->render->Blit(graphicswall, 500, 0, &wall, 0.75f);
	App->render->Blit(graphicswall, 1000, 0, &wall, 0.75f);
	App->render->Blit(graphicswall, 1500, 0, &wall, 0.75f);
	App->render->Blit(graphicswall2, 2000, 0, &wall, 0.75f);
	App->render->Blit(graphics, 0, 0, &background, 0.75f); 

	
	//App->render->Blit(graphics7, 512, 0, &background2, 0.75f);
	//App->render->Blit(graphics8, 1252, -144, &background2, 0.75f);
	//App->render->Blit(graphics9, 1764, -144, &background2, 0.75f);
	//App->render->Blit(graphics10, 2276, -144, &background2, 0.75f);
	
	

	return UPDATE_CONTINUE;
}