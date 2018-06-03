#include "ModuleUI.h"
#include "ModuleFonts.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "ModuleSceneScore.h"
#include <stdio.h>

ModuleUI::ModuleUI() {}

ModuleUI::~ModuleUI() {}

bool ModuleUI::Start()
{
	LOG("Loading UI");

	u_interface = App->textures->Load("Sprites_Assets/UI_1.png");
	font_score = App->fonts->Load("Sprites_Assets/fonts.png", "0123456789ם.-=יט()ףעבת`´!?abcdefghijklmnopqrstuvwxyz", 2);
	pink_font = App->fonts->Load("Sprites_Assets/pinkfonts.png", "0123456789ם.-=יט()ףעבת`´!?abcdefghijklmnopqrstuvwxyz", 2);
	
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
	if (score > maxscore)
		maxscore = score;
	sprintf_s(text, 10, "%7d", score);
	App->fonts->BlitText(71, 235, font_score, text);

	sprintf_s(text2, 10, "%7d", maxscore);
	App->fonts->BlitText(177, 235, font_score, text2);
	/*App->fonts->BlitText(177, 235, font_score, top_score);*/
	App->fonts->BlitText(290, 235, font_score, second_score);

	if (App->scene_score->IsEnabled())
	{
		sprintf_s(text2, 10, "%6d", maxscore);
		App->fonts->BlitText(105, 101, pink_font, text2);
	}


	return UPDATE_CONTINUE;
}