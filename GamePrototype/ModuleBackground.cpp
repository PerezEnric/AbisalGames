#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"


ModuleBackground::ModuleBackground()
{
	// ground
	ground.x = 8;
	ground.y = 391;
	ground.w = 896;
	ground.h = 72;

	// Background 
	background.x = 72;
	background.y = 208;
	background.w = 768;
	background.h = 176;

	wall.x = 100;
	wall.y = 150;
	wall.w = 500;
	wall.h = 600;

	
}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;

	graphics2 = App->textures->Load("FirstLvlMap1.png");
	graphics = App->textures->Load("Map1.png");

	return ret;
}

// Update: draw background
update_status ModuleBackground::Update()
{
	// Draw everything --------------------------------------
	App->render->Blit(graphics2, 0, 0, &wall, 0.75f);
	App->render->Blit(graphics, 0, 155, &background, 0.75f); // sea and sky


	// TODO 2: Draw the ship from the sprite sheet with some parallax effect

	

	// TODO 3: Animate the girl on the ship (see the sprite sheet)


	
	App->render->Blit(graphics, 0, 170, &ground);

	return UPDATE_CONTINUE;
}