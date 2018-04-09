#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"
#include "ModuleAudio.h"

ModuleBackground::ModuleBackground()
{
	// Background 
	background.x = 72;
	background.y = 208;
	background.w = 768;
	background.h = 176;

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

	graphics = App->textures->Load("Map1.png");
	graphics2 = App->textures->Load("Map2.png");
	graphics3 = App->textures->Load("Map3.png");
	graphics4 = App->textures->Load("Map4.png");
	graphics5 = App->textures->Load("Map5.png");
	graphics6 = App->textures->Load("Map6.png");
	graphics7 = App->textures->Load("Map7.png");
	graphics8 = App->textures->Load("Map8.png");
	graphics9 = App->textures->Load("Map9.png");
	graphics10 = App->textures->Load("Map10.png");
	graphicswall = App->textures->Load("FirstLvlMap1.png");
	graphicswall2 = App->textures->Load("FirstLvlMap3.png");
	
	firstlvlmusic = App->audio->LoadMusic("Into_the_Human_Body_(Stage_1).ogg");
	App->audio->PlayMusic(firstlvlmusic);
	return ret;
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
	App->render->Blit(graphics, 0, 157, &background, 0.75f); 
	App->render->Blit(graphics2, 740, -126, &background2, 0.75f);
	App->render->Blit(graphics3, 1252, -144, &background2, 0.75f);
	App->render->Blit(graphics4, 1764,-144, &background2, 0.75f);
	App->render->Blit(graphics5, 2276, -144, &background2, 0.75f);
	App->render->Blit(graphics6, 2788, -95, &background2, 0.75f);
	//App->render->Blit(graphics7, 512, 0, &background2, 0.75f);
	//App->render->Blit(graphics8, 1252, -144, &background2, 0.75f);
	//App->render->Blit(graphics9, 1764, -144, &background2, 0.75f);
	//App->render->Blit(graphics10, 2276, -144, &background2, 0.75f);
	
	

	return UPDATE_CONTINUE;
}