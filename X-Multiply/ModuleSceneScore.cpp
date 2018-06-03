#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleBackground.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleIntroScene.h"
#include "ModuleFadeToBlack.h"
#include "ModuleWinLoseScene.h"
#include "ModuleSceneScore.h"
#include "ModuleEnemies.h"
#include "ModuleUI.h"
#include "ModuleFonts.h"

#include <stdio.h>


ModuleSceneScore::ModuleSceneScore()
{
	infinitsprite = {0,150,179,56};
}

ModuleSceneScore::~ModuleSceneScore(){}

bool ModuleSceneScore::Start()
{
	background_score = App->textures->Load("Sprites_Assets/highscore_scene.png");
	allscores = App->textures->Load("Sprites_Assets/all_scores.png");
	infinit = App->textures->Load("Sprites_Assets/UI_3.png");
	score_music = App->audio->LoadMusic("Audio_Assets/score_music.ogg");
	App->audio->PlayMusic(score_music);
	position.x = 0;
	position.y = 0;
	infinitepos = 120;

	App->enemies->Disable();
	App->ui->Disable();

	return true;
	
}

bool ModuleSceneScore::CleanUp()
{
	App->textures->Unload(background_score);
	background_score = nullptr;

	App->textures->Unload(infinit);
	infinit = nullptr;

	App->audio->UnloadMusic(score_music);
	score_music = nullptr;

	return true;
}

update_status ModuleSceneScore::Update()
{
	
	App->render->Blit(background_score, position.x, position.y, nullptr, false);
	App->render->Blit(allscores, 0, 0, nullptr , false);
	App->render->Blit(infinit, infinitepos, 10, &infinitsprite);

	infinitepos += 1;
	position.x -= 1;

	sprintf_s(App->ui->text2, 10, "%6d", App->ui->maxscore);
	App->fonts->BlitText(105, 101, App->ui->pink_font, App->ui->text2);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] || App->input->controller[BUTTON_START] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, App->intro, 2.0f);
	}


	return UPDATE_CONTINUE;
}