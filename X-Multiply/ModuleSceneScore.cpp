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

ModuleSceneScore::ModuleSceneScore()
{

}

ModuleSceneScore::~ModuleSceneScore(){}

bool ModuleSceneScore::Start()
{
	background_score = App->textures->Load("Sprites_Assets/highscore_scene.png");
	allscores = App->textures->Load("Sprites_Assets/all_scores.png");

	score_music = App->audio->LoadMusic("Audio_Assets/score_music.ogg");
	App->audio->PlayMusic(score_music);

	return true;
}

bool ModuleSceneScore::CleanUp()
{
	App->textures->Unload(background_score);
	background_score = nullptr;

	App->audio->UnloadMusic(score_music);
	score_music = nullptr;

	return true;
}

update_status ModuleSceneScore::Update()
{
	App->render->Blit(background_score, 0, 0, NULL, false);
	App->render->Blit(allscores, 0, 0, NULL, false);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] || App->input->controller[BUTTON_START] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, App->intro, 2.0f);
	}

	return UPDATE_CONTINUE;
}