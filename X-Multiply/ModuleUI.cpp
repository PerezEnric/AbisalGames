#include "ModuleUI.h"
#include "ModuleFonts.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include <stdio.h>

ModuleUI::ModuleUI() {}

ModuleUI::~ModuleUI() {}

bool ModuleUI::Start()
{
	LOG("Loading UI");

	u_interface = App->textures->Load("Sprites_Assets/UI_1.png");
	font_score = App->fonts->Load("Sprites_Assets/fonts.png", "0123456789ם.-=יט()ףעבת`´!?abcdefghijklmnopqrstuvwxyz", 2);

	
	return true;
}

bool ModuleUI::CleanUp()
{
	LOG("Unloading UI");

	App->textures->Unload(u_interface);
	

	return true;
}

update_status ModuleUI::Update()
{
	App->render->Blit(u_interface, 0, 220, NULL, false);

	score = App->ui->points;
	sprintf_s(text, 10, "%7d", score);

	App->fonts->BlitText(71, 235, font_score, text);
	App->fonts->BlitText(177, 235, font_score, top_score);
	App->fonts->BlitText(290, 235, font_score, second_score);


	return UPDATE_CONTINUE;
}